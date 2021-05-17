//
// Ejercicio 2 -- sem_getvalue 
//

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <semaphore.h>

int main(int argc, char* argv[])
{
    int value;
    sem_t *semaphore;

    if (argc < 2) {
        fprintf(stderr, "Uso: %s semaforo\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // COMPLETAR: abrir el semaforo
    if (semaphore == SEM_FAILED) {
        perror(?);
        exit(EXIT_FAILURE);
    }


    // COMPLETAR: obtener el valor del semáforo
    if (value == -1) {
        perror(?);
        exit(EXIT_FAILURE);
    }

    printf("%s value: %d\n", argv[1], value);

    exit(EXIT_SUCCESS);
}

