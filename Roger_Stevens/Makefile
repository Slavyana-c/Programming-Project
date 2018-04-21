
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/stevens

SRC= main.c options.c game.c files.c editor.c endgame.c texts.c

# generic build details

CC =     gcc
CFLAGS = -Wall -O -std=c99
LIBS =   -lSDL2 -lSDL2_image -lSDL2_ttf


# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o: main.c constants.h globals.h
options.o: options.c options.h constants.h globals.h
game.o: game.c game.h constants.h globals.h
files.o: files.c files.h constants.h globals.h
editor.o: editor.c editor.h constants.h globals.h
endgame.o: endgame.c endgame.h
texts.o: texts.c texts.h
