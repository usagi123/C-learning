#include<stdio.h>
#define ARRAYSIZE 7
#define STACKSIZE 8

static int stack[STACKSIZE];
static int operators[ARRAYSIZE];
void printInt();
int readOperators();
int readInts();
int evaluate();
 
 
int main(int argc, char*argv[]){
  int numInts, numExpectedOperators, numOperators, maxInts, solution;
  maxInts = 8;
  printf("Made it to main");
  numInts =  readInts(stack, maxInts ,argv, argc);
  numExpectedOperators = numInts-1;
  numOperators =  readOperators(operators, numExpectedOperators, argv, argc, numInts);
  if(numInts != -1 ||  numOperators != -1){
    return 0;
  }
  else{
   solution = evaluate(stack, operators, numInts);
   printInt(solution);
  }
}
      int readInts(int stack[], int maxInts, char*argv[], int argc){
    int currIntCount = 0;
    int i, tempInt, expectedInts;
    char temp;
    /*if the number of total arguments entered is even then that means there is a mismatch of integers and operators. B/c numOperators =  numInts-1 */
    if(argc%2 == 0){
      printf("Mismatch in number of integers and operators. Quitting");
      return -1;
    }
    expectedInts = (argc/2)+1;
    for(i=0; i< expectedInts; i++){
      temp = *argv[i];
      tempInt =  atoi(temp);
      if(tempInt == 0  &&  currIntCount != expectedInts){
        printf("Bad input character enountered. Quitting");
        return -1;
      }
      if(currIntCount <= expectedInts){
        stack[i]=tempInt;
        currIntCount++;
      }else{
        printf("Minimum of 1 integer needed. Maximum of 8 integers accepted. Quitting.");
        return -1;
      }
    }
        /*reverse the order so its in stack form */
        int t1, t2, i1, i2;
        i1 = currIntCount-1;
        i2 = 0;
        while(i1 > i2){
        t1 = stack[i1];
        t2 = stack[i2];
        stack[i2] = t1;
        stack[i1] = t2;
        i1--;
        i2++;
        }
        return currIntCount;
      }
      int readOperators(char operators[], int expectedNumOperations, char*argv[],int argc, int indexArgvOperator){
    int currOperatorCount = 0;
    int y;
    char temp2;
    for(y=indexArgvOperator; y<argc;y++){
       temp2 = *argv[y];
       if(atoi(temp2) == 0){
         if(temp2 == 'a'|| temp2 == 'm' || temp2 == 's' || temp2 == 'd'){
        operators[currOperatorCount]=temp2;
        currOperatorCount++;
         }
         else{
           printf("Bad input character encountered. Quitting.");
           return -1;
         }
       }else {
         printf("Bad input character encountered. Quitting.");
         return -1;
       }
    }
    if(currOperatorCount != expectedNumOperations){
      printf("Mismatch in number of integers and operators. Quitting.");
      return -1;
    }
    return currOperatorCount;
      }
      int evaluate(int stack[], char operators[], int numItemsInStack){
    int sCounter = 0;
    int oCounter = 0;
    int a1, secondNum, currOperator;
    a1 = stack[sCounter];
    numItemsInStack--;
    sCounter++;
    while(numItemsInStack > 0){
      secondNum = stack[sCounter];
      currOperator = operators[oCounter];
      oCounter++;
      sCounter++;
      numItemsInStack--;
      if(currOperator == 'a'){
        a1 = a1+secondNum;
      }
      else if(currOperator == 'm'){
        a1 = a1*secondNum;
      }
      else if(currOperator == 's'){
        a1 = a1-secondNum;
      }
      else if(currOperator == 'd'){
        a1 = a1/secondNum;
      }
      else{
        printf("Bad input character encountered. Quitting.");
        return -1;
    }
      return a1;
    }
      }
      void printInt(int intToPrint){
        printf("%d\n", intToPrint);
      }