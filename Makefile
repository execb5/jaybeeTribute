IDIR = ./include
SDIR = ./src
ODIR = ./obj

CC = gcc
CFLAGS = -Wall -g -I$(IDIR)

_DEPS = GTree.h H45h.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = GTree.o main.o H45h.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

testLeak: main
	valgrind --leak-check=full -v ./main

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
	rm -f main
