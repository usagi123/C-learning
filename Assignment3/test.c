#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double evaluate (char []);
int precedence(char);
double calculate(char , double , double );
char checknumber(char);

int main(void)
{
    char expression[100];
    double result;

    printf("Enter the Expression: "); scanf("%[^\n]", expression);
    result = evaluate(expression);
    printf("Result = %lf\n", result);
    return 0;
}

double evaluate(char expr[])
{
    double numbers[5]; int numbersi = 0;
    char operators[5]; int operatorsi = 0;
    char numbuffer[16]; int numbufferi = 0;
    char ch; int  i = 0;

    while ((ch = expr[i]) != 0) {
        if (checknumber(ch)) 
        {
            numbuffer[numbufferi++] = ch;
            if (!checknumber(expr[i + 1])) 
            {
                numbuffer[numbufferi] = 0; numbufferi = 0;
                sscanf(numbuffer, "%lf", &numbers[numbersi++]); 
            }
        }
        else
        {
            while ((operatorsi > 0) && (precedence(ch) <= precedence(operators[operatorsi - 1])))
            {
                numbers[numbersi - 2] = calculate(operators[operatorsi - 1], numbers[numbersi - 2], numbers[numbersi - 1]);
                operatorsi--; numbersi--;
            }
            operators[operatorsi++] = ch;          
        }
        i++;
    }
    while (operatorsi > 0) {
        numbers[numbersi - 2] = calculate(operators[operatorsi - 1], numbers[numbersi - 2], numbers[numbersi - 1]);
        operatorsi--; numbersi--;
    }
    return numbers[0];
}

char checknumber(char ch) 
{
    return (('0' <= ch && ch <= '9') || ch == '.');

}
int precedence(char ch)
{
    int precedence;
    switch (ch) 
    {
    case '+':
    case '-':
        precedence = 0;
        break;
    case '*':
    case '/':
        precedence = 1;
        break;
    case '^':
        precedence = 2;
    }
    return precedence;
}

double calculate(char moperator, double num1, double num2) 
{
    double result;
    switch (moperator)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    case '^':
        result = pow(num1, num2);
        break;
    default:
        printf("Invalid Operator\n");
        exit(-1);
    }
    return result;
}