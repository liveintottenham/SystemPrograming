/*dltest.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include "math.h"

int main() {

	void *handle;
	int (*add)(int, int), (*subtract)(int, int), (*multiply)(int, int), (*divide)(int, int);
	char *error;

	handle = dlopen ("./lib/libshare.so", RTLD_LAZY);
	
	if(!handle) {
		fputs(dlerror(), stderr);
		exit(1);
	}
	
	char* str = (char*)malloc(10*sizeof(char));
	int a, b;
	
	printf("What do you want to calculate? ");
	scanf("%s", str);
	
	printf("Two numbers = ");
	scanf("%d %d", &a, &b);
	
	if(strcmp(str, "add") == 0) {
		add = dlsym(handle, "add");
		if((error = dlerror()) != NULL) {
			fprintf(stderr, "%s", error);
			exit(1);
		}
		printf("add = %d\n", (*add)(a,b));
	}
	
	else if(strcmp(str, "subtract") == 0) {
		subtract = dlsym(handle, "subtract");
		if((error = dlerror()) != NULL) {
			fprintf(stderr, "%s", error);
			exit(1);
		}
		printf("subtract = %d\n", (*subtract)(a,b));
	}
	
	else if(strcmp(str, "multiply") == 0) {
		multiply = dlsym(handle, "multiply");
		if((error = dlerror()) != NULL) {
			fprintf(stderr, "%s", error);
			exit(1);
		}
		printf("multiply = %d\n", (*multiply)(a,b));
	}
	
	else if(strcmp(str, "divide") == 0) {
		divide = dlsym(handle, "divide");
		if((error = dlerror()) != NULL) {
			fprintf(stderr, "%s", error);
			exit(1);
		}
		printf("divide = %d\n", (*divide)(a,b));
	}
	
	dlclose(handle);
	free(str);
}
	
	

