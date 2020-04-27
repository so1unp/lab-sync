# Laboratorio 6 - Señales

:bulb: Las respuestas a las preguntas en los ejercicios pueden incluirlas en un archivo de texto con el nombre `respuestas.txt`.

:date: Fecha de entrega: 23/04

## Ejercicio 1

Completar los programas `sig_sender.c` y `sig_receiver.c`:

* `sig_sender.c`: Envía la señal indicada a un proceso.
* `sig_receiver.c`: Espera por la recepción de señales. Por cada señal recibida imprime el identificador y una descripción de la misma.

Utilizar las siguientes funciones y llamadas al sistema:

* [`kill()`](http://man7.org/linux/man-pages/man2/kill.2.html): envía una señal a un proceso.
* [`signal()`](http://man7.org/linux/man-pages/man2/signal.2.html): permite especificar un handler.
* [`pause()`](http://man7.org/linux/man-pages/man2/pause.2.html): espera a recibir una señal.
* [`strsignal()`](http://man7.org/linux/man-pages/man3/strsignal.3.html): retorna un puntero a una cadena con la descripción de la señal indicada.
* El archivo de cabecera `signal.h` incluye la constante `NSIG`, igual a la cantidad de señales del sistema más uno.

Responder:

1. ¿Cuáles son las dos señales que no se pueden "atrapar"? ¿Por qué?

---

¡Fin del Laboratorio 6!
