#include <stdio.h>
#include <string.h>

char* read(char inputloc[]);
char* convert(char input[]);
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
	printf("\e[0;35m                                  B    Y\n");
	printf("\n");
	printf("\e[0;35m                     K  K    A     V     V EEEEE X   X\n");
	printf("\e[0;35m                     K K    A A    V     V E      X X\n");
	printf("\e[0;35m                     KK    AAAAA    V   V  EEE     X\n");
	printf("\e[0;35m                     K K  A     A    V V   E      X X\n");
	printf("\e[0;35m                     K  K A     A     V    EEEEE X   X\n\n\n\e[0m");

	printf("Please enter the path to the rc.d script you want to translate:\n");
	scanf("%c", &inlocation);
	printf("Now, please enter a path for the output file:\n");
	scanf("%c", &outlocation);
	read("/home/kavex/Desktop/test.txt");
	write(outlocation, "test");
	return(0);
};

char* read(char inputloc[1000]){  // This function currently reads from a file and stores it in a virable. ATM it only reads parts of the last three lines
	FILE *fptr;
	char string1[1000];
	char string2[1000];
	char string3[1000];
	char line[1000];
	fptr = fopen(inputloc, "r");
	int cur_ln = 0;
	while(fgets(line, 1000, fptr) != NULL){
		if (cur_ln == 2) {
			sscanf (line, "%s %s %s \n", string1, string2, string3);
			break;
		}
		cur_ln++;
	}
	/*
	char script[1000];
	fgets(script, 1000, fptr);
	printf("%s", script);
	while(fgets(script, 1000, fptr)) {
 		printf("%s", script);
	}
	*/
	fclose(fptr);
	printf("%s\n%s\n%s", string1, string2, string3);
	return "test";
};

int write(char outputloc[1000], char data[1000]){ // This function works as intended, it writes a string to a file
	FILE *fptr;
	fptr = fopen(outputloc, "w");
	fprintf(fptr, data);
	fclose(fptr);
};
