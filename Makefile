IDIR = ./include
SDIR = ./src
ODIR = ./obj

CC = gcc
CFLAGS = -Wall -g -I$(IDIR)

_DEPS = GTree.h H45h.h LinkedList.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = GTree.o main.o H45h.o LinkedList.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

GTree: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

testLeak: GTree
	valgrind --leak-check=full -v ./GTree

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
	rm -f GTree
