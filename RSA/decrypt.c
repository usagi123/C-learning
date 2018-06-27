#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//decrypt c^d mod n
int main(){
    double t = 10; //encrypted content
    double d = 37; //decrypt number
    double n = 35; //P*Q value
    double m = pow(t,d);
    double data = fmod(m,n);
    printf("Decrypted data %f", data);
    printf("\n");
    return 0;
}