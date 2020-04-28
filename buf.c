// 
// Problema del búfer limitado modificado.
// 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include <semaphore.h>

// Mueve el cursor a la linea x, columna y (ver codigos ANSI).
#define xy(x, y) printf("\033[%d;%dH", x, y)

// Borra desde el cursor hasta el fin de la linea.
#define clear_eol(x) print(x, 10, "\033[K")

// Borra la pantalla.
#define clear() printf("\033[H\033[J")

// Mutex para sincronizar el acceso a la pantalla
static pthread_mutex_t screen = PTHREAD_MUTEX_INITIALIZER;

static void* writer(void*);
static void* reader(void*);
static void setup_draw(void);
static void draw(int, int, int);

int counter;
int bufsize;
int *buffer;

int out = 0; // Indice del consumidor.
int in = 0;  // indice del productor.

// Mutex para utilizar en la sincronización.
pthread_mutex_t mutex;

// Puntero a un buffer donde se almacena que leyo el consumidor.
int *reader_results;

/* Productor */
static void* writer(void *p) 
{
    int item = 0;  // item a producir
    int num = 0;   // cantidad de items producidos
    
    while (num < counter) {
        // Agrega un item al buffer
        buffer[in] = item;
        draw(6, in, item);

        // Valor del proximo item
        item = item + 1;
        // Indice del buffer para el proximo item
        in = (in + 1) % bufsize; 

        num++;

        sleep(rand() % 3);
    }
    
    pthread_exit(0);
}

/* Consumidor */
static void* reader(void *p) 
{
    int num = 0;
    
    while (num < counter) {
        // Lee un item del buffer
        int item = buffer[out];
        draw(7, out, item);

        reader_results[num] = item;

        // Indice del próximo elemento
        out = (out + 1) % bufsize;
        num++;

        sleep(rand() % 3);
    }
    
    pthread_exit(0);
}

/* Datos iniciales en la pantalla. */
static void setup_draw(void)
{
    int i;
    xy(4,1), printf("Buffer:");
    xy(6,1), printf("Prod:");
    xy(7,1), printf("Cons:");

    xy(4,10);
    for(i = 0; i < bufsize; i++) {
        xy(4,10+(i*4)), printf("-");
    }

    xy(6,10), printf("^");
    xy(7,10), printf("^");

    xy(9,1), fflush(stdout);
}

/* Dibuja el símbolo ^ y el valor producido si es el productor. */
static void draw(int w, int i, int v)
{
    pthread_mutex_lock(&screen);

    xy(w, 10), printf("\033[K");
    xy(w, 10+(i*4));
    printf("^");
    if (w==6) {
        xy(4,10+(i*4));
        printf("%d",v);
    }
    xy(6,1), fflush(stdout);
    
    pthread_mutex_unlock(&screen);
}

int main(int argc, char** argv) 
{
    int i;
    pthread_t writer_t;
    pthread_t reader_t;

    if (argc != 3) {
        fprintf(stderr, "Uso: %s bufsize items\n", argv[0]);
        fprintf(stderr, "\tbufsize:\ttamaño del búfer.\n");
        fprintf(stderr, "\titems:\tnúmero de items a producir/consumir.\n");
        exit(EXIT_FAILURE);
    }

    // Borra la pantalla
    clear();

    // Tamaño del buffer.
    bufsize = atoi(argv[1]);    
    if (bufsize <= 0) {
        fprintf(stderr, "bufsize tiene que ser mayor que cero.\n");
        exit(EXIT_FAILURE);
    }

    // Reserva memoria para el buffer.
    buffer = (int*) malloc(sizeof(int) * bufsize);
    if (buffer == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    printf("Tamaño del búfer: %d\n", bufsize);

    // Cantidad de items a producir.
    counter = atoi(argv[2]);
    if (counter <= 0) {
        fprintf(stderr, "counter tiene que ser mayor que cero.\n");
        exit(EXIT_FAILURE);
    }

    printf("Items a producir/consumir: %d\n", counter);

    // Reserva memoria para guardar lo que lee el consumidor.
    reader_results = (int*) malloc(sizeof(int)*counter);

    // Imprime en pantalla datos iniciales
    setup_draw();
    
    // Crea el productor
    pthread_create(&writer_t, NULL, writer, NULL); 
    // Crea el consumidor
    pthread_create(&reader_t, NULL, reader, NULL); 

    // Espera a que ambos hilos finalicen
    pthread_join(reader_t, NULL);  
    pthread_join(writer_t, NULL);

    xy(9,1);
    
    // Imprime en pantalla lo que leyó el consumidor
    printf("Consumidor leyo: ");
    for (i = 0; i < counter; i++) {
        printf("%d ", reader_results[i]);
    }
    printf("\n");
    
    pthread_exit(0);
}
