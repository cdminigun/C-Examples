# Makefile for programs in directory ch03-ex01-random-h
# ***************************************************************

PROGRAMS =   guessGame 

# ***************************************************************
# Parameters to control Makefile operation
# Note that the gccx command script must be defined

CC = gcc
CFLAGS =

# ***************************************************************
# Entry to bring the package up to date

all: $(PROGRAMS)

# ***************************************************************
# Standard entries to remove files from the directories
#    tidy    -- eliminate unwanted files
#    scratch -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out graphics.ps

clean: tidy
	rm -f *.o *.a $(PROGRAMS)

# ***************************************************************
# C compilations

random.o: random.c random.h
	$(CC) $(CFLAGS) -c random.c

guessGame.o: guessGame.c random.h
	$(CC) $(CFLAGS) -c guessGame.c


# ***************************************************************
# Executable programs
guessGame: guessGame.o random.o
	$(CC) $(CFLAGS) -o guessGame  guessGame.o random.o
