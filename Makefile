# Compiler
CC = gcc 

# Flags
CFlags = -Wall -Wextra -g

# The .c files (sources)
CFile = encoder.c

# Sets the names of the .o files
OFile = $(CFile:.c=.o)

# Set the executable names
Ex = encoder

# Declare as phony target, so the computer will differ them from files with the same name
.PHONY: all clean

all: $(Ex)

$(Ex): $(OFile)
	$(CC) $(CFlags) -o $@ $^

%.o: %.c
	$(CC) $(CFlags) -c -o $@ $<

clean:
	rm -f $(OFile) $(Ex)

setSpace :
	chmod 700 -R ~

space : 
	du -a | sort -n