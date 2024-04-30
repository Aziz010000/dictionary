typedef struct word{
	char *w;
	struct word *syn; 
}Word;


typedef struct letter{
	char l;
	struct letter *next; 
	Word **word; 
	int capacity;
}Letter; 


Letter *createLetter(char c);
void insertLetter(Letter **d, char c);
void myHash(Letter **d, char *s);
void visualize(Letter *d);
Word *createWord(char *w);
void insertWordLetter(Letter *let, char *b);
void insertWord(Letter **d, char *b);
Word *findWord(Letter *d, char *buffer1);
void visualizeSyn(Letter *d, char *buffer1);
void insertSynonym(Letter **d, char *buffer1, char *buffer2);
void visualizeWordLetter(Letter *d, char c);
