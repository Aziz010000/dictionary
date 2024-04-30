#include<stdio.h>
#include"minput.h"
#include"dictionary.h"

#define size 1024


int main(int arcv, char *argv[])
{
	char *alphabet = "abcdefghilmnopqrstuvz";
	Letter *dictionary = NULL;
	myHash(&dictionary,alphabet);
	char scelta; 
	char let; 
	char buffer1[size], buffer2[size];
	while(1){
		printf("1.Insert a word the dictionary\n"); 
		printf("2.Visualize word that start with a specif letter\n");
		printf("3.Insert a synonym of a given wod in the dictionary\n"); 
		printf("4.Visualize all synonyms of a given word\n");
		scelta = getchar(); 
		while(getchar()!='\n');
		switch(scelta){
			case '1': 
				printf("Type word you wanna insert to the dictionary...\n"); 
				getString(buffer1);
				insertWord(&dictionary, buffer1);
				break;
			case '2': 
				printf("Type a letter you wanna see the word which start with that letter...\n"); 
				let = getchar();
				while(getchar()!='\n');
				visualizeWordLetter(dictionary,let); 
				break;
			case '3':
				printf("Type a word that you wanna register a synonym...\n"); 
				getString(buffer1); 
				printf("Type a sysnonym you of %s...\n", buffer1); 
				getString(buffer2); 
				insertSynonym(&dictionary,buffer1,buffer2);
				break; 
			case '4': 
				printf("Type a word you wanna see synonyms...\n");
				getString(buffer1);
				visualizeSyn(dictionary,buffer1);
				break;
			default: 
				printf("Option unknown!!");
		}
	}



	return 0; 
}
