#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char stack[20];
int top = -1;
void pushconvert(char x){
    stack[++top] = x;
}
 
char popconvert(){
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
 
int priority(char x){
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
}

char input(){

}

int convert(){
    char exp[20];
    char *e, x;
    printf("Enter the expression: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0'){
        if(isalnum(*e)){
            printf("%c",*e);
        }
        else if(*e == '('){
            pushconvert(*e);
        }
        else if(*e == ')'){
            while((x = popconvert()) != '('){
                printf("%c", x);
            }
        }
        else{
            while(priority(stack[top]) >= priority(*e)){
                printf("%c",popconvert());
            }
            pushconvert(*e);
        }
        e++;
    }
    while(top != -1){
        printf("%c",popconvert());
    }
    printf("\n");
    return 0;
}

int main(){
    convert();
    return 0;
}