
/* RMIT VIETNAM UNIVERSITY  - NAM HO NGUYEN HAI (S3548200) -  LAM MINH TUNG (S3598768)
BELOW IS THE SOURCE CODE OF ASSIGNMENT 1 IN PROGRAMMING TECHNIQUE  
THE ASSIGNMENT HAS THREE PARTS: PART A, PART B AND PART C */

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

/* -------- PART A BEGINS FROM HERE ---------------

PART A. Write a function  
  void searchWordTextFile(char *fileName, char *word)  
that prints all the lines of the text file  fileName  that contains the word  word.  
The file that will be used to test your function is biglist.txt, which has 1,000,000 lines.  
The search is NOT case-sensitive.

*/

//Include all neccessary C library
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// define INPUT_FILE and OUTPUT_FILE
#define INPUT_FILE      "biglist.txt"
#define OUTPUT_FILE     "output.txt"

//define function search Word In Text File -- THIS IS PART A
void searchWordTextFile(char *fileName, char *word);

//define function sort Text in Text File - THIS IS PART C
void sortTextFile(int N, char *fileName, char *sortedFileName)  ;

static void sort_a(void *array, unsigned n);
static int cmpr(const void *a, const void *b);

//MAIN function
int main(int argc, char *argv[]) {
//WELCOME MESSAGE
  printf("----------------------------------------------------------------------------------------------------------------- \n");
printf("WELCOME TO OUR PROJECT - THIS IS THE PROJECT FOR ASSIGNMENT 1 IN PROGRAMMING TECHNIQUE - RMIT VIETNAM UNIVERSITY \n");
printf("\n");
printf("THE CONTRIBUTORS OF THIS PROJECT: NAM HO NGUYEN HAI (S3548200) -  LAM MINH TUNG (S3598768) \n");
printf("\n");
printf("PLEASE PRESS ENTER TO CONTINUE \n");
printf("\n");

getchar(); // get Enter key from user

printf("PART A START HERE. PLEASE PRESS ENTER TO CONTINUE WITH PART A \n");
getchar(); // get Enter key from user

// COUNT TIME FUNCTION TO EXECUTE PROGRAM IN MILISECOND -THIS IS  PART B

   clock_t t;  // The C library function clock_t clock returns the number of clock ticks elapsed since the program was launched.
    t = clock(); //the declaration for clock() function.
    searchWordTextFile(argv[1],argv[2]); // THIS IS THE FUNCTION TO SEARCH WORD WITH LINES CONTAINNING THAT WORD -- THIS IS PART A
    t = clock() - t; // time for the program to execute 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    //INSTRUCTION MESSAGE FOR USER
    printf("----------------------------------------------------------------------------- \n");


    //INSTRUCTION MESSAGE FOR USER
    printf("ALL SEARCH RESULT DISPLAYED.  PLEASE PRESS ENTER TO CONTINUE WITH PART B \n");
getchar(); // get Enter key from user

    //INSTRUCTION MESSAGE FOR USER
 printf("------------------------------------------------------------------------------------------ \n");
 printf("PART B START HERE. \n");

 // PRINT THE TIME THE PROGRAM TOOK  TO EXECUTE FOR PART A IN MILISECONDS
    printf("This program took %f seconds to execute \n", time_taken); 


    //INSTRUCTION MESSAGE FOR USER
 printf("----------------------------------------------------------------------------- \n");

    //INSTRUCTION MESSAGE FOR USER
    printf("THE END OF PART B.  PLEASE PRESS ENTER TO CONTINUE WITH PART C \n");
getchar(); // get Enter key from user

    //INSTRUCTION MESSAGE FOR USER
 printf("------------------------------------------------------------------------------------------ \n");
 printf("PART C START HERE. \n");

//THIS IS THE FUNCTION TO SORT CONTENT OF A TEXT FILE -- THIS IS PART C
 sortTextFile(argc,argv[4],argv[5]);

   //INSTRUCTION MESSAGE FOR USER
  printf("------------------------------------------------------------------------------------------ \n");
    printf("THE END OF PART C. \n");
}
 
 
 //FUNCTION SEARCH START HERE - PART A

void searchWordTextFile(char *fileName, char *word){

//CONVERT CONTENT TO UPPERCASE START HERE

       // 1. Open the file Biglist.txt to convert content to uppercase online 
    FILE *inputFile = fopen(INPUT_FILE, "rt");

    // if there is no file has the name user entered - print "ERROR: Cannot open the ile"
    if (NULL == inputFile) {
        printf("ERROR: cannot open the file: %s\n", INPUT_FILE);
      
    }

    // 2. Open another file to write the content of Biglist.txt in uppercase

    FILE *outputFile = fopen(OUTPUT_FILE, "wt");
       // if there is no file has the name user entered - print "ERROR: Cannot open the ile"
    if (NULL == outputFile) {
        printf("ERROR: cannot open the file: %s\n", OUTPUT_FILE);
     
    }

    // 3. Read the content of the input file and Write it in uppercase to the ouput file
    int c;
    while (EOF != (c = fgetc(inputFile))) {

        // 4 . Capitalize and write it to the output file
        fputc(toupper(c), outputFile);
    }

// SEARCH START HERE
      //Define the variables: fp. OUTPUT_FILE, line, string
        FILE *fp;
        fileName=OUTPUT_FILE;
        char line[200];
        char string[1000];
        
         //SCAN THE SEARCHED KEYWORD FROM USER
        printf("Input the word you want to search in the file:\n");
        //CONVERT THE USER INPUT TO UPPERCASE
        word= strupr(gets(string));

        //open the filename (which was written in uppercase above from the content of biglist.txt)
        fp=fopen(fileName,"r");

        // If there is no file matched filename, exit the program
        if(!fp)

        {
                perror("could not find the file");
                exit(0);


        }

        //READ AND PRINT ALL THE LINES CONTAINNING THE USER INPUT WORD ON THE CONSOLE SCRREN 

        while ( fgets ( line, 200, fp ) != NULL ) /* read a line */

        {

                if(strstr(line,word))
                fputs ( line, stdout ); /* write the line */

        }

//CLOSE FILE
        fclose ( fp );


        return;


}

/* ----------- PART C BEGINS HERE ----------

PART C: Write a function  
void sortTextFile(int N, char *fileName, char *sortedFileName)  
that sorts the contents of a text file  fileName  into alphabetical order and creates the output file  sortedFileName.  
N is the number of lines in  fileName. 

*/

//FUNCTION TO SORT CONTENT IN TEXT FILE

void sortTextFile(int N, char *fileName, char *sortedFileName)  {

  //DEFINE ALL VARIABLES: originFile, sortFile, file1, file2
  FILE *originFile;
  FILE *sortFile;
  char file1[1000];
  char file2[1000];
  char line[1000];
  N = 500000;
  char *line_array[N];
  int i = 0;
  int j = 0;
           //SCAN THE FILE NAME WHICH USER WANT TO SORT
        printf("Input the file name you want to sort content in the file (Please choose the txt file only. For example: biglist.txt) :\n");
        //CONVERT THE USER INPUT TO UPPERCASE
        fileName= gets(file1);
 printf("\n");
             //SCAN THE FILE NAME WHICH USER WANT TO WRITE ALL THE SORTED CONTENT
        printf("Input the file name that you want to write all the sorted content which is different from the previous file name (Please choose the txt file only. For example: sortedfile.txt) :\n");
        //CONVERT THE USER INPUT TO UPPERCASE
        sortedFileName= gets(file2);

    // 2. Open another file to write the content from the previous file after sorting out
    sortFile = fopen(sortedFileName, "wt");
       // if there is no file has the name user entered - print "ERROR: Cannot open the ile"
    if (NULL == sortedFileName) {
        printf("ERROR: cannot open the file: %s\n", sortedFileName);
     
    }


 // 1. Open the file to read content  to sort the content
    originFile = fopen(fileName, "rt");
       // if there is no file has the name user entered - print "ERROR: Cannot open the ile"
    if (NULL == fileName) {
        printf("ERROR: cannot open the file: %s\n", fileName);
      
    }
    else{
       // Trim the newline character
       while (fgets(line, sizeof line, originFile) != NULL)
        {
       
            // Stop processing if line_array is full
            if (i < sizeof line_array / sizeof *line_array)
            {
                line_array[i++] = strdup(line);
            }
            else
            {
                break;
            }
    }

    sort_a(line_array, i);
      for (j = 0; j < i; j++)
        {
    
             fputs(line_array[j] , sortFile);
        }
  }



    
   
  
 


//CLOSE FILE
        fclose ( originFile);

        //CLOSE FILE
        fclose ( sortFile);


        return;
}

int cmpr(const void *a, const void *b)
{
    return (strcmp(*(char **)a, *(char **)b));
}
void sort_a(void *array, unsigned n)
{
    qsort(array, n, sizeof(const char *), cmpr);
}