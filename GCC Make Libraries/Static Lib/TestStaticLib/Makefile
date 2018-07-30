# compile our "cprog" program and 
# link it statically with the "libctest.a" library
main: 
	gcc -static cprog.c -L. -lctest -o cprog
	
# run cprog
run:
	./cprog

# clean gabbage 
clean:
	rm -r *.o cprog
