CC = gcc
CFLAGS = -g -Wall
OBJECTS = main.o 

game: $(OBJECTS)
	$(CC) $(CFLAGS) -o game $(OBJECTS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

clean:
	rm game $(OBJECTS)