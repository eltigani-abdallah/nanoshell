CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = nanoshell

SOURCES = main.c builtins.c execution.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c shell.h
	$(CC) $(CFLAGS) -c $

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean