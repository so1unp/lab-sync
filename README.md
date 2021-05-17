# Laboratorio 6 - Concurrencia y Sincronización

:bulb: Agregar las respuestas a las preguntas de los ejercicios en un archivo de texto con el nombre `ejX.txt`.

## Ejercicio 1

El programa `glob.c` crea dos hilos que incrementan repetidamente la variable global `glob` el número de veces indicado en la línea de comandos.

1. Compilar y ejecutar el programa, probando valores hasta que se encuentre una _condición de carrera_. ¿Por qué ocurre esta situación de carrera? ¿Cómo se podría evitar?
2. ¿Por qué al pasar un valor pequeño como parámetro el resultado es correcto?
3. Evitar la condición de carrera mediante el uso de un _mutex_ (`pthread_mutex_t`). Utilizar un _mutex_ inicializado estáticamente, con `PTHREAD_MUTEX_INITIALIZER`. Para tomar y liberar el _mutex_, usar las funciones `pthread_mutex_lock()` y `pthread_mutex_unlock()` respectivamente.

## Ejercicio 2

Completar los siguientes programas:

* `sem_open.c`: crea un semáforo, con el nombre indicado como parámetro.
* `sem_wait.c`: realiza una operación _down_ sobre el semáforo indicado.
* `sem_post.c`: realiza una operación _up_ sobre el semáforo indicado.
* `sem_getvalue.c`: imprime el valor del semáforo indicado.
* `sem_unlink.c`: elimina el semáforo indicado.

Utilizar las siguientes funciones:
* [`sem_open()`](https://man7.org/linux/man-pages/man3/sem_open.3.html): abre o crea un semáforo.
* [`sem_post()`](https://man7.org/linux/man-pages/man3/sem_post.3.html): realiza una operación up sobre el semáforo.
* [`sem_wait()`](https://man7.org/linux/man-pages/man3/sem_post.3.html): realiza una operación down sobre el semáforo.
* [`sem_getvalue()`](https://man7.org/linux/man-pages/man3/sem_getvalue.3.html): obtiene el valor actual de un semáforo.
* [`sem_close()`](https://man7.org/linux/man-pages/man3/sem_close.3.html): cierra un semáforo.
* [`sem_unlink()`](https://man7.org/linux/man-pages/man3/sem_unlink.3.html): elimina un semáforo del sistema.

Una vez completados los programas, tendrían que poder ejecutar la siguiente serie de comandos: primero, se crea un semáforo con un valor inicial de cero. Luego, se  realiza una operación _down_, luego un _up_, y finalmente se lo elimina.

```bash
$ sem_open /semaforo 0
$ sem_wait /semaforo &
$ sem_post /semaforo
$ sem_unlink /semaforo

```
Responder:

1. ¿Qué es lo que sucede con el proceso que ejecuta `sem_wait` en el segundo comando del ejemplo?

## Ejercicio 3

El programa `buf.c` implementa un ejemplo de productor-consumidor haciendo uso de un _buffer limitado_. El programa no utiliza mecanismos de sincronización para el acceso al buffer. Esto puede ocasionar condiciones de carrera. Modificar el programa para sincronizar el acceso al buffer, empleando semáforos y _mutexs_. En este ejercicio y en los que siguen, crear los _mutexs_ con la funcion `pthread_mutex_init()`.

## Ejercicio 4

El programa `philo.c` implementa un ejemplo del problema de la _cena de los filósofos_. Durante la ejecución del programa puede ocurrir una condición de carrera.

1. Describir la condición de carrera que puede ocurrir durante la ejecución del programa.

2. Modificar el programa para evitar la condición de carrera mediante el uso de semáforos y mutexes.

3. Agregar también una solución para evitar el _bloqueo mutuo_ o _abrazo mortal_. Explicarla.

## Ejercicio 5 

Un problema clásico de IPC es el problema del peluquero dormido. Una peluquería tiene *n* peluqueros, y *m* sillas donde los clientes esperan su turno. Si no hay clientes, los peluqueros duermen (se _bloquean_). Cuando arriba un cliente, alguno de los peluqueros se despierta, y realiza el corte de pelo. Si todos los peluqueros estuvieran ocupados, y hubiera sillas disponibles, el cliente se sienta a esperar su turno (es decir, se _bloquea_ a la espera de su turno). Caso contrario, se retira. Implementar en `peluquero.c` un ejemplo de este problema. Emplear semáforos para manejar **sincronización** y _mutexs_ para garantizar la **exclusión mutua**.

---

¡Fin del Laboratorio 6!
