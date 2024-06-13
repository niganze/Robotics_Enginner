CC = gcc
CFLAGS = -Wall -g
TARGET = generic_arrayp2

all: $(TARGET)

$(TARGET): generic_arrayp2.o
	$(CC) $(CFLAGS) -o $(TARGET) generic_arrayp2.o

generic_arrayp2.o: generic_arrayp2.c
	$(CC) $(CFLAGS) -c generic_arrayp2.c

clean:
	rm -f *.o $(TARGET)
