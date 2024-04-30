#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"minput.h"

#define size 1024

//input function implementation

void getString(char *buffer){
	if(fgets(buffer,size,stdin)){
		buffer[strcspn(buffer, "\n")] = 0;
	}else{
		fprintf(stderr, "Errore in reading!!"); 
		exit(EXIT_FAILURE);
	}
}

