#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void searchWordTextFile(char *fileName, char *word);
void sortTextFile(int N, char *fileName, char *sortedFileName);
static int stringcompare(const void *a, const void *b);
static void sort_array(void *array, unsigned n);


int main(int argc, char *argv[]){
    searchWordTextFile(argv[1], argv[2]); //input argument 1 as input file name and argument 2 as keyword
    sortTextFile(atoi(argv[3]), argv[4], argv[5]); //input argument 3 as the number of lines needs to sort, argument 4 as the input file name and argument 5 as the output file name.
    return 0;
};

void searchWordTextFile(char *fileName, char *word){
    clock_t begin = clock(); //start counting the clock
    FILE *file1;
    char originalKW[200]; //backup original input from user before lower case it
    strcpy(originalKW,word);
    char line[200]; //give it maximum length
    file1 = fopen(fileName, "r"); //open file name
    char *result;
    char string[200];
    int i = 0, j = 0;
    static int count = 0; //counting how many result

    //change all keyword to lower case, loop each character
    for(i = 0; word[i]; i++){
        word[i] = tolower(word[i]);
    }

    while(!feof(file1)){
        fgets(line, 200, file1); //get one line from file
        strcpy(string,line); //copy to another memory to change into lower case in the next step
        //change all copyed result from line to string into lower case to compae
        for(j = 0; j<strlen(string); j++){
            string[j] = tolower(string[j]);
        }
        result = strstr(string, word); //find first occurrance of the substring
        if(result){ //if result not null then print out, null means not contains the keyword
            printf("%s",line); //print out the original format
            count = count + 1;
        }
    }
    fclose(file1);
    // calculate the ending time & detecting OS's compiler
    #ifdef _WIN32 //for windows
    double time_spent = (clock() - begin);
    #else //for unix
    double time_spent = (clock() - begin)/1000;
    #endif
    printf("\nSearch summary:\n");
    if(count==1)    printf("There is %d result of '%s'\n", count, originalKW);   
    else    printf("There are %d results of '%s'\n", count, originalKW);     
    printf("Execution time of searching '%s': %.0f ms\n", originalKW, time_spent);
};

int stringcompare(const void *a, const void *b){ //pointers should not be modified so we use const void
    return (strcmp(*(char **)a, *(char **)b)); //compare characters in string a vs string b
};

void sort_array(void *array, unsigned n){ //can be modified so there is no const void here, just void
    qsort(array, n, sizeof(const char *), stringcompare); //sort an array
};

void sortTextFile(int N, char *fileName, char *sortedFileName){
    clock_t begin = clock();    //start clock
    FILE *originalFile;
    FILE *sortFile;
    char line[200];
    char *line_array[N]; //an array to store how many search lines
    int i = 0, j = 0;
    sortFile = fopen(sortedFileName, "w");
    originalFile = fopen(fileName, "r");
    while(fgets(line, sizeof line, originalFile) != NULL){  //get one line until the end of the file
        if(i < N){  //length of the array //alternative (i < sizeof line_array / sizeof *line_array)
            line_array[i++] = strdup(line); //duplicate line array  
        }
        else break;
    };
    sort_array(line_array, i);

    //print out
    for(j = 0; j < i; j++){
        fputs(line_array[j], sortFile);
    }
    // calculate the ending time & detecting OS's compiler
    #ifdef _WIN32 //for Windows
    double time_spent = (clock() - begin);
    #else
    double time_spent = (clock() - begin)/1000;   //for Unix
    #endif
    printf("\nSort summary:\n");
    printf("Output file name: %s\n", sortedFileName);
    if(N==1) printf("Execution time of sorting %d line: %.0f ms\n", N, time_spent);
    else    printf("Execution time of sorting %d lines: %.0f ms\n", N, time_spent);
};
