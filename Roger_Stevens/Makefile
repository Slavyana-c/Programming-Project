
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/stevens

SRC= main.c options.c

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

main.o: main.c constants.h
options.o: options.c options.h
#play.o : play.c constants.h
#files.o: files.c constants.h
#game_modes.o: game_modes.c constants.h
#editor.o: editor.c editor.h constants.h
