CC := gcc

football.exe: football.c football.h
    $(CC) -o football.exe

temperature.exe: temperature.c temperature.h
    $(CC) -o temperature.exe 
