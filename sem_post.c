//
// Ejercicio 2 -- sem_post
//

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Uso: %s semaforo\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // COMPLETAR: abrir el semaforo.
    sem_t *sem  = ?

    if (sem == SEM_FAILED) {
        perror(?);
        exit(EXIT_FAILURE);
    }

    // COMPLETAR: realizar el down del semáforo.
    if (?) {
        perror(?);
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}

