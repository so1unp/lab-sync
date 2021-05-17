//
// Ejercicio 2 -- sem_unlink
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

    // COMPLETAR: eliminar el semaforo
    int r = ?

    if (r < 0) {
        perror(?);
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}

