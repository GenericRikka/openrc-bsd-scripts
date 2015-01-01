#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FPATH_LIMIT 500
#define MAX_ROWS 1000

char* read(char inputloc[]);
char* convertscr(char input[]);
int write(char outputloc[], char data[]);
int main();

int main(){
	/* Do some tasks */
	char inlocation[1000];
	char outlocation[1000];

	printf("\e[0;31m╔═══╗  ╔════╗    ╔══╗   \e[0;35m       ═══╦═══ ╔════╗       \e[0;32m ╔════╗ ╔════╗ ╔════ ╔╗   ║ ╔═══╗ ╔════╗\n");
	printf("\e[0;31m║   ║  ║         ║  ╚╗  \e[0;35m          ║    ║    ║       \e[0;32m ║    ║ ║    ║ ║     ║╚╗  ║ ║   ║ ║\n");
	printf("\e[0;31m╠═╦═╝  ║         ║   ╚╗ \e[0;35m          ║    ║    ║       \e[0;32m ║    ║ ╠════╝ ╠═══  ║ ╚╗ ║ ╠═╦═╝ ║\n");
	printf("\e[0;31m║ ╚╗   ║         ║   ╔╝ \e[0;35m ════     ║    ║    ║  ════ \e[0;32m ║    ║ ║      ║     ║  ║ ║ ║ ╚╗  ║\n");
	printf("\e[0;31m║  ╚╗  ║      ╔╗ ║  ╔╝  \e[0;35m          ║    ║    ║       \e[0;32m ║    ║ ║      ║     ║  ╚╗║ ║  ╚╗ ║\n");
	printf("\e[0;31m║   ╚  ╚════╝ ╚╝ ╚══╝   \e[0;35m          ║    ╚════╝       \e[0;32m ╚════╝ ║      ╚════ ║   ╚╝ ║   ╚ ╚════╝\n");
	printf("\n");
	printf("\e[0;35m                                                B    Y\n");
	printf("\n");
	printf("\e[0;35m                                     K  K    A     V     V EEEEE X   X\n");
	printf("\e[0;35m                                     K K    A A    V     V E      X X\n");
	printf("\e[0;35m                                     KK    AAAAA    V   V  EEE     X\n");
	printf("\e[0;35m                                     K K  A     A    V V   E      X X\n");
	printf("\e[0;35m                                     K  K A     A     V    EEEEE X   X\n\n\n\e[0m");

	printf("Please enter the path to the rc.d script you want to translate:\n");
	scanf("%24[^\n]", &inlocation);
	getchar();
	printf("Now, please enter a path for the output file:\n");
	scanf("%24[^\n]", &outlocation);
	read(inlocation);
	write(outlocation, "test");
	return 0;
}

char* read(char inputloc[FPATH_LIMIT]){  // This function currently reads from a file and stores it in a virable. ATM it only reads parts of the last three lines
	FILE *fptr;
	int lines = 0;
	char c;
	fptr = fopen(inputloc, "r");
	if(fptr == NULL){
		fputs(stderr, ""Error: Opening specified File returned NULL. Unable to open File."");
		return 1;
	}
	for(c = getc(fptr); c != EOF; c = getc(fptr)){
		if( c == '\n'){
			lines = lines + 1;
		}
	}
	fclose(fptr);
	printf("Counted %d lines.", lines);
	return 0;
	char** data[MAX_ROWS][lines];
	data = malloc(MAX_ROWS * lines * sizeof(*data));
	if(!data){
		fputs(stderr, ""Error: Unable to allocate memory."");
		return 1;
	}
	for(r = 0; )
}

int write(char outputloc[1000], char data[1000]){ // This function works as intended, it writes a string to a file
	FILE *fptr;
	fptr = fopen(outputloc, "w");
	fprintf(fptr, data);
	fclose(fptr);
}
