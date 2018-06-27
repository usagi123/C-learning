#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gdc(int a, int b);
int checkCoPrime(); //check co-prime which e>1
int publickey();
int privatekey();

int p = 5; //prime number 1
int q = 7; //prime number 2
int n; //2 prime numbers * together
int On; //that formula
int e; //encrypt
int d; //decrypt
int k; //can be any number
int count;

int main(){
    publickey();
    privatekey();
}

int gdc(int a, int b){
    int temp;
    while(1){
        temp = a%b;
        if(temp==0){
            return b;
        }
        a=b;
        b=temp;
    };
};

int checkCoPrime(){
    while(e<On){
        count = gcd(e,On);
        if(count==1)
            break;
        else
            e++;
    }
}

//generate public key
int publickey(){
    n = p*q;
    On = (p-1)*(q-1); //that formula
    e = 2; //encrypt, can be any number except (p-1) and (q-1)
    printf("\n Public key");
    printf("\n N value: %d", n);
    printf("\n Encrypt value: %d", e);
    printf("\n");
    return 0;
};

int privatekey(){
    k = 1; //can be any
    d = (1 + (k*On))/e;
    printf("\n Private key");
    printf("\n N value: %d", n);
    printf("\n Decrypt value: %d", d);
    printf("\n");
    return 0;
};