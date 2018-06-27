#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
 
//to find gcd
int gcd(int a, int b){
    int temp;
    while(1)
    {
        temp = a%b;
        if(temp==0)
        return b;
        a = b;
        b = temp;
    }
}
 
int main(){
    int p = 151; //prime number 1      
    int q = 73; //prime number 2
    int n=p*q;
    int On = (p-1)*(q-1);        //24 factors:  1, 2, 3, 4, 6, 8, 12, 24

 
    //public key
    //e stands for encrypt, e can be any value except p and q (not a factor of n or On), here I use psuedo random number
    srand(time(NULL));
    // int e = rand()%100;
    int e = 7;
    // while(0){ //while false 
    //     if(e!=p||(e!=q)){ //if randomized e value is not p or q then accept that e value and break out the while loop
    //         break;
    //     }
    //     else{ //else generate e value again
    //         e = rand()%100;
    //     }
    // }   
    int result[n];

    // for(int i = 1; i <= e; i++){
    //     if(e%i == 0){
            
    //     }
    // }
 
    //for checking co-prime which satisfies e>1
    int count;
    while(e<On){
    count = gcd(e,On);
    if(count==1)
        break;
    else
        e++;
    }
 
    //private key
    //d stands for decrypt
    int d;
 
    //k can be any value, here I use pseudo random number with seed
    int k = rand()%100;
 
    //choosing d such that it satisfies d*e = 1 + k * totient
    d = (1 + (k*On))/e;
    printf("\n Public key");
    printf("\n N value: %d", n);
    printf("\n Encrypt value: %d", e);
    printf("\n");
    printf("\n Private key");
    printf("\n N value: %d", n);
    printf("\n Decrypt value: %d", d);
    printf("\n");
    return 0;
}