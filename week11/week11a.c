/*
Program 11: Evaluating a postfix expression
using a stack. We use Program 6-2 (Binary trees)
for our tree traversal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int left(int i) { return i*2+1; }
int right(int i) { return i*2+2; }
int parent(int i) { return (i-1)/2; }

void pre_order(char *tree, int node);
void in_order(char *tree, int node);
void post_order(char *tree, int node);

// Our postfix expression
char postfix[200][10]; // array of tokens
int lengthPostfix = 0; // how many tokens found?

// Our stack:
// - is an array of maximum of 200 strings
// - each element stores a token (a string)
// where each token has a max length of 10 chars
// - the bottom of the stack is stack[0]
char stack[200][10];
int top = 0;

void push(char *token);
float pop();
void printStack();
void evaluate();

int main(int argc, char *argv[]) {
    char tree[200];
    // strcpy( tree,"+-/*5^423nn41nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn");
    // strcpy( tree,"-+/*69323nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn");
    // strcpy( tree,"+-*+4*512nn23nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn");
    // strcpy( tree,"*-++1/-45nn9273nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn");
    strcpy( tree, "*+312nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn");
    printf("\n Pre-order: ");
    pre_order(tree, 0);
    printf("\n In-order: ");
    in_order(tree, 0);
    printf("\n Post-order: ");
    post_order(tree, 0);
    printf("\n");

    evaluate();
    return 0;
}

// Recursive algorithm for pre-order traversal
// of a binary tree
void pre_order(char *tree, int node) {
    if (tree[node] != 'n') {
        printf("%c",tree[node]);
        pre_order(tree, left(node));
        pre_order(tree, right(node));
    }
}

// Recursive algorithm for in-order traversal
// of a binary tree
void in_order(char *tree, int node) {
    if (tree[node] != 'n') {
        in_order(tree, left(node));
        printf("%c",tree[node]);
        in_order(tree, right(node));
    }
}

// Recursive algorithm for post-order traversal
// of a binary tree. The result is a
// post-fix expression
void post_order(char *tree, int node){
    if (tree[node] != 'n') {
        post_order(tree, left(node));
        post_order(tree, right(node));
        printf("%c",tree[node]); // print the token
        // save the token in the postfix[] array
        sprintf( postfix[lengthPostfix],"%c",tree[node]);
        lengthPostfix++;
    } 
}

//evaluate the postfix expression
void evaluate() {
    int i;
    char t[20]; // contains our current token
    // make the stack empty
    top = 0;
    printStack();
    // for each token t in the postfix expression
    for (i = 0; i < lengthPostfix; i++) {
        strcpy( t, postfix[i]);
        // if t is a number
        if ((t[0] >= '0' && t[0] <= '9') || t[0] == '.') {
            // push(t) to the stack
            push(t);
            printf("The token is ta number. Pushing to the stack... \n");
            printStack();
        }
        else { // t is an operator token
                // b = pop()
                float b = pop();
                // a = pop()
                float a = pop();
                printf("Token is %s. Popping a and b...\n", t );
                printStack();
                // c = a t b --> operation
                float c;
                if (t[0] == '+') { c = a + b; }
                if (t[0] == '-') { c = a - b; }
                if (t[0] == '/') { c = a / b; }
                if (t[0] == '*') { c = a * b; }
                // push(c)
                char temp[20];
                sprintf( temp, "%.5f", c ); // convert the result c into a string
                push(temp);
                printf("c was computed and push to the stack.\n");
                printStack();
            }
        }

    printf("The result is %f \n", pop() );
}


void push(char *token) {
        strcpy( stack[top],token );
        top++;
    }

    float pop() {
        char temp[20];
        if (top >= 0) { // if the stack is not empty
        top--;
        strcpy(temp,stack[top]);
        return atof(temp);
    }
    else {
        printf("Error: Trying to pop an empty stack!!\n");
        return 0;
    }
}

//print the content of the stack
void printStack(){
    int i;
    printf("Stack: [ ");
    for(i = 0; i < top; i++){
        printf("%s ", stack[i]);
    }
    printf("]\n");
}