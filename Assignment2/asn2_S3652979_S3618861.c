/*
    RMIT VIETNAM UNIVERSITY
    ASSIGNMENT 2
    ADD AND REMOVE ELEMENTS WITH DIFFERENT DATA STRUCTURES 
    AUTHORS:
    DO QUOC TOAN - S3652979
    MAI PHAM QUANG HUY - S3618861
    THIS IS THE SOURCE CODE OF ASSIGNMENT 2 IN PROGRAMMING TECHNIQUE  
    THE ASSIGNMENT HAS THREE PARTS: PART A, PART B AND PART C 

    A. Using a doubly-linked list, implement the following data structures and their basic functions:
    Stack
    Queue
    Double-ended Queue

    B. Create a simple menu where you can:
    Print the data structure
    Add an element***
    Remove an element*** 

    ***Note: On the double-ended queue, you can add or remove elements from the front or the rear.

    Menu:
    Print stack
    Pop stack
    Push to stack
    Print queue
    Pop queue
    Push to queue
    Print double-ended queue
    Pop front double-ended queue
    Push front double-ended queue
    Pop back double-ended queue
    Push back double-ended queue
    Print stack singly-linked list
    Pop stack singly-linked list
    Push to stack singly-linked list
    Print queue singly-linked list
    Pop queue singly-linked list
    Push to queue singly-linked list
    Print double-ended queue singly-linked list
    Pop front double-ended queue singly-linked list
    Push front double-ended queue singly-linked list
    Pop back double-ended queue singly-linked list
    Push back double-ended queue singly-linked list


    C. In addition to  A  and  B  above, implement a Stack, Queue and a Double-ended Queue using a singly-linked list.  The menu above should include new options to add/remove elements from the new data structures.
*/

#include <stdio.h>
#include <stdlib.h>

//Define menu and exit functions
void Menu();
void ContinueOrExit();
void DoubleLinkedList();
void SingleLinkedList();

//Define function - Double Linked List - DLL
//Stack
void popStackDLL();
void pushStackDLL(int newData);
void printStackDLL();
//Queue
void popQueueDLL();
void pushQueueDLL(int newData);
void printQueueDLL();
//Double ended queue
void pushFrontDoubleEndedQueueDLL(int newData);
void pushBackDoubleEndedQueueDLL(int newData);
void popFrontDoubleEndedQueueDLL();
void popBackDoubleEndedQueueDLL();
void printDoubleEndedQueueDLL();

//Define function - Single Linked List - SLL
//Stack
void popStackSLL();
void pushStackSLL(int newData);
void printStackSLL();
//Queue
void popQueueSLL();
void pushQueueSLL(int newData);
void printQueueSLL();
//Double ended queue
void pushFrontDoubleEndedQueueSLL(int newData);
void pushBackDoubleEndedQueueSLL(int newData);
void popFrontDoubleEndedQueueSLL();
void popBackDoubleEndedQueueSLL();
void printDoubleEndedQueueSLL();

//Main
int main(int argc, char *argv[]){
    Menu();
    return 0;
}

/*Start of Menu and related functions*/
void Menu(){
    int selection;
    printf("\n1. Double Linked List \n2. Single Linked List \n3. Exit");
    printf("\nYour selection: ");
    scanf("%d", &selection);
    switch(selection){
        case 1: printf("\nSelected Double Linked List"); DoubleLinkedList(); break;
        case 2: printf("\nSelected Single Linked List"); SingleLinkedList(); break;
        case 3: exit(0); break;
        default: printf("\nInvaild selection. Please try again");
    }
    return;
}

void ContinueOrExit(){
    int selection;
    printf("\nDo you wish to continue using or exit?");
    printf("\n1. Go back to Double Linked List \n2. Go back to Single Linked List \n3. Go back to Main Menu \n4. Exit");
    printf("\nYour selection: ");
    scanf("%d", &selection);
    switch(selection){
        case 1: printf("\nSelected Double Linked List"); DoubleLinkedList(); break;
        case 2: printf("\nSelected Single Linked List"); SingleLinkedList(); break; 
        case 3: Menu(); break;
        case 4: exit(0);
        default: printf("\nInvaild selection. Please try again");
    }
    return;
}

//Double Linked List Menu
void DoubleLinkedList(){
    int selection, newData;
    printf("\nDouble Linked List Menu:");
    printf("\n1. Push stack \n2. Pop stack \n3. Print stack \n4. Push queue \n5. Pop queue \n6. Print queue \n7. Push front double-ended queue \n8. Pop front double-ended queue \n9. Push back double-ended queue \n10. Pop back double-ended queue \n11. Print double-ended queue\n12. Go back to Main Menu \n13. Exit");
    printf("\nYour selection: ");
    scanf("%d", &selection);
    switch(selection){
        //Stack functions
        case 1: 
            printf("\nSelected Push stack.");
            printf("\nEnter inserted value: ");
            scanf("%d", &newData);
            pushStackDLL(newData);
            break;
        case 2: 
            printf("\nSelected Pop stack."); 
            popStackDLL(); 
            break;
        case 3: 
            printf("\nSelected Print stack."); 
            printStackDLL(); 
            break;
        //Queue functions
        case 4: 
            printf("\nSelected Push queue.");
            printf("\nEnter inserted value: ");
            scanf("%d", &newData);
            pushQueueDLL(newData);
            break;
        case 5:
            printf("\nSelected Pop queue."); 
            popQueueDLL(); 
            break;
        case 6: 
            printf("\nSelected Print queue.");
            printQueueDLL(); 
            break;
        //Double-ended queue functions
        case 7: 
            printf("\nSelected Push front double-ended queue.");
            printf("\nEnter inserted value: ");
            scanf("%d", &newData);
            pushFrontDoubleEndedQueueDLL(newData);
            break;
        case 8: 
            printf("\nSelected Pop front double-ended queue.");
            popFrontDoubleEndedQueueDLL(); 
            break;
        case 9: 
            printf("\nSelected Push back double-ended queue.");
            printf("\nEnter inserted value: ");
            scanf("%d", &newData);
            pushBackDoubleEndedQueueDLL(newData);
            break;
        case 10: 
            printf("\nSelected Pop back double-ended queue.");
            popBackDoubleEndedQueueDLL(); 
            break;
        case 11: 
            printf("\nSelected Print double-ended queue.");
            printDoubleEndedQueueDLL(); 
            break;
        case 12: Menu(); break;
        case 13: exit(0); break;
    }
}

//Double Linked List Menu
void SingleLinkedList(){
    int selection, newData;
    printf("\nSingle Linked List Menu:");
    printf("\n1. Push stack \n2. Pop stack \n3. Print stack \n4. Push queue \n5. Pop queue \n6. Print queue \n7. Push front double-ended queue \n8. Pop front double-ended queue \n9. Push back double-ended queue \n10. Pop back double-ended queue \n11. Print double-ended queue\n12. Go back to Main Menu \n13. Exit");
    printf("\nYour selection: ");
    scanf("%d", &selection);
    switch(selection){
        //Stack functions
        case 1: 
            printf("\nSelected Push stack.");
            printf("\nEnter inserted value: ");
            scanf("%d", &newData);
            pushStackSLL(newData);
            break;
        case 2: 
            printf("\nSelected Pop stack."); 
            popStackSLL(); 
            break;
        case 3: 
            printf("\nSelected Print stack."); 
            printStackSLL(); 
            break;
        //Queue functions
        case 4: 
            printf("\nSelected Push queue.");
            printf("\nEnter inserted value: ");
            scanf("%d", &newData);
            pushQueueSLL(newData);
            break;
        case 5:
            printf("\nSelected Pop queue."); 
            popQueueSLL(); 
            break;
        case 6: 
            printf("\nSelected Print queue.");
            printQueueSLL(); 
            break;
        //Double-ended queue functions
        case 7: 
            printf("\nSelected Push front double-ended queue.");
            printf("\nEnter inserted value: ");
            scanf("%d", &newData);
            pushFrontDoubleEndedQueueSLL(newData);
            break;
        case 8: 
            printf("\nSelected Pop front double-ended queue.");
            popFrontDoubleEndedQueueSLL(); 
            break;
        case 9: 
            printf("\nSelected Push back double-ended queue.");
            printf("\nEnter inserted value: ");
            scanf("%d", &newData);
            pushBackDoubleEndedQueueSLL(newData);
            break;
        case 10: 
            printf("\nSelected Pop back double-ended queue.");
            popBackDoubleEndedQueueSLL(); 
            break;
        case 11: 
            printf("\nSelected Print double-ended queue.");
            printDoubleEndedQueueSLL(); 
            break;
        case 12: Menu(); break;
        case 13: exit(0); break;
    }
}
/*End of Menu and related functions*/

/*Start of Double Linked List*/
//Stack - Double Linked List
struct stackDLL {
    int data;
    struct stackDLL *prev; 
    struct stackDLL *next; 
};
struct stackDLL *stackDLLHead = NULL;

//Stack - Double Linked List - Push
void pushStackDLL(int newData){
    struct stackDLL *pNew;
   
    pNew = (struct stackDLL *) malloc(sizeof(struct stackDLL));
    pNew->data = newData;
    pNew->next = stackDLLHead;
    if(stackDLLHead != NULL){ 
        stackDLLHead->prev = pNew;
    }
    pNew->prev = NULL;
    stackDLLHead = pNew;

    printf("\nPush Doubly Linked List Stack Finish.");
    ContinueOrExit();
    return;
}

//Stack - Double Linked List - Pop
void popStackDLL(){
    if(stackDLLHead == NULL){
        printf("\nYour stack is empty.");
    }
    else{
        struct stackDLL *temp = stackDLLHead;
        if(temp->prev == temp->next){ 
            stackDLLHead = NULL; 
            free(temp);
        }
        else{
            stackDLLHead = temp->next; 
            stackDLLHead->prev =  NULL; 
            free(temp);
        }
        printf("\nPop successful.");
    }
    ContinueOrExit();
    return;
}

//Stack - Double Linked List - Print
void printStackDLL(){
    struct stackDLL *current;
    current = stackDLLHead;
    if(stackDLLHead == NULL){
        printf("\nYour stack is empty.");
    }
    else{
        printf("\nPrinted Done \nYour stack: ");
        while(current != NULL){ 
            printf("Data = %d; ", current->data); 
            current = current->next; 
        }
        printf("End.\n");

    };
    ContinueOrExit();
    return;
}

//Queue - Double Linked List
struct queueDLL{
    int data;
    struct queueDLL *next; 
    struct queueDLL *prev;
};

struct queueDLL *queueDLLHead = NULL;

//Queue - Double Linked List - Push
void pushQueueDLL(int newData){
    struct queueDLL *qNew;
    qNew = (struct queueDLL*)malloc(sizeof(struct queueDLL));
    qNew->data = newData;
    qNew->next = NULL;
    if(queueDLLHead == NULL){
        qNew->prev = NULL;
        queueDLLHead = qNew;
    }
    else{
        struct queueDLL *temp = queueDLLHead;
        while(temp->next != NULL){ 
            temp = temp->next; 
        }
        temp->next = qNew;
        qNew->prev = temp;
    }
    printf("\nPush Doubly Linked List Queue Finish.\n");
    ContinueOrExit();
    return;
}

//Queue - Double Linked List - Pop
void popQueueDLL(){
    if(queueDLLHead == NULL){
        printf("\nYour queue is empty.");
    }
    else{
        struct queueDLL *temp = queueDLLHead;
        if(temp->prev == temp->next){
            queueDLLHead = NULL;
            free(temp);
        }
        else{
            queueDLLHead = temp->next;
            queueDLLHead->prev = NULL;
            free(temp);
        }
        printf("\nPop successful.");
    }
    ContinueOrExit();
    return;
}

//Queue - Double Linked List - Print
void printQueueDLL(){
    struct queueDLL *current;
    current = queueDLLHead;
    if(queueDLLHead == NULL){
        printf("\nYour queue is empty.");
    }
    else{
        printf("\nPrinted done. \nYour stack: ");
        while(current != NULL){
            printf("Data = %d; ", current->data);
            current = current->next;
        }
        printf("\nEnd.");
    }
    ContinueOrExit();
    return;
}

//Doubled-ended Queue - Double Linked List
struct doubleEndedQueueDLL{
    int data;
    struct doubleEndedQueueDLL *next; 
    struct doubleEndedQueueDLL *prev; 
};

struct doubleEndedQueueDLL *doubleEndedQueueDLLHead = NULL;

//Double-ended Queue - Double Linked List - Push Front
void pushFrontDoubleEndedQueueDLL(int newData){
    struct doubleEndedQueueDLL *dNew;
    dNew = (struct doubleEndedQueueDLL *)malloc(sizeof(struct doubleEndedQueueDLL));
    dNew->data = newData;
    dNew->next = doubleEndedQueueDLLHead;
    if(doubleEndedQueueDLLHead != NULL){
        doubleEndedQueueDLLHead->prev = dNew;
    }
    dNew->prev = NULL;
    doubleEndedQueueDLLHead = dNew;
    printf("\nPush Front Double Ended Queue Finish.");
    ContinueOrExit();
    return;
}

//Double-ended Queue - Double Linked List - Push Back
void pushBackDoubleEndedQueueDLL(int newData){
    struct doubleEndedQueueDLL *newNode;
    newNode = (struct doubleEndedQueueDLL*)malloc(sizeof(struct doubleEndedQueueDLL));
    newNode->data = newData;
    newNode->next = NULL;
    if(doubleEndedQueueDLLHead == NULL){
        newNode->prev = NULL;
        doubleEndedQueueDLLHead = newNode;
    }
    else{
        struct doubleEndedQueueDLL *temp = doubleEndedQueueDLLHead;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("\nPush Back Double Ended Queue Finish.");
    ContinueOrExit();
    return;
}

//Double-ended Queue - Double Linked List - Pop Front
void popFrontDoubleEndedQueueDLL(){
    if(doubleEndedQueueDLLHead == NULL){
        printf("\nYour queue is empty.");
    }
    else{
        struct doubleEndedQueueDLL *temp = doubleEndedQueueDLLHead;
        if(temp->prev == temp->next){
            doubleEndedQueueDLLHead = NULL;
            free(temp);
        }
        else{
            doubleEndedQueueDLLHead = temp->next;
            doubleEndedQueueDLLHead->prev = NULL;
            free(temp);
        }
        printf("\nPop successful.");
    }
    ContinueOrExit();
    return;
}

//Double-ended Queue - Double Linked List - Pop Back
void popBackDoubleEndedQueueDLL(){
    if(doubleEndedQueueDLLHead == NULL){
        printf("\nYour queue is empty.");
    }
    else{
        struct doubleEndedQueueDLL *temp = doubleEndedQueueDLLHead;
        if(temp->prev == temp->next){
            doubleEndedQueueDLLHead = NULL;
            free(temp);
        }
        else{
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->prev->next=NULL;
            free(temp);
        }
        printf("\nPop successful.");
    }
    ContinueOrExit();
    return;
}

//Double-ended Queue - Double Linked List - Print
void printDoubleEndedQueueDLL(){
    struct doubleEndedQueueDLL *current;
    current = doubleEndedQueueDLLHead;
    if(doubleEndedQueueDLLHead == NULL){
        printf("\nYour queue is empty.");
    }
    else{
        printf("\nPrinted done. \nYour queue: ");
        while(current != NULL){
            printf("Data = %d; ", current->data);
            current = current->next;
        }
        printf("\nEnd.");
    }
    ContinueOrExit();
    return;
}
/*End of Double Linked List*/

/*Start of Single Linked List*/
//Stack - Single Linked List

//Stack - Single Linked List
struct stackSLL{
    int data;
    struct stackSLL *ptr; 
};

struct stackSLL *stackSLLHead = NULL;

void popStackSLL(){
    if(stackSLLHead == NULL){
        printf("\nYour stack is empty.");
    }
    else{
        struct stackSLL *temp = stackSLLHead;
        printf("\nPop successful.");
        stackSLLHead = temp->ptr;
        free(temp);
    }
    ContinueOrExit();
    return;
}

void pushStackSLL(int newData){
    struct stackSLL *newNodeSLL;
    newNodeSLL = (struct stackSLL *)malloc(sizeof(struct stackSLL));
    newNodeSLL->data = newData;
    if(stackSLLHead == NULL){
        newNodeSLL->ptr = NULL;
    }
    else{
        newNodeSLL->ptr = stackSLLHead;
    }
    stackSLLHead = newNodeSLL;
    printf("\nPush succesful.");
    ContinueOrExit();
    return;
}

void printStackSLL(){
    if(stackSLLHead == NULL){
        printf("\nYour stack is empty.");
    }
    else{
        struct stackSLL *temp = stackSLLHead;
        printf("\nPrinted done. \nYour stack: ");
        while(temp->ptr != NULL){
            printf("Data = %d; ", temp->data);
            temp = temp->ptr;
        }
        printf("\nEnd.");
    }
    ContinueOrExit();
    return;
}

//Queue - Single Linked List

struct queueSLL{
    int data;
    struct queueSLL *ptr; 
};

struct queueSLL *queueSLLHead = NULL;

void popQueueSLL(){
    if(queueSLLHead == NULL){
        printf("\nYour queue is empty.");
    }
    else{
        struct queueSLL *temp = queueSLLHead;
        printf("\nPop succesful.");
        queueSLLHead = temp->ptr;
        free(temp);
    }
    ContinueOrExit();
    return;
}

void pushQueueSLL(int newData){
    struct queueSLL *newNodeSLL;
    newNodeSLL = (struct queueSLL *)malloc(sizeof(struct queueSLL));
    newNodeSLL->data = newData;
    newNodeSLL->ptr = NULL;
    if(queueSLLHead == NULL){
        queueSLLHead = newNodeSLL;
    }
    else{
        struct queueSLL *temp = queueSLLHead;
        while(temp->ptr != NULL){
            temp = temp->ptr;
            temp->ptr = newNodeSLL;
        }
    }
    printf("\nPush successful.");
    ContinueOrExit();
    return;
}

void printQueueSLL(){
    if(queueSLLHead == NULL){
        printf("\nYour queue is empty.");
    }
    else{
        struct queueSLL *temp = queueSLLHead;
        printf("\nPrinted done. \nYour queue: ");
        while(temp->ptr != NULL){
            printf("Data = %d; ", temp->data);
            temp = temp->ptr;
        }
        printf("\nEnd");
    }
    ContinueOrExit();
    return;
}

//Double-ended Queue - Single Linked List

struct doubleEndedQueueSLL{
    int data;
    struct doubleEndedQueueSLL *ptr; 
};

struct doubleEndedQueueSLL * doubleEndedQueueSLLHead = NULL;

void pushFrontDoubleEndedQueueSLL(int newData){
    struct doubleEndedQueueSLL *newNodeSLL;
    newNodeSLL = (struct doubleEndedQueueSLL *)malloc(sizeof(struct doubleEndedQueueSLL));
    newNodeSLL->data = newData;
    if(doubleEndedQueueSLLHead == NULL){
        newNodeSLL->ptr = NULL;
    }
    else{
        newNodeSLL->ptr = doubleEndedQueueSLLHead;
    }
    doubleEndedQueueSLLHead = newNodeSLL;
    printf("\nPush Front succesful.");
    ContinueOrExit();
    return;
}

void pushBackDoubleEndedQueueSLL(int newData){
    struct doubleEndedQueueSLL *newNodeSLL;
    newNodeSLL = (struct doubleEndedQueueSLL *)malloc(sizeof(struct doubleEndedQueueSLL));
    newNodeSLL->data = newData;
    newNodeSLL->ptr = NULL;
    if(doubleEndedQueueSLLHead == NULL){
        doubleEndedQueueSLLHead = newNodeSLL;
    }
    else{
        struct doubleEndedQueueSLL *temp = doubleEndedQueueSLLHead;
        while(temp->ptr != NULL){
            temp = temp->ptr;
            temp->ptr = newNodeSLL;
        }
    }
    ContinueOrExit();
    return;
}

void popFrontDoubleEndedQueueSLL(){
    if(doubleEndedQueueSLLHead == NULL){
        printf("\nYour queue is empty.");
    }
    else{
        struct doubleEndedQueueSLL *temp = doubleEndedQueueSLLHead;
        printf("\nPop successful.");
        doubleEndedQueueSLLHead = temp->ptr;
        free(temp);
    }
    ContinueOrExit();
    return;
}

void popBackDoubleEndedQueueSLL(){
    if(doubleEndedQueueSLLHead == NULL){
        printf("\nYour queue is empty.");
    }
    else{
        struct doubleEndedQueueSLL *temp1 = doubleEndedQueueSLLHead, *temp2;
        if(doubleEndedQueueSLLHead->ptr == NULL){
            doubleEndedQueueSLLHead = NULL;
        }
        else{
            while(temp1->ptr != NULL){
                temp2 = temp1;
                temp1 = temp1->ptr;
            }
            temp2->ptr = NULL;
        }
        printf("\nPop successful.");
        free(temp1);
    }
    ContinueOrExit();
    return;
}

void printDoubleEndedQueueSLL(){
    if(doubleEndedQueueSLLHead == NULL){
        printf("\nYour queue is empty.");
    }
    else{
        struct doubleEndedQueueSLL *temp = doubleEndedQueueSLLHead;
        printf("\nPrinted done. \nYour queue: ");
        while(temp->ptr != NULL){
            printf("Data = %d; ", temp->data);
            temp = temp->ptr;
        }
        printf("\nEnd.");
    }
    ContinueOrExit();
    return;
}

/*Start of Single Linked List*/
