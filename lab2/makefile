
#YOU MUST HAVE YOUR NAME IN YOUR MAKEFILE!

#Makefile for lab 1-4.  You need to add you name to this file in the comments
# You will need to add a entry to create your zip file

#change the last dependency for each new lab
all:  tags headers lab2 

#this entry has to change for lab 2 - 4
# NEVER compile .c files with this rule - it lacks needed compile time flags
# There is an entry below that turns .c files into .o files

lab2: lab2.o bits.o input.o output.o physics.o 
	gcc -g -o $@ $^ -L. -lpb -lncurses -lm

#this is where you create an entry to build yuour zip file
#it will also update with new labs



#this entry stays for C code labs
tags: *.c
	ctags -R .

# this entry stays for C code labs
headers: *.c tags
	./headers.sh


# this entry takes care of C files depending on header files
# It has the flags for compiling the c code
# It you don't like makefiles, consider typing the following line a few
# thousand times this semester and reconsider.
# Be sure that this one doesn't get an inserted line break anywhere
%.o:%.c *.h
	gcc -std=c99 -pedantic -Wformat -Wreturn-type -g -c $< -o $@

clean:
	rm -f tags headers *.vs bits.h bits.o input.h input.o physics.h physics.o lab2.h lab2.o output.h output.o physics.h physics.o
