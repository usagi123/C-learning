#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void increase(int *p) {  // p is an address
	*p = *p + 1;  // modify the integer
						// whose address is p
}

int main() {
    int *p1;		// p1 is an address, a “pointer”
    int b = 2;
	p1 = &b;
	increase( &b );  // b becomes 3
	increase( p1 );  // b becomes 4
	*p1 += 3;    // b becomes 7
	printf("b==%d, &b==%d, p1==%d, *p1==%d \n",
		b, &b, p1, *p1);

    int A[5];
    int n = 5;
    int *pa = A;
    for(int i = 0; i < n; i++){
        // A[i] = i * 10; //way 1
        *pa = i * 10; //way 2
    }

	return 0;
}
