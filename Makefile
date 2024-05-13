# Compiler
CC = gcc 

# Flags
CFlags = -Wall -Wextra -g

# The .c files (sources)
CFiles = main.c numbers.c
my_echo_CFile = my_echo.c
part1_CFile = Dbug.c

# Sets the names of the .o files
OFiles = $(CFiles:.c=.o)
my_echo_OFile = $(my_echo_CFile:.c=.o)
part1_OFile = $(part1_CFile:.c=.o)

# Set the executable names
Ex = add
my_echo_Ex = my_echo
part1_Ex = Dbug

# Declare as phony target, so the computer will differ them from files with the same name
.PHONY: all clean

all: $(Ex) $(my_echo_Ex) $(part1_Ex)

$(Ex): $(OFiles)
	$(CC) $(CFlags) -o $@ $^

$(my_echo_Ex): $(my_echo_OFile)
	$(CC) $(CFlags) -o $@ $^

$(part1_Ex): $(part1_OFile)
	$(CC) $(CFlags) -o $@ $^

%.o: %.c
	$(CC) $(CFlags) -c -o $@ $<

clean:
	rm -f $(OFiles) $(Ex) $(my_echo_OFile) $(my_echo_Ex) $(part1_OFile) $(part1_Ex)

setSpace :
	chmod 700 -R ~

space : 
	du -a | sort -n