#include <stdio.h>
#include <stdlib.h>
#include <time.h> //for setting the seed of the random num generator

int recMult(int a, int b);
int recPower(int a, int b);
int fibRECURSION(int n);
int fibLOOP(int n);
void swap(int *a, int *b);
void makeArray(int n, int *B); //make an array A of random numbers
void printArray(int n, int *A); //print the contents
void quickSort(int *A, int left, int right);
void searchNumber(n,A,x); //find X in the sorted array

//recursive multiplication
int recMult(int a, int b){
    if(b == 0){; //check base case, cannot work if multiply with 0
        printf("Reach the base case, cannot calculate with multiply of 0 \n");
        return 0;
    } else{
        printf("Comptuing recMult(%d, %d)...", a, b-1);
        int c = recMult(a, b-1); //call myself
        printf("Returing a+recMult(a,b-1) == %d\n", a + c);
        return a + c;
    }
}

//recursive exponentiation
int recPower(int a, int b){
    if(b == 0){; //check base case, cannot work if multiply with 0
        printf("Reach the base case, cannot calculate with power of 0 \n");
        return 1;
    } else{
        printf("Comptuing recPower(%d, %d)...", a, b-1);
        int c = recPower(a, b-1); //call myself
        int power = recMult(a,c); //multiply a and c
        printf("Returing a+recPower(a,b-1) == %d\n", power);
        return power;
    }
}

//finding Fibonacci(n)
//recursion way
//f(n) = f(n-1) + f(n-2)
int fibRECURSION(int n){
    if(n<=2){
        return 1;
    } else{
        return fibRECURSION(n-1) + fibRECURSION(n-2);
    }
}

//for loop way
int fibLOOP(int n){
    int fib, n1 = 0, n2 = 1;
    if(n==1 || n==2){ //or n<=2
        // printf("The value of f(",n,") is ", 1);
        return 1;
    } else {
        for(int i = 2; i <=n; i++){ //tested, its doesnt affect the result if you put 0 or 1 or 2 or 3 in there but I believed the performance will increase a tiny if you put there 2
            fib = n1 + n2;
            n1 = n2;
            n2 = fib;
        }
        // printf("The value of f(",n,") is ", fib);
        return fib;
    }
}

//*a the
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//make an array A of random numbers
void makeArray(int n, int *A){
    int i;
    for (i = 0; i < n; i++){
        A[i] =i;
    }
    int j,k;
    srand ( time(NULL)); //set the seed of the rand num generator
    for(i = 0; i < 200; i++){
        j = rand() % n; //j is a random number in 0..n-1
        j = rand() % n; //k is a random number in 0..n-1
        //exhcnage A[j] and A[k]
        swap (&A[j], &A[k]); //note the aperasand & (the address of)
    }
}

//print the contents of array A
void printArray(int n, int *A){
    int i;
    for(i = 0; i < n; i++){
        printf("%3d", A[i]);
    }
    printf("\n");
}

void quickSort(int *A, int left, int right){
    int pivot;
    if(left >= right){ //the sub array is already sorted
        return;
    }
    //partition
    pivot = A[ (left+right)/2 ]; //choose pivot, can be anywhere but for now I choose the middle
    int i = left;
    int j = right;
    while ( i<j ){
        while( A[i] <= pivot ) i++;
        while( A[j] > pivot ) j--;
        swap( &A[i], &A[j] ); 
    }

    quickSort(A, i,j-1); //recursive part; quicksort the left side
    quickSort(A, j+1,i); //
}

int main(int argc, char *argv[]){ //command line param
    //take command line convert it into int
    // printf("argv[0] is %s \n", argv[0]);
    // if (argc < 4){
    //     printf("Insufficicient number of arguments \n");
    //     printf("Syntax: prog a b n \n");
    //     return 0; //exit program
    // }
    // int a = atoi(argv[1]);
    // int b = atoi(argv[2]);
    // int n = atoi(argv[3]);

    //debug mode
    int A[10];
    int n = 10;
    makeArray(n, A);
    printArray(n, A);

    quickSort(A, 0, n-1);
    printArray(n, A);

    // int a = 4;
    // int b = 5;
    // printf("%d * %d = %d \n", a, b, recMult(a, b));
    // printf("%d ^ %d = %d \n", a, b, recPower(a, b));
    // printf("Result %d \n", fibLOOP(n));
    return 0;
}


int infloop(){
    for(int i = 0; i < 1; i--){
        printf("Haha, stay inside this loop forever");
    }
}