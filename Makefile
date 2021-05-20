CC=gcc
BIN=./bin
CFLAGS=-Wall -g -pthread -lm

PROG=glob philo buf peluquero semaphores 

LIST=$(addprefix $(BIN)/, $(PROG))

.PHONY: all
all: $(LIST)

$(BIN)/%: %.c
	$(CC) -o $@ $< $(CFLAGS)

%: %.c
	$(CC) -o $(BIN)/$@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(BIN)/glob $(BIN)/ph $(BIN)/philo $(BIN)/buf $(BIN)/peluquero $(BIN)/sem_* $(BIN)/sig_*
