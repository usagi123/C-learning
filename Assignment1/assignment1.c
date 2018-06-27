#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h> //dunno what this lib used for, the compliler asked me to add it

int search(char *fileName, char *keyword);
int sort(char *file, char *sortedfile );

int main(int argc, char *argv[]){
    // search(argv[1], argv[2]); //input argument 1 as fileName and argument 2 as keyword
    sort(argv[1], argv[2]);
    return 0;
};

int search(char *fileName, char *keyword){
    clock_t begin = clock(); //start counting the clock
    FILE *file1;
    char originalKW[200]; //backup original input from user before lower case it
    strcpy(originalKW,keyword);
    char line[200]; //give it maximum length
    file1 = fopen(fileName, "r"); //open file name
    char *result;
    char string[200];

    //change all keyword to lower case, loop each character
    for(int i = 0; keyword[i]; i++){
        keyword[i] = tolower(keyword[i]);
    }

    while(!feof(file1)){
        fgets(line, 200, file1); //get one line from file
        strcpy(string,line); //copy to another memory to change into lower case in the next step
        //change all copyed result from line to string into lower case to compae
        for(int j = 0; j<strlen(string); j++){
            string[j] = tolower(string[j]);
        }
        result = strstr(string, keyword); //find first occurrance of the substring
        if(result){ //if result not null then print out, null means not contains the keyword
            printf("%s",line); //print out the original format
        }
    }
    fclose(file1);
    clock_t end = clock();
    double time_spent = (double)(end - begin)/1000; //time in microseconds divided 1000 into milliseconds
    printf("\nExecution time of searching '%s': %.0f ms\n", originalKW, time_spent);
    return 0;
};

int sort(char *fileName1, char*fileName2){
	clock_t begin = clock();
	char c;
	FILE *orgfile;
	FILE *sortedfile;
	char line[200];
	char string[200];

	
	sortedfile = fopen(fileName2, "w"); // target file
	for (c = 'a'; c <= 'z'; ++c){
		orgfile = fopen(fileName1, "r");	// source file
		while(!feof(orgfile)){
			fgets(line, 200, orgfile);
			strcpy(string, line);
			string[0] = tolower(string[0]);
			if(string[0] == c){
					fprintf( sortedfile,"%s", line );
				}
		}
		fclose(orgfile);

	}

	clock_t end = clock();
    double time_spent = (double)(end - begin)/1000; //time in microseconds divided 1000 into milliseconds
    printf("\nExecution time of sorting: %.0f ms\n", time_spent);
	return 0;
}