CREATOR =  gcc -Wall -ansi -pedantic

# Creating the final executable - seek.
seek: seek.o 
	$(CREATOR) -g seek.o -o seek


# Creating seek.o file.
seek.o: seek.c
	$(CREATOR) -g -c seek.c -o seek.o