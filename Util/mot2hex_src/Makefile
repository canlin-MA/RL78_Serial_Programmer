CC=gcc
EXECNAME=mot2hex.exe

IDIR =inc
CFLAGS=-I$(IDIR)

ODIR=obj
SDIR=src
LDIR=lib

LIBS=-lpthread

_DEPS = gethex.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = gethex.o main.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECNAME): $(OBJ) 
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(EXECNAME) $(ODIR)/*.o *~ 