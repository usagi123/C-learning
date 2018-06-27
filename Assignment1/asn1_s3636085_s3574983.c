#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


int tolower(int C); //take a character and convert it to lowercase


void searchWordTextFile(char *fileName, char *word); 
void sortTextFile(int N, char *fileName, char *sortedFileName);

int main (int argc, char *argv[]){ //command-line arguments
	 if (argc != 6) {
	 printf("Insufficient number of arguments.\n");
	 exit(0); 
	 }
	searchWordTextFile(argv[1], argv[2]);
	int a = atoi(argv[3]); //convert argument into int
	sortTextFile(a,argv[4],argv[5]);
	
	return 0;
}

void sortTextFile(int N, char *fileName, char *sortedFileName){
	char array[N][50]; //array of N number of strings that have 50 characters max
	FILE *file1;
	FILE *file2;
	char line[200]; //line buffer
	file1 = fopen(fileName,"r"); //open fileName on read mode
	for (int i = 0; i < N; i++){
		fgets(line,200,file1); //get a line from file 1 and put it into line
		strcpy(array[i],line); //copy that line into array[i]
		// printf("%s", array[i]);
	}
	printf("Sorting %s .......... \n", fileName);
	file2 = fopen(sortedFileName, "w"); //open sortedFileName on write mode
	
	//bubblesort
	char swap[100] = {'\0'}; //temporary string to sort
	for(int i = 0; i < (N - 1); i++) {
        for(int j = 0; j < ( N - i - 1);j++ ) {
            if(strcmp(array[j], array[j+1]) > 0) {
                strcpy(swap, array[j]);
                strcpy(array[j], array[j+1]);
                strcpy(array[j+1], swap);
            }
        }
    }
	for (int i = 0; i < N; i++){ //write into file2
		fprintf(file2, "%s", array[i]);
	}
	
	printf("Sort complete \nOutput %s", sortedFileName);
	fclose(file1);
	fclose(file2);
	
}
void searchWordTextFile(char *fileName, char *word){
	int a =  clock(); //time start
	FILE *file1;
	char line[200]; //line buffer
	char *query;
	char s1[200] = "";
	for(int i = 0; word[i]; i++){
		word[i] = tolower(word[i]); //convert to lowercase for comparison
		}
	file1 = fopen(fileName, "r");
	while (!feof(file1)){ //while not at the end of file1
		fgets(line, 200, file1);
		strcpy(s1,line);
		for(int i = 0; line[i]; i++){
		line[i] = tolower(line[i]); //to lowercase
		}
		query = strstr(line,word); //check if a substring is in a string
		if(query){
		printf("%s", s1);
		};
		
	}
	a = clock() - a; // elapsed time
	printf("Time taken: %d ms\n",a);
	fclose(file1);

}