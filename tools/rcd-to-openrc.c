#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

#define FPATH_LIMIT 500 /* maximum length for file paths */
#define MAX_ROWS 1000 /* maximum of rows to be expected in the script */

void myread(char inputloc[], char outputloc[]); /* a small function to read from a file and then call another function with read data as argument */
void convert(char* data, size_t size); /* main thread during the conversion of the script. It calls sub functions to modify different parts */
void mywrite(char outputloc[], char* data); /* a small function to write to a file */
void delete(size_t a, size_t b, char* data); /* a function that deletes the section from a to b in data. one of the functions called by convert */
void extract(char* pattern, char* delim, char* data, char* extract); /* a function which extracts the value found after pattern and before delim from data and saves it to extract. one of the functions called by convert */
void myinsert(char* insert, size_t pos, char* data); /* this function inserts insert at pos in data. one of the functions called by convert */
void replace(char target[], char phrase[], char* data); /* a function to replace target with phrase inside data. one of the functions called by convert */
void cmdextract(char* data, char* extractpre, char* extractpost);
char* strrev(char* str);
void print_progress(char *title1, char *title2, int count, int max, int *spinstore);
void test_progress();
int main();


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!    THIS PROGRAM CURRENTLY CONTAINS MEMORY LEAKS, I STRONGLY ADVISE NOT TO RUN IT      !!!!!
!!!!!    THIS PROGRAM CURRENTLY CONTAINS MEMORY LEAKS, I STRONGLY ADVISE NOT TO RUN IT      !!!!!
!!!!!    THIS PROGRAM CURRENTLY CONTAINS MEMORY LEAKS, I STRONGLY ADVISE NOT TO RUN IT      !!!!!
!!!!!    THIS PROGRAM CURRENTLY CONTAINS MEMORY LEAKS, I STRONGLY ADVISE NOT TO RUN IT      !!!!!
!!!!!    THIS PROGRAM CURRENTLY CONTAINS MEMORY LEAKS, I STRONGLY ADVISE NOT TO RUN IT      !!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


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
	printf("\e[0;35m                                               B    Y\n");
	printf("\n");
	printf("\e[0;35m                                 K  K    A     V     V EEEEE X   X\n");
	printf("\e[0;35m                                 K K    A A    V     V E      X X\n");
	printf("\e[0;35m                                 KK    AAAAA    V   V  EEE     X\n");
	printf("\e[0;35m                                 K K  A     A    V V   E      X X\n");
	printf("\e[0;35m                                 K  K A     A     V    EEEEE X   X\n\n\n\e[0m");

	printf("Please enter the path to the rc.d script you want to translate:\n");
	scanf("%24[^\n]", &inlocation);
	getchar();
	printf("Now, please enter a path for the output file:\n");
	scanf("%24[^\n]", &outlocation);
	myread(inlocation, outlocation);
	printf(" Done!");
        //write(outlocation, "test");
	return 0;
}

void myread(char inputloc[FPATH_LIMIT], char outputloc[FPATH_LIMIT]){ //Tested. Works.
	FILE *file;
	char *data;
	long size;

	//printf("Read initialized.");
	file = fopen(inputloc, "rb");
	if(! file) fputs("[ERROR] Unable to open file.",stderr),perror(inputloc),printf("Unable to open file.\n"),exit;
	fseek(file, 0L, SEEK_END);
	size = ftell(file);
	rewind(file);

	data = malloc(1 * size + 1); 
	if(!data) fclose(file),fputs("[ERROR] Failed to allocate memory. Bailing out.",stderr),perror("malloc fail"),printf("[ERROR] Failed to allocate memory.\n"),exit;
	if(1 != fread(data, size, 1, file))
		fclose(file),free(data),fputs("[ERROR] Read Operation from file failed.",stderr),perror("read fail"),printf("[ERROR] Read operation failed\n"),exit;
	fread(data, size, 1, file);
	fclose(file);
	int i;
	//printf("Read:\n");
	//for(i = 0; i <= size; i++) printf("%c",data[i]);
	convert(data, size);
	//write(outputloc,data);
	free(data);
}

void convert(char* data, size_t size){ 
	//int i;
	//printf("Recieved:\n");
	//for(i = 0; i <= size; i++) printf("%c",data[i]);
	//printf("%s",data);
	//long a = 10;
	//long b = 300;
	//delete(a, b, data);
	//printf("Edited:\n");
	//for(i = 0; i <= size; i++) printf("%c",data[i]);
	//printf("%s",data);
	
	//This part is able to extract a value from the file using extract()
	/*char *pattern;
	pattern = malloc(sizeof(data));
	char *delim;
	delim = malloc(sizeof(data));
	char *extractd;
	extractd = malloc(sizeof(data)*strlen(data));
	strcpy(pattern,"desc=\"");
	strcpy(delim,"\"");
	extract(pattern,delim,data,extractd);
	free(pattern);
	free(delim);
	free(extractd);*/
	/*char* insertn;
	insertn = malloc(sizeof(char)*10);
	char temp[] = "\n\nTest\n\n";
	strcpy(insertn,temp);
	insert(insertn,100,data);
	free(insertn);*/
	
	//This part uses replace to fix description in script
	/*char* target;
	char* phrase;
	target = malloc(sizeof(char)*20);
	phrase = malloc(sizeof(char)*40);
	char tmp1[] = "desc=\"";
	char tmp2[] = "description=\"";
	strcpy(target,tmp1);
	strcpy(phrase,tmp2);
	replace(target,phrase,data);
	free(target);
	free(phrase);*/

	//This part was used to test cmdextract()
	/*char* extractpre;
	char* extractpost;
	extractpre = malloc(sizeof(char)*40);
	extractpost = malloc(sizeof(char)*40);
	cmdextract(data,extractpre,extractpost);
	printf("Function name: %s\nFunction command: %s",extractpre,extractpost);
	free(extractpre);
	free(extractpost);*/

	test_progress();
}

void test_progress(){
	size_t num_secs = 0, max_secs = 50;
	printf("%s\n", "");
	char title1[] = "/etc/rc.d/netif";
	char title2[] = "/etc/init.d/netif";
	int spinstore;
	spinstore = 0;
	for ( ; num_secs < max_secs; num_secs++){
		usleep(50000);
		print_progress(title1, title2, num_secs, max_secs, &spinstore);
	}
}

void print_progress(char *title1, char *title2, int count, int max, int *spinstore){ //Remember to convert longs that hold array counts into size_t
	const char prefix[] = " [";
	const char suffix[] = "]     ";
	const size_t prefix_length = sizeof(prefix) - 1;
	const size_t suffix_length = sizeof(suffix) - 1;
	char *buffer = malloc(max + prefix_length + suffix_length + 1);
	size_t i;
	strcpy(buffer, prefix);
	for ( i = 0; i < max; i++ ){
		buffer[prefix_length + i] = i <= count ? '#' : ' '; //Remember to change # to pretty unicode/ascii symbol
	}
	strcpy(&buffer[prefix_length + i], suffix);
	
	char *spin[5];
	spin[0] = "-->  -->  ";
	spin[1] = " -->  --> ";
	spin[2] = "  -->  -->";
	spin[3] = ">  -->  --";
	spin[4] = "->  -->  -";
	int spinmax = 4;
	
	printf("\r\b\b\b\r%s\b\b\b\b\b Converting: %s [%s] %s", buffer, title1, spin[*spinstore], title2);
	fflush(stdout);
	free(buffer);
	if(*spinstore == spinmax) *spinstore = 0;
	else if(*spinstore < spinmax && *spinstore >= 0) *spinstore = *spinstore + 1;
	else printf("[ERROR] Illegal spinner state.\n"), fputs("[ERROR] Illegal spinner state.",stderr), perror("Illegal spinner state"), exit;
}

void delete(size_t a, size_t b, char* data){ //Tested. Works.
	size_t size = strlen(data);
	size_t d = b - a;
	char *buffer;
	buffer = malloc(sizeof(char)*size); 
	int i;
	for(i = 0; i < a; i++){
		buffer[i] = data[i];
	}
	for(i = b; i < size; i++){
		buffer[i - d] = data[i];
	}
	for(i = 0; i < size+1; i++) data[i] = buffer[i];
	free(buffer);
}

void extract(char* pattern, char* delim, char* data, char* extract){ //Tested. Works.
	size_t psz = strlen(pattern);
	size_t desz = strlen(delim);
	size_t dasz = strlen(data);
	char *result1;
	result1 = strstr(data,pattern);
	long l;
	for(l = psz; result1[l]!= delim[0]; l++) extract[l-psz] = result1[l];
	printf("%s",extract);
}

void cmdextract(char* data, char* extractpre, char* extractpost){ //Tested. Works.
	//For the *_cmd="command" values an extra function is needed to extract both the * value and the command values
	char pattern[] = "_cmd=\"";
	char delimpre[] = "\n";
	char delimpost[] = "\"";
	char* ptr;
	ptr = strstr(data,pattern);
	size_t l;
	for(l = 0; ptr[l] != delimpre[0]; l--) extractpre[l * -1] = ptr[l];
	size_t m;
	strrev(extractpre);
	for(m = 0; ptr[m + strlen(pattern)] != delimpost[0]; m++) extractpost[m] = ptr[m + strlen(pattern)];
}

void myinsert(char* insert, size_t pos, char* data){ //Tested. Works.
	char* buffer;
	buffer = malloc(sizeof(char)*strlen(data));
	size_t insize = strlen(insert);
	size_t dsize = strlen(data);
	size_t l;
	for(l = 0; l < pos; l++) buffer[l] = data[l];
	for(l = 0; l < insize; l++) buffer[pos + l] = insert[l];
	for(l = pos; l <= dsize; l++) buffer[l+insize] = data[l];
	strcpy(data,buffer);
	free(buffer);
}

void replace(char target[], char phrase[], char* data){ //Tested. Works.
	char* pos;
	size_t tsize = strlen(target);
	pos = strstr(data,target);
	size_t l;
	delete(0,tsize,pos);
	myinsert(phrase,0,pos);
	printf("%s",data);
}

void mywrite(char outputloc[1000], char* data){ //Tested. Works.
	FILE *fptr;
	fptr = fopen(outputloc, "w");
	fprintf(fptr, data);
	fclose(fptr);
}

char* strrev(char* str) //Reverses a string
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

