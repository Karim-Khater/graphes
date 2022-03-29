CC = gcc -g
CFLAGS = -W -Wall -Werror
SOURCES = $(wildcard *.c)
OBJETS = $(SOURCES:.c=.o)
EXEC = main

$(EXEC) : $(OBJETS)
	$(CC) $(CFLAGS) -o $@ $^ 
%.o : %.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm $(OBJETS)
