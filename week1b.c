#include <stdio.h> //stadard IO lib
#include <stdlib.h> //C standard lib

// the fuction prototype - creating lib, saving into another file
void printValues(int a, int b);
int getSum(int a, int b);
int maxTwo(int a, int b);
int maxFour(int a, int b, int c, int d);

int main() {
    int i;
    int j = 5;

    printf("Enter a value: ");
    scanf("%d", &i); // &i is the address of i
    printf("The value you entered is %d \n", i);
    i = i + 1; // same as i++ or i += 1;
    printValues(i,j);
    // printValues(getSum(1,2), getSum(8,9));
    // printValues(maxTwo(8,3), maxTwo(4,10));
    printValues(maxFour(4,3,2,1), maxFour(9,2,7,4));
    return 0; // the program return a value
}

//implementation
void printValues(int a, int b){
    printf("The 2 values are %d and %d \n", a,b);
}

int getSum(int a, int b){
    int c = a + b;
    return c;
}

int maxTwo(int a, int b){
    //1 line version
    // return (a > b ? a : b);

    //short version
    // int c = a > b ? a : b;
    
    //full version
    int c;
    if (a > b){
        c = a;
    } else{
        c = b;
    }
    return c;
}

int maxFour(int a, int b, int c, int d){
    //shorter
    // return maxTwo(maxTwo(a,b),maxTwo(c,d));

    //longer
    // int max;
    // max = a;
    // max = b > max ? b : max;
    // max = c > max ? c : max;
    // max = d > max ? d : max;
    //return max;

    //for loop
    int array[4] = {a, b, c, d}; //assign 4 vars into an array
    int max = array[0]; //assign max value for the first var in array
    printf("Side of %lu \n", sizeof(array)); //debug - size of the array print out
    for(int i = 0; i < sizeof(array)/ sizeof(array[0]); i++){
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
   
}
