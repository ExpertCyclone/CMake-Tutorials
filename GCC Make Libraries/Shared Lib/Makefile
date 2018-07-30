# compile main and link to dynanic/shared library
main: sources makelibs addlibtosystem
	# set the LD_LIBRARY_PATH to the current directory because Linux dynamic 
	# loader uses this variable to search for libraries
	export LD_LIBRARY_PATH=.
	gcc -Wall -L. cprog.c -lctest -o cprog

#  create source objects
sources:
	gcc -Wall -fPIC -c ctest1.c ctest2.c

# creates dynamic library stored in libctest.so.1.0  file with "libctest.so.1" 
# soname create symlinks used to point GNU Linker and Linux dynamic loader to 
# the proper versions of our library
makelibs:
	gcc -shared -Wl,-soname,libctest.so.1 -o libctest.so.1.0 ctest1.o ctest2.o
	ln -sf libctest.so.1.0 libctest.so
	ln -sf libctest.so.1.0 libctest.so.1

# add to system shared libs
addlibtosystem:
	sudo cp libctest* /usr/lib 
	
# run program
run:
	./cprog

# cleaan gabbage
clean:
	rm -r ./cprog *.so*
