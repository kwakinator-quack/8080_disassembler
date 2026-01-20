# default compiler is gcc, but we explicity set it to make sure
CC = gcc

# cflags variable sets compile flags for gcc:
#	-g			compile with debug info.
#	-Wall		give verbose compiler warnings
#	-O0			do not optimize generated code
#	-std=c99	use the C99 standard language definition
#	-dwarf-4	use version 4 of the DWARF debugging format
CFLAGS = -g -Wall -O0 -std=c99 #-dwarf-4

# ldlibs variable sets the library flags for linker
#	-lm			links in libm (the math library)
LDLIBS = -lm

# list the files that are part of the project
# here is where you add/change names of sources files
SOURCES = 8080dis.c opcode8080.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = 8080dis

# the first target defined in the makefile is the one used
# when make is involved with no argument. Given the definitions
# above, this Makefile will build the one name TARGET and assume
# that it depends on all the named OBJECTS files
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# phony means not a "real" target, so it doesn't build anything.
# The phony target "clean" is used to remove all compiled object files
.PHONY: clean

clean:
	@rm -f $(TARGET) $(OBJECTS) core
