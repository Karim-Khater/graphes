CC = gcc -g 
CFLAGS= -W -Wall
SOURCES= $(wildcard *.c)
OBJETS= $(SOURCES:.C=.o)
EXEC=main

$(EXEC) : $(OBJETS)
	$(CC) $(CFLAGS) -o $@ $^ -lm
%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm $(EXEC) $(OBJETS)