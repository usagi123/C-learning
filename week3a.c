/*
File input and output

Copy the content of file fileName1 into the file fileName2
Generate randoms content into a table.csv file
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int copyFile(char *fileName1, char *fileName2);
//create a table on numbers with "n" rows and "columns" columns
void createTableFile(char *dataFileName, int n, int columns);

//command ./week3a test.txt copy_test.txt table1.csv 20 4
int main(int argc, char *argv[]){
    copyFile(argv[1], argv[2]);
    createTableFile(argv[3], atoi(argv[4]), atoi(argv[5]));
};  

//Copy the content of file fileName1 into the file fileName2
//command [originalfile].txt [copy_of_originalfile].txt
int copyFile(char *fileName1, char *fileName2){
    FILE *file1;
    FILE *file2;
    char line[200];

    file1 = fopen(fileName1,"r"); //the source file
    file2 = fopen(fileName2,"w"); //the target file

    while(!feof(file1)){ //while i am not yet at the end of file == !feof
        fgets(line, 200, file1); //get one line from file1
        fprintf(file2, "%s", line); //write the above line into file2
    };

    fclose(file1);
    fclose(file2);
    return 0;
}

//create a table on numbers with "n" rows and "columns" columns
//command [name].csv [row] [col]
void createTableFile(char *dataFileName, int n, int columns){
    FILE *file1;
    int row, col;
    int lower = 0; //each number is in the range [lower..upper]
    int upper = 100;

    file1 = fopen(dataFileName, "w");
    srand(time(NULL)); //randomize the rand generator's seed
    for(row = 0; row < n; row++){ //create a row of numbers
        //for each row, make a number of columns
        for(col = 0; col < columns; col++){
            fprintf(file1, "%4d", lower + rand() % (upper-lower+1));
        }
        fprintf(file1, "\n");
    }
}