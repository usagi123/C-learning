#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//encrypt c^e mod n
int main(){
    double cipher = 15; //position of character into number cipher
    double e = 13; //encrypt number
    double n = 143; //P*Q value
    double m = pow(cipher,e);
    double c = fmod(m,n);
    printf("Encrypted text %f", c);
    printf("\n");
    return 0;
}