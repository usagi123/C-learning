/*
     Program 4-2
     Doubly Linked Lists
     By Vlad
*/

#include <stdio.h>
#include <stdlib.h>

//A struct is like a class but without methods/functuions
struct Node{
    int key;
    int data;
    struct Node *prev; //a pointer (address) to the Node
    struct Node *next; //a pointer (address) to the Node
};

struct Node *head = NULL;  //start with an empty list

void insertFirsteElement(int key, int data);
void printList();
int lengthList();
void deleteThisNode(struct Node *pDelete);
void insertAfter(int key, int data, struct Node *current); 
void insertBefore(int key, int data, struct Node *current); 

int main(int argc, char *argv[]){
    head = NULL;
    insertFirsteElement(1,31);
    printList();
    insertFirsteElement(3,6);
    printList();
    insertFirsteElement(2,12);
    printList();
    insertFirsteElement(4,21);
    printList();
    return 0;
};

void insertFirsteElement(int newKey, int newData){
    struct Node *pNew;
    //create our new Node, pNew will point to it
    pNew = (struct Node *) malloc(sizeof(struct Node));
    pNew->key = newKey;
    pNew->data = newData;

    pNew->next = head;
    if(head!=NULL){ //if the list is not empty
        head->prev = pNew;
    }
    pNew->prev = NULL;
    head = pNew;
};

void printList(){
    struct Node *current;
    current = head; //current now points to the head of the list
    printf("List: ");
    while(current!=NULL){ //not yet at the end
        printf("(Key=%d, Data=%d) ", current->key, current->data);
        current = current->next; //move to the next node
    }
    printf("End\n");
}

int lengthList(){
    return 0;
};
void deleteThisNode(struct Node *pDelete){

};
void insertAfter(int key, int data, struct Node *current){

};
void insertBefore(int key, int data, struct Node *current){

};
