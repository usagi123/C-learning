/*
 RMIT VIETNAM UNIVERSITY  - NAM HO NGUYEN HAI (S3548200) -  LAM MINH TUNG (S3598768)
BELOW IS THE SOURCE CODE OF ASSIGNMENT 3 IN PROGRAMMING TECHNIQUE  
THE ASSIGNMENT HAS TWO PARTS: PART A AND PART B

PART A. (80 points)

The program reads a numerical expression and computes the result.  For example, if the input is "4.5 / 3 + 2*1.5 - 0.5" then the output should be "4".
Each number is positive and can the form "5" or "4.98" or ".345".
The supported operations are addition (+), subtraction (-), multiplication (*) and division (/).
Multiplication and division have the same priority and are done from left to right.
Addition and subtraction have the same priority and are done from left to right.
Multiplication have a higher priority over addition and multiplication.

PART B. (20 points)

Include support for negative numbers, such as "-9.8"
Include support for exponentiation (**), which has a higher priority over multiplication and division.
Include support for parenthesis.  For example, "3 * (9 - 6) / 2".
*/

//Include all neccessary C library
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//define all functions used in this program
void welcome();
void expressioncalulator();
double evaluateexpression (char []);
int oprationorder(char);
double calculating(char , double , double );
char checknumber(char);

//Main function
int main(void)
{
    welcome(); // call welcome function
    expressioncalulator(); //call expressioncalculator function
    
    return 0;
}

//Function welcome
void welcome(){
    //WELCOME MESSAGE
    printf("----------------------------------------------------------------------------------------------------------------- \n");
    printf("WELCOME TO OUR PROJECT - THIS IS THE PROJECT FOR ASSIGNMENT 3 IN PROGRAMMING TECHNIQUE - RMIT VIETNAM UNIVERSITY \n");
    printf("\n");
    printf("THE CONTRIBUTORS OF THIS PROJECT: NAM HO NGUYEN HAI (S3548200) -  LAM MINH TUNG (S3598768) \n");
    printf("\n");
    printf("PLEASE PRESS ENTER TO CONTINUE \n");
    printf("-----------------------------------------------------------------------------------------------------------------");
    getchar(); // get Enter key from user

    return;
}
//expressioncalculator function
void expressioncalulator(){
char expression[100]; //define string expression which can contain 100 characters
    double result; //define result with the data type double
    printf("Enter the Expression: (for operators: + , - , /, * , ^) \n"); scanf("%[^\n]", expression); //print the instruction and scan the input from user into the expression string
    result = evaluateexpression(expression); //use the function evaluateexpression to handle the string expression and put it  into the result
    printf("Result = %lf\n", result); //print the result
    return;
}

//Function evaluateexpression 
double evaluateexpression(char expr[])
{
    //define datatype for number, operator, numbuf, nsi, osi, nbi, i, ch
    double numbers[5]; 
    int nsi = 0;
    char operators[5]; 
    int osi = 0;
    char numbuf[16]; 
    int nbi = 0;
    char ch; 
    int  i = 0;

    while ((ch = expr[i]) != 0) {
        if (checknumber(ch)) 
        {
            numbuf[nbi++] = ch;
            if (!checknumber(expr[i + 1])) 
            {
                numbuf[nbi] = 0; nbi = 0;
                sscanf(numbuf, "%lf", &numbers[nsi++]); 
            }
        }
        else
        {
            while ((osi > 0) && (oprationorder(ch) <= oprationorder(operators[osi - 1])))
            {
                numbers[nsi - 2] = calculating(operators[osi - 1], numbers[nsi - 2], numbers[nsi - 1]);
                osi--; nsi--;
            }
            operators[osi++] = ch;          
        }
        i++;
    }
    while (osi > 0) {
        numbers[nsi - 2] = calculating(operators[osi - 1], numbers[nsi - 2], numbers[nsi - 1]);
        osi--; nsi--;
    }
    return numbers[0];
}

//Function checknumber 
char checknumber(char ch) 
{
    if (('0' <= ch && ch <= '9') || ch == '.') return 1; else return 0; //check if the character is number and then result number in boolean
}
//define the order of operation in an expression
int oprationorder(char ch)
{
    int oprationorder;
    switch (ch) 
    {
    // handle + and - at the final priority   
    case '+':
    case '-':
        oprationorder = 0;
        break;
    // handle * and / at the second priority
    case '*':
    case '/':
        oprationorder = 1;
        break;
    //handle ^ at the first priority    
    case '^':
        oprationorder = 2;
    }
    return oprationorder;
}

//Function calculating
double calculating(char moperator, double num1, double num2) 
{
    double result; //define double data type for result

    //how to handle the operator
    switch (moperator)
    {
    case '+':
        result = num1 + num2; // if the operator is +, then use the addition
        break;
    case '-':
        result = num1 - num2; // if the operator is -. then use the substraction
        break;
    case '*':
        result = num1 * num2; // if the operator is *, then use the multiplication
        break;
    case '/':
        if (num2 !=0){ // if num2 different than 0
        result = num1 / num2; // if the operator is /, then use the devision
         }
         else{ //if num2 equal to 0
         printf("ERRO ! Cannot be divided by ZERO \n"); // print error message
         exit(0); //exit the program
         }
        break;
    case '^':
        result = pow(num1, num2); // if the operator is ^, the use the exponetial (power)
        break;
    default:
        printf("Invalid Operator\n"); // For other operator, print "Invalid Operator"
        exit(0);  //Then exit the program
    }
    return result;
}