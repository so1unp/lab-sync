//
// Ejercicio 2 -- sem_wait
//

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <semaphore.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Uso: %s semaforo\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // COMPLETAR: abrir el semáforo.
    sem_t *sem = ?

    if (sem == SEM_FAILED) {
        perror(?);
        exit(EXIT_FAILURE);
    }

    // COMPLETAR: realizar el down
    if (? == -1) {
        perror(?);
        exit(EXIT_FAILURE);
    }

    printf("[%ld] down ok!\n", (long) getpid());

    exit(EXIT_SUCCESS);
}

