/*
    Header file of the singly linked list
*/

//A struct is like a class but without methods/functuions
struct SingleLinkNode{
    int key;
    int data;
    struct SingleLinkNode *next; //a pointer (address) to the Node
};

void insertFirsteElement_SLL(struct SingleLinkNode **head, int key, int data);
void printList_SLL(struct SingleLinkNode *head);
// int lengthList();
// void deleteThisNode(struct Node *pDelete);
// void insertAfter(int key, int data, struct Node *current); 
// void insertBefore(int key, int data, struct Node *current); 
