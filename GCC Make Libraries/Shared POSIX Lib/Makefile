# compile main and link to dynanic/shared library
main: sources makesharedlib addlibtosystem
	gcc -Wall -o cprog cprog.c -ldl
	
#  create source objects
sources:
	gcc -Wall -fPIC -c ctest1.c ctest2.c

# creates dynamic library stored in libctest.so.1.0 
makesharedlib:  
	gcc -shared -Wl,-soname,libctest.so.1 -o libctest.so.1.0 ctest1.o ctest2.o
	ln -sf libctest.so.1.0 libctest.so
	ln -sf libctest.so.1.0 libctest.so.1
	export LD_LIBRARY_PATH=.
	# copy libs to system shared location
	sudo cp libctest* /usr/lib 


# add to system shared libs
install:
	sudo cp libctest* /usr/lib 

# run cprog
run:
	./cprog

# clean gabbage 
clean:
	rm -r *.o *a cprog
