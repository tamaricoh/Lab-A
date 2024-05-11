# Compiler
CC = gcc 

# Flags
CFlags = -Wall -Wextra -g

# The .c files (sources)
CFiles = main.c numbers.c
my_echo_CFile = my_echo.c

# Sets the names of the .o files
OFiles = $(CFiles:.c=.o)
my_echo_OFile = $(my_echo_CFile:.c=.o)

# Set the executable name
Ex = add
my_echo_Ex = my_echo

# Declare as phony target, so the computer will differ them from files with the same name
.PHONY: all clean

all: $(Ex)

my_echo: $(my_echo_Ex)

$(Ex): $(OFiles)
# linking to executable (@ is the target and ^ the o files)
	$(CC) $(CFlags) -o $@ $^

%.o: %.c
# Create .o file from a .c file. (< is the .c file, @ is the .o file)
	$(CC) $(CFlags) -c -o $@ $<

$(my_echo_Ex): $(my_echo_OFile)
# linking to executable (@ is the target and ^ the o files)
	$(CC) $(CFlags) -o $@ $^

clean:
	rm -f $(OFiles) $(Ex)
	rm -f $(my_echo_OFile) $(my_echo_Ex)

setSpace :
	chmod 700 -R ~

space : 
	du -a | sort -n
