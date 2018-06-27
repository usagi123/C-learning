/*
	RMIT Vietnam University
	Assignment 3 Mai Pham Quang Huy - s3618861, Do Quoc Toan - s3652979 
	Below is the source code of assignment 3 in Advance Programming Technique
	This program takes a mathemathical expression and compute the results by converting infix to postfix.
	The assignment has 2 parts:
	A. (80 points)
	The program reads a numerical expression and computes the result.  For example, if the input is "4.5 / 3 + 2*1.5 - 0.5" then the output should be "4".
	Each number is positive and can the form "5" or "4.98" or ".345".
	The supported operations are addition (+), subtraction (-), multiplication (*) and division (/).
	Multiplication and division have the same priority and are done from left to right.
	Addition and subtraction have the same priority and are done from left to right.
	Multiplication have a higher priority over addition and multiplication.
	B. (20 points)
	Include support for negative numbers, such as "-9.8"
	Include support for exponentiation (**), which has a higher priority over multiplication and division.
	Include support for parenthesis.  For example, "3 * (9 - 6) / 2".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Stack structure for converting to postfix
struct postfixStack{
	char data[50];
	int top;
};

//Postfix stack operations
int isEmpty(struct postfixStack *s);
void emptyStack(struct postfixStack* s);
void pushPostfix(struct postfixStack* s, int item);
char popPostfix(struct postfixStack* s);

//check if operator
int isOperator(char e);

//check if operand
int isNumber(char c);

//assign priority to the operators
int priority(char e);

//algorithm to convert infix to postfix expression
void infixToPostfix(char* infix, char * postfix);

char postfix[200][10]; //array of tokens
int lengthPostfix = 0; // how many tokens found?
void printPostfix(); //print the postfix expression

// - is an array of maximum of 200 strings
// - each element stores a token (a string)
// where each token has a max length of 10 chars
// - the bottom of the stack is stack[0]
char stack[200][10]; //stack for evaluation
int top = 0;

void evaluate();
void push(char *token);
double pop();
void printStack();
void coreFunction();

int main(int argc, char *argv[]){
	coreFunction();
}

void coreFunction(){
	int count = 0;
	char in[200] = {0},post[200] = {0}; //initialize infix and postfix
	printf("Enter Mathematical Expression: ");
	fgets(in, sizeof(in), stdin);
		in[strlen(in) - 1] = '\0';
	infixToPostfix(&in[0],&post[0]); //convert to postfix
	char temp[10];
	for(int i = 0; i < strlen(post) - 1; i++){ //add string to postfix expression
		if(isNumber(post[i]) || isOperator(post[i])){
			sprintf(temp, "%c", post[i]);
			strcat(postfix[lengthPostfix], temp);
		}
		if (post[i] == ' '){
			lengthPostfix++;
		}
	}
	printPostfix();
	evaluate();
}

void evaluate(){
	int i;
	char t[20]; // contains our current token
	// make the stack empty
	top = 0;
	printStack();
	// for each token t in the postfix expression
		for (i = 0; i < lengthPostfix + 1; i++) {
		strcpy( t, postfix[i]);
		// if t is a number
		if ((t[0] >= '0' && t[0] <= '9') || t[0] == '.') {
			// push t to the stack
			push(t);
			printf("The token is a number. Pushing to the stack.\n");
			printStack();
		}
		else { 
			// t is an operator token
			// b = pop()
			double b = pop();
			// a = pop()
			double a = pop();
			printf("Token is %s. Pop a=%f and b=%f. \n", t,a,b);
			printStack();
			// c = a t b --> operation
			double c;
			if (t[0] == '+') { c = a + b; }
			if (t[0] == '-') { c = a - b; }
			if (t[0] == '/') { c = a / b; }
			if (t[0] == '*') { c = a * b; }
			if (t[0] == '^') { c = (double)pow((double)a, (double)b); }
			// push the result c
			char temp[20];
			sprintf( temp, "%f", c ); // convert the result c into a string
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

double pop() {
	char temp[20];
	if (top >= 0) { // if the stack is not empty
		top--;
		strcpy(temp,stack[top]);
		return atof(temp);
	}
	else {
		printf("Error: Cannot pop an empty stack.\n");
		return 0;
	}
}

void printStack() {
	int i;
	printf("Stack: [ ");
	for (i = 0; i < top; i++) {
		printf("%s ", stack[i]);
	}
	printf("]\n");
}

void printPostfix() {
	int i;
	printf("Postfix expression is: ");
	for (i = 0; i < lengthPostfix +1; i++) {
		printf("%s ", postfix[i]);
	}
	printf("\n");
}

int isEmpty(struct postfixStack *s){
	return (s->top == -1) ? 1 : 0;
}

void emptyStack(struct postfixStack* s){
	s->top=-1;
}

void pushPostfix(struct postfixStack* s,int item){
	if(s->top == (100-1)){
		printf("\nSTACK FULL");
	}
	else{
		++s->top;
		s->data[s->top]=item;
	}
}

char popPostfix(struct postfixStack* s){
	char a=(char)-1;
	if(!isEmpty(s)){
		a= s->data[s->top];
		--s->top;
	}
	return a;
}

int isOperator(char e){
	if(e == '+' || e == '-' || e == '*' || e == '/' || e == '^')
		return 1;
	else
		return 0;
}

int isNumber(char c) {
  if ((c>='0' && c<='9') || c=='.') {
	return 1;
  }
  return 0;
}

int priority(char e){
	int p = 0;
	if(e == '^'){
		p = 3;
	}
	else if(e == '*' || e == '/'){
		p = 2;
	}
	else{
		if(e == '+' || e == '-'){
		p = 1;
		}	
	}
	return p;
}

void infixToPostfix(char* infix, char * postfix){
	char *i,*p;
	struct postfixStack stack;
	char n1;
	emptyStack(&stack);
	i = &infix[0];
	p = &postfix[0];
	
	while(*i){
		while(*i == ' ' || *i == '\t'){
			i++;
		}
		if(isNumber(*i)){
			while(isNumber(*i)){
				*p = *i;
				p++;
				i++;
				}
				*p = ' ';
				p++;
		}
		if(*i == '('){
			pushPostfix(&stack,*i);
			i++;
		}
		if(*i == ')'){
			n1 = popPostfix(&stack);
			while( n1 != '(' ){
				*p = n1;
				p++;
				*p = ' ';
				p++;
				n1 = popPostfix(&stack);
			}
			i++;
		}
		if(isOperator(*i)){
			if(isEmpty(&stack)){
				pushPostfix(&stack,*i);
			}
			else{
				n1 = popPostfix(&stack);
				while(priority(n1) >= priority(*i)){
					*p = n1;
					p++;
					*p = ' ';
					p++;
					
					n1 = popPostfix(&stack);
				}
				pushPostfix(&stack,n1);
				pushPostfix(&stack,*i);
			}
			i++;
		}
	}
	while(!isEmpty(&stack)){
		n1 = popPostfix(&stack);
		*p = n1;
		p++;
		*p = ' ';
		p++;
	}
	*p = '\0';
}



