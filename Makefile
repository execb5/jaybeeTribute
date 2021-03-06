IDIR = ./include
SDIR = ./src
ODIR = ./obj

CC = gcc
CFLAGS = -Wall -g -I$(IDIR)

_DEPS = GTree.h LinkedList.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = GTree.o main.o LinkedList.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

GTree: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean testLeak

testLeak: GTree
	valgrind --leak-check=full --show-leak-kinds=all -v ./$^


clean:
	rm -f $(ODIR)/*.o
	rm -f GTree
