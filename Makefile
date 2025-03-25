CC := gcc
CFLAGS := -Wall

football.o: football.c football.h
	$(CC) $(CFLAGS) -c football.c -o football.o

football.exe: football.o
	$(CC) $(CFLAGS) -o football.exe football.o

temperature.o: temperature.c temperature.h
	$(CC) $(CFLAGS) -c temperature.c -o temperature.o

temperature.exe: temperature.o
	$(CC) $(CFLAGS) -o temperature.exe temperature.o

