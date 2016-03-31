# Makefile for [INSER_NAME]
# ***************************************************************
PROGRAMS = \
    [INSERT_PROG1] \
        [INSERT_PROG2] \
# Add up to N addtional lines depending upon programs
# ***************************************************************
# Parameters to control Makefile operation
# Note that the gccx command script must be defined
#CC = gccx
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
scratch: tidy
    rm -f *.o *.a $(PROGRAMS)
# ***************************************************************
# C compilations
[INSERT_PROG1].o: [INSERT_PROG1].c [INSERT_PROG1].h
    $(CC) $(CFLAGS) -c [INSERT_PROG1].c
[INSERT_PROG2].o: some2.c some2.h
    $(CC) $(CFLAGS) -c [INSERT_PROG2].c
[INSERT_DRIVER].o: [INSERT_DRIVER].c some.h
    $(CC) $(CFLAGS) -c [INSERT_DRIVER].c
# ***************************************************************
# Executable programs
[INSERT_PROG1]: [INSERT_DRIVER].o [INSERT_PROG1].o
    $(CC) $(CFLAGS) -o [INSERT_PROG1] [INSERT_DRIVER].o [INSERT_PROG1].o
[INSERT_PROG2]: [INSERT_DRIVER].o [INSERT_PROG2].o
	$(CC) $(CFLAGS) -o [INSERT_PROG2] [INSERT_DRIVER].o [INSERT_PROG2].o
