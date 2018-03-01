
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

main.o: main.c treeStructure.h
writeTree.o: writeTree.c writeTree.h
buildTree.o: buildTree.c buildTree.h
valueTree.o: valueTree.c valueTree.h
test.o: test.c test.h
destroyTree.o: destroyTree.c destroyTree.h
