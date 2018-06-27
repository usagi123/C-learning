/*
    Linked List and Dynamic Data Structures == ArrayList in Java
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//A struct is like a class but without methods/functions
struct Node { 
    int key;
    int data;
    struct Node *ptr; //a pointer (address) to a Node
};

struct Node *head = NULL; //start with an empty list

void insertFirstElement(int key, int data);
void printList();
void insertLastElement(int key, int data);
void deleteFirstElement();
void deleteLastElement();
void deleteKey(int key); //delete the node with key
void reverseList();
bool isThereNodeWithKey(int key); //returns true if there is a node with a key value


//the last one inserted will be the first one printed out
int main(int argc, char *argv[]){
    insertFirstElement(2,23);
    insertFirstElement(3,12);
    insertFirstElement(1,18);
    printList();
    insertFirstElement(5,7);
    insertFirstElement(4,33);
    printList();
    deleteFirstElement();
    printList();

    return 0;
}

void insertFirstElement(int key, int data){
    struct Node *pnode; //a pointer to a node
    pnode = (struct Node *) malloc(sizeof(struct Node)); //this will allocate memory for a Node and return its address
    pnode->key = key;
    pnode->data = data;
    
    pnode->ptr = head; //the node's pointer is now pointing to whatever the head is pointing to
                //this is same as (*pnode).ptr = head
    head = pnode; //head now points to the new node
}

void deleteFirstElement(){
    //how to de-allowcate the deleted node?
    if(head != NULL){
        head = head->ptr;
    }
    // struct Node *tempNext;
    // tempNext = head->ptr;
    // head = tempNext;
}


void printList(){
    struct Node *current;
    current = head; //current now points to whatever head pointing to
    printf("[ "); //start of the list
    while (current != NULL){
        printf(" (key=%d,data=%d) ", current->key, current->data);
        current = current->ptr; //move current to the next node
    }
    printf(" ]\n"); //end of the list
};