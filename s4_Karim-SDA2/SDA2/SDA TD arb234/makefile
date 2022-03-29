CC = gcc -g
CFLAGS = -W -Wall
SOURCES = $(wildcard *.c)
HS = $(wildcard *.h)
OBJETS = $(SOURCES:.c=.o)
EXEC = main

$(EXEC) : $(OBJETS)
	$(CC) $(CFLAGS) -o $@ $^
%.o : %.c
	$(CC) $(CFLAGS) -c $<
dist: makefile $(SOURCES) $(HS) graphes.cafe
	tar -cvz $^ -f graphes.tar.xz
clean:
	rm $(OBJETS) $(EXEC)
