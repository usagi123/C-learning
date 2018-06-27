#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void insertFirsteElement_SLL(struct SingleLinkNode **head, int key, int data){
    struct SingleLinkNode *pnode;
    //create our new Node, pNew will point to it
    pnode = (struct SingleLinkNode *) malloc(sizeof(struct SingleLinkNode));
    pnode->key = key;
    pnode->data = data;

    pnode->next = *head;
    *head = pnode;
};

void printList_SLL(){
    struct Node *current;
    current = head; //current now points to the head of the list
    printf("List: ");
    while(current!=NULL){ //not yet at the end
        printf("(Key=%d, Data=%d) ", current->key, current->data);
        current = current->next; //move to the next node
    }
    printf("End\n");
}