#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FPATH_LIMIT 500 /* maximum length for file paths */
#define MAX_ROWS 1000 /* maximum of rows to be expected in the script */

int read(char inputloc[], char outputloc[]); /* a small function to read from a file and then call another function with read data as argument */
int convert(char* data, long size); /* main thread during the conversion of the script. It calls sub functions to modify different parts */
int write(char outputloc[], char* data); /* a small function to write to a file */
int delete(long a, long b, char* data); /* a function that deletes the section from a to b in data. one of the functions called by convert */
int extract(char pattern[], char delim[], char* data); /* a function which extracts the value found after pattern and before delim from data. one of the functions called by convert */
int insert(char insert[], long pos, char* data); /* this function inserts insert at pos in data. one of the functions called by convert */
int replace(char target[], char phrase[], char* data); /* a function to replace target with phrase inside data. one of the functions called by convert */
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
	read(inlocation, outlocation);
	printf("After read.");
        //write(outlocation, "test");
	return 0;
}

int read(char inputloc[FPATH_LIMIT], char outputloc[FPATH_LIMIT]){
	FILE *file;
	char *data;
	long size;

	printf("Read initialized.");
	file = fopen(inputloc, "rb");
	if(! file) fputs("[ERROR] Unable to open file.",stderr),perror(inputloc),printf("Unable to open file.\n"),exit(1);
	fseek(file, 0L, SEEK_END);
	size = ftell(file);
	rewind(file);

	data = malloc(1 * size + 1); 
	if(!data) fclose(file),fputs("[ERROR] Failed to allocate memory. Bailing out.",stderr),perror("malloc fail"),printf("[ERROR] Failed to allocate memory.\n"),exit(1);
	if(1 != fread(data, size, 1, file))
		fclose(file),free(data),fputs("[ERROR] Read Operation from file failed.",stderr),perror("read fail"),printf("[ERROR] Read operation failed\n"),exit(1);
	fread(data, size, 1, file);
	int i;
	printf("Read:\n");
	for(i = 0; i <= size; i++) printf("%c",data[i]);
	convert(&data, size);
	fclose(file);
	write(outputloc, &data);
	free(data);
	return(0);
}

int convert(char* data, long size){ 
	int i;
	printf("Recieved:\n");
	for(i = 0; i <= size; i++) printf("%c",data[i]);
	long a = 10;
	long b = 300;
	delete(a, b, &data);
	printf("Edited:\n");
	for(i = 0; i <= size; i++) printf("%c",data[i]);
	return(0);
}	

int delete(long a, long b, char* data){
	long size = strlen(data);
	long d = b - a;
	char *buffer;
	buffer = malloc(sizeof(data)); 
	int i;
	for(i = 0; i < a; i++){
		buffer[i] = data[i];
	}
	for(i = b; i < size; i++){
		buffer[i - d] = data[i];
	}
	for(i = 0; i < size+1; i++) data[i] = buffer[i];
	free(buffer);
	return(0);
}

int write(char outputloc[1000], char* data){ // This function works as intended, it writes a string to a file
	FILE *fptr;
	fptr = fopen(outputloc, "w");
	fprintf(fptr, data);
	fclose(fptr);
	return(0);
}
