# The CC to use
CC=g++

# CC flags
CFLAGS=-c -Wall -std=c++2a
    # -c: Compile or assemble the source files, but do not link.
    # The linking stage simply is not done.
    # The ultimate output is in the form of an object file
    # for each source file.
    #
    # -Wall: This enables all the warnings about constructions that
    # some users consider questionable, and that are easy to avoid
    # (or modify to prevent the warning), even in conjunction with macros.

# Linker flags
# LDFLAGS=

# Libraries
# LIBS=

# Name of executable output
TARGET= program
SRCDIR= src
SUPDIR= src/*
BUILDDIR= bin
TEMPSDIR= temps

OBJS := $(patsubst %.cpp,%.o,$(shell find $(SRCDIR) -name '*.cpp'))

#tried replacing OBJS with this to find the *.o files
#OBJSTEMP := $(shell find $(TEMPSDIR) -name '*.o') 
 
# test of to move command !! not working
#MV := $(shell mv $(SRCDIR)/*.o $(TEMPSDIR) && mv $(SUPDIR)/*.o $(TEMPSDIR))

# mv here wait for build to finish then moves the *.o files to the temps
all: makebuildir $(TARGET) MV 

#mv here would move the *.o files before the build is finished
$(TARGET) : $(OBJS) #MV 
	$(CC) $(LDFLAGS) -o $(BUILDDIR)/$@ $(OBJS) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(BUILDDIR)
	rm -rf $(TEMPSDIR)
	rm -f $(OBJS)

makebuildir:
	mkdir -p $(BUILDDIR)
	mkdir -p $(TEMPSDIR)

MV:
	mv $(SRCDIR)/*.o $(TEMPSDIR)
	mv $(SUPDIR)/*.o $(TEMPSDIR)