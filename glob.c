//
// Ejercicio 1
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Variable global que incrementan los hilos.
static int glob = 0;

static void *hilo(void *arg)
{
    int loops = *((int *) arg);
    int loc, j;

    // incrementa glob
    for (j = 0; j < loops; j++) {
        loc = glob;
        loc++;
        glob = loc;
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t t1, t2;
    int loops;
 
    // Controla numero de argumentos.
    if (argc != 2) {
        fprintf(stderr, "Uso: %s ciclos\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    loops = atoi(argv[1]);

    // Verifica argumentos.
    if (loops < 1) {
        fprintf(stderr, "Error: ciclos debe ser mayor a cero.\n");
        exit(EXIT_FAILURE);
    }

    // Crea hilo t1.
    if ( pthread_create(&t1, NULL, hilo, (void*) &loops) != 0 ) {
        perror("pthread_create");
    }

    // Crea hilo t2.
    if ( pthread_create(&t2, NULL, hilo, (void*) &loops) ) {
        perror("pthread_create");
    }

    // Espera por el hilo t1.
    if ( pthread_join(t1, NULL) != 0) {
        perror("pthread_join");
    }

    // Espera por el hilo t2.
    if ( pthread_join(t2, NULL) != 0) {
        perror("pthread_join");
    }

    printf("%d\n", glob);

    exit(EXIT_SUCCESS);
}
