# REESE ALLEN | rga2uz | Makefile | 10-26-20
# link assembly with C++

# Defines the C++ compiler we'll be using
CXX = clang++

# Defines the flags we'll be passing to the C++ compiler
CXXFLAGS = -Wall -g

# Defines the assembler
AS = nasm

# Defines the flags for the assembler
ASFLAGS = -f macho64 -g

# All of the .o files for our program
OBJECTS = mathlib.o mathfun.o

# Compile our files into a.out
a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcibly remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	-rm -f *.o *~