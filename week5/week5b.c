/*
    Prog 5-2
    Passing parameters
        Pass by value
        Pass by reference
*/

#include <stdio.h>
#include <stdlib.h>

void swapValue(int a, int b);
void swapReference(int *pa, int *pb);

int main(int argc, char *argv[]) {
    int c = atoi(argv[1]);
    int d = atoi(argv[2]);
    printf("Before swapValue(): c = %d, d = %d \n"
            "   &c = %d, &d = %d \n", c, d, &c, &d);
    swapValue(c, d); //use int
    printf("Before swapReference(): c = %d, d = %d \n"
            "   &c = %d, &d = %d \n", c, d, &c, &d);
    swapReference(&c, &d); //use address
    printf("After swapReference(): c = %d, d = %d \n"
            "   &c = %d, &d = %d \n", c, d, &c, &d);
    return 0;
}

//khong co chuc nang == useless
void swapValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("a = %d, b = %d\n", a, b);
}

//useful, swapRef = swap value ide it
//pa and pb are addresses of int
//*pa and *pb are the ints whoese addresses are pa and pb
void swapReference(int *pa, int *pb) {
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}
