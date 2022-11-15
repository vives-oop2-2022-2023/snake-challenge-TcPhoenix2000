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
BUILDDIR= bin
TEMPSDIR= temps

OBJS := $(patsubst %.cpp,%.o,$(shell find $(SRCDIR) -name '*.cpp'))

all: makebuildir $(TARGET)

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