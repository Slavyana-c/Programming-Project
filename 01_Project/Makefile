
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/quadTree

SRC= main.c writeTree.c buildTree.c test.c valueTree.c destroyTree.c

# generic build details

CC=      cc
COPT=    -g
CFLAGS= -lm

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

#main: main.o buildTree.o writeTree.o
