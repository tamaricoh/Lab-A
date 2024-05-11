# Compiler
CC = gcc 

# Flags
CFlags = -Wall -Wextra -g

# The .c files (sources)
CFiles = main.c numbers.c

# Sets the names of the .o files
OFiles = $(CFiles:.c=.o)
# Set the executable name
Ex = add

# Declare as phony target, so the computer will differ them from files with the same name
.PHONY: all clean

all: $(Ex)

$(Ex): $(OFiles)
# linking to executable (@ is the target and ^ the o files)
	$(CC) $(CFlags) -o $@ $^

%.o: %.c
# Create .o file from a .c file. (< is the .c file, @ is the .o file)
	$(CC) $(CFlags) -c -o $@ $<

clean:
	rm -f $(OFiles) $(Ex)

setSpace :
	chmod 700 -R ~

space : 
	du -a | sort -n
