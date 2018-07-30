# compile our "cprog" program and 
# link it statically with the "libctest.a" library
main: sources makelib
	gcc -static cprog.c -L. -lctest -o cprog
	
# compile sources
sources:
	gcc -Wall -c ctest1.c ctest2.c

# static librariy 
makelib:
	ar rcs libctest.a ctest1.o ctest2.o
	
# run cprog
run:
	./cprog

# clean gabbage 
clean:
	rm -r *.o *a cprog
