CC=gcc
CFLAGS=-Wall -Iinclude

all:
	$(CC) $(CFLAGS) src/main.c src/container.c -o mycontainer

clean:
	rm -f mycontainer