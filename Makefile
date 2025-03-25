CC := gcc
CFLAGS := -Wall

football.exe: football.o
	$(CC) $(CFLAGS) -o football.exe football.o

football.o: football.c football.h
	$(CC) $(CFLAGS) -c football.c -o football.o

temperature.exe: temperature.o
	$(CC) $(CFLAGS) -o temperature.exe temperature.o

temperature.o: temperature.c temperature.h
	$(CC) $(CFLAGS) -c temperature.c -o temperature.o

