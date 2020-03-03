/*
This program prints out how many lines, words and characters has a file, whose name is entered by user.
*/

#include <stdio.h>

void file_read(char *name);
char *get_file_name();
void classify(char *fname);
void menu();

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
int main ()
{
    classify(get_file_name());				
    menu();

	return(0);
}
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
char *get_file_name()						// BUG: funkce get_file_name() nevracela nazev souboru zadany uzivatelem,
{											// ale pointer na vstupni promenne, tedy nic,
	printf("File name: ");					// proto je zde pouzit "malloc", ktery toto vyresi
	char *fname = (char *) malloc (100 * sizeof (char));
	scanf("%s",fname);
 	return (fname);
// 	free(fname);							// nevim jestli to tu neni zbytecne a nemelo by to byt jinde
}
////////////////////////////////////////////////////////////////////////
void classify(char *fname)
{
	char c;
	int lines, words, characters, state;
	state = 0;
	lines = words = characters = 0;

	FILE *file;
	file = fopen(fname, "r");
	if (file){
	while ((c = getc(file)) != EOF) {
		++characters;
		if (c == '\n')
			++lines;
		if (c == ' ' || c == '\n' || c == '\t')
			state = 0;
		else if (state == 0) {
			state = 1;
		++words;
		}
	}
	printf("lines: %d\nwords: %d\ncharacters: %d\n", lines, words, characters);
	}
	else {
		printf("No file named: %s\n", fname);
		 printf("______________________________________________\n");
		main();
	} 
}
////////////////////////////////////////////////////////////////////////
void menu(){
	printf("______________________________________________\n");
	printf("What else you wanna do?\n");
	printf("0 -> Quit this program.\n");
	printf("1 -> Enter another file name.\n");
	

again:										// come back to enter decision again
	printf("Choice:");
	int decision;
	scanf("%d", &decision);
/*	if ( decision == 0 || decision == 1){
	}
	else{
		printf("Invalid input, try again.\n");
		goto again;	
	}*/

	switch (decision){							// choose the matching way
		case 0:
		break;
		case 1:
			printf("______________________________________________\n");
			main();
		break;
		default:
			printf("Invalid input, try again.\n");
			goto again;	
	}
}


////////////////////////////////////////////////////////////////////////
void file_read(char *fname)
{
	char c;
	FILE *file;

	file = fopen(fname, "r");
	if (file) {
    	while ((c = getc(file)) != EOF)
        	putchar(c);
    fclose(file);
	}
	else {
		printf("No file named: %s\n", fname);
	} 
}