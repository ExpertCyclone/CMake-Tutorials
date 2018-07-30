
// include standard C header files
#include <stdio.h>
#include <stdlib.h>
// includes "dlfcn.h" with macros like RTLD_LAZY (man dlopen, man dlfcn.h) 
#include <dlfcn.h>
// to prevent C++ from mangling our function symbol names
#include "ctest.h"
 
int main(){
    void *handle;
    char *error;
    int x, y, z;
	
	// get handle to "libctest.so.1" library using dlopen
    handle = dlopen ("libctest.so.1", RTLD_LAZY);

    // exit if lib handle is invalid
    if (!handle) {
        fputs (dlerror(), stderr);
        exit(1);
    }
	
	// assign function pointer to lib function ctest1
    ctest1 = dlsym(handle, "ctest1"); //  we let C++ to mangle symbol names
    // exit if can't assign function to function pointer 
    if (( error = dlerror() ) != NULL)  {
        fputs(error, stderr);
        exit(1);
    }
 
	// assign function pointer to lib function ctest2
    ctest2 = dlsym(handle, "ctest2"); //  we let C++ to mangle symbol names
    // exit if can't assign function to function pointer 
    if (( error = dlerror() ) != NULL)  {
        fputs(error, stderr);
        exit(1);
    }
	
	// use assigned function pointers
    ctest1(&x);
    ctest2(&y);
    // use vars and print val z
    z = (x / y);
    printf("%d / %d = %d\n", x, y, z);
    
    // close handle
    dlclose(handle);
    return 0;
}
