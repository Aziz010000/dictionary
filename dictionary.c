#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#include"dictionary.h"

Letter *createLetter(char c){
	Letter *myletter; 
	myletter = malloc(sizeof(Letter)); 
	if(!myletter){
		fprintf(stderr, "Error in allocation!"); 
		exit(EXIT_FAILURE);
	}
	myletter->l = c; 
	myletter->next = NULL; 
	myletter->word = NULL;
	myletter->capacity = 0;
}

void insertLetter(Letter **d,char c){
	Letter *myletter;
	myletter = createLetter(c); 
	if(!(*d)){
		(*d) = myletter;
	}else{
		while((*d)->next){
			 d = &(*d)->next; //crucial part
		}
		(*d)->next= myletter;
	}
}

void myHash(Letter **d,char *s){
	for(int i=0; i<strlen(s); i++){
		insertLetter(d,s[i]); 
	}
}


void visualize(Letter *d){
	while(d){
		printf("Letter %c\n", d->l);
		d = d->next;
	}

}


//code related to inserting a word in the dictionary 
Word *createWord(char *w){
	Word *myWord; 
	myWord = malloc(sizeof(Word)); 
	if(!myWord){
		fprintf(stderr, "Error in allocation\n"); 
		exit(EXIT_FAILURE);
	}
	myWord->w = strdup(w);
	myWord->syn = NULL;
	return myWord;
}


//when you wanna change an atribute of the pointer it is not necessar to have a double pointer
void insertWordLetter(Letter *let, char *b){
	Letter *myword;
	let->word = realloc(let->word, sizeof(Word*)*(let->capacity+1)); 
	if(!let->word){
		fprintf(stderr, "Error in reallocation!!"); 
		exit(EXIT_FAILURE);
	}
	let->word[let->capacity] = createWord(b);
	let->capacity = let->capacity +1;

}


void insertWord(Letter **d, char *b){	
	//you can use here a counter to check some errors
	while((*d)->l != b[0]){
		d = &(*d)->next; 
	}
	insertWordLetter(*d,b);
	printf("PROVa\n");
}

//wanna change this function because I think that I can pass *d 
Word *findWord(Letter *d, char *buffer1){
	while(d && d->l!= buffer1[0]){
		 d =  d->next;
	}
	if(d){
		for(int i=0; i<d->capacity;i++){
			if(strcmp(d->word[i]->w, buffer1)==0){
				return d->word[i];
			}
		}
		return NULL;
	}else{
		return NULL;
	}
}

void visualizeSyn(Letter *d, char *buffer1){
	Word *myword; 
	myword = findWord(d,buffer1);
	myword = myword->syn; 
	if(myword== NULL)printf("BINGO\n");
	while(myword){
		printf("Sinonimo %s\n", myword->w); 
		myword = myword->syn;
	}
}
void insertSynonym(Letter **d, char *buffer1, char *buffer2){
	Word *myd; 
	Word *mySyn;
	myd = findWord(*d,buffer1);
	mySyn = myd;
	bool f = false;
	if(!myd){
		printf("Esito negativo\n");
	}else{
			while(mySyn->syn){
				if(strcmp(mySyn->syn->w,buffer2)==0){
					f = true;
					break;
				}
				mySyn = mySyn->syn;
			}
			mySyn->syn = createWord(buffer2);
			if(!f){
				mySyn->syn->w = strdup(buffer2);
			}
	}
}


//part related visualizing the word which start with a specif letter

void visualizeWordLetter(Letter *d, char c){
	while(d && d->l != c){
		d = d->next;
	}
	if(d){
		for(int i=0; i<d->capacity; i++){
			printf("%s\n", d->word[i]->w);
		}
	
	}

}


