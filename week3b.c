#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    char *s1 = "her name is Thao";
    char s2[50] = " I study at RMIT";
    char *s4 = "Hello Thao";

    printf("s1= %d, s2= %d, s4=! %d, s1= %s, s2= %s, s4= %s\n", //%d is an address, %s is the content of that address
    s1, s2, s4, s1, s2, s4);

    strcpy(s2, s1); //copy into new address in memory
    printf("s1= %d, s2= %d, s4=! %d, s1= %s, s2= %s, s4= %s\n", //%d is an address, %s is the content of that address
    s1, s2, s4, s1, s2, s4);

    s4 = s2; //change address, no new content added into new memory, s4 and s2 is the same
    printf("s1= %d, s2= %d, s4=! %d, s1= %s, s2= %s, s4= %s\n", //%d is an address, %s is the content of that address
    s1, s2, s4, s1, s2, s4);

    int b,n; //b and n are integers
    int *p1; //p1 is an address, a "pointer"
    int *p2; //p2 is also an address
    b = 12; 
    n = 5;
    p1 = &b; // p1 contains the address of b or you can say “p1 points to b”
    p2 = &n; //p2 points to n
    p2 = p1; //now both p1 and 2 points to b
    *p1 = 20; //assign the value 20 to the integer that p1 is pointing to
    p1 = &n; //p1 is now points to n
    printf("b==%d, n==%d, p1==%d, p2==%d, \n", b,n,p1,p2);
    printf("&b==%d, &n = %d, *p1==%d, *p2==%d \n", &b,&n,*p1,*p2);

    return 0;
}