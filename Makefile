CC := gcc

football.exe: football.c football_main.c
    $(CC) -o football.exe football.c football_main.c

temperature.exe: temperature.c temperature_main.c
    $(CC) -o temperature.exe temperature.c temperature_main.c
