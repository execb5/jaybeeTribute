IDIR = ./include
SDIR = ./src
ODIR = ./obj

CC = gcc
CFLAGS = -Wall -I$(IDIR)

_DEPS = GTree.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = GTree.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
	rm -f main
