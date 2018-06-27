/*
 RMIT VIETNAM UNIVERSITY  - NAM HO NGUYEN HAI (S3548200) -  LAM MINH TUNG (S3598768)
BELOW IS THE SOURCE CODE OF ASSIGNMENT 2 IN PROGRAMMING TECHNIQUE  
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

#include<stdio.h>
#include<stdlib.h>

//Define function Menu

void Menu();

//Define Continue or Exit Menu 
void ContinueorExit();
//Define Function - Double Linked List
void DoubleLinkedList();
void DoubleLinkStackPrint();
void DoubleLinkStackPop();
void DoubleLinkStackPush(int value);
void DoubleLinkQueuePrint();
void DoubleLinkQueuePush(int value);
void DoubleLinkQueuePop();
void DoubleLinkDoubleEndedQueuePrint();
void DoubleLinkDoubleEndedQueuePopFront();
void DoubleLinkDoubleEndedQueuePopBack();
void DoubleLinkDoubleEndedQueuePushFront(int value);
void DoubleLinkDoubleEndedQueuePushBack(int value);

//Define Function - Single Linked List
void SingleLinkedList();
void SingleLinkStackPrint();
void SingleLinkStackPop();
void SingleLinkStackPush(int value);
void SingleLinkQueuePrint();
void SingleLinkQueuePush(int value);
void SingleLinkQueuePop();
void SingleLinkDoubleEndedQueuePrint();
void SingleLinkDoubleEndedQueuePopFront();
void SingleLinkDoubleEndedQueuePopBack();
void SingleLinkDoubleEndedQueuePushFront(int value);
void SingleLinkDoubleEndedQueuePushBack(int value);

// Define struct Doubly Linked Stack 
struct DoublyLinkedStack {
	 int data;
	 struct DoublyLinkedStack *next; // a pointer (address) to a Doubly Linked Stack 
 	 struct DoublyLinkedStack *prev; // a pointer (address) to a Doubly Linked Stack

};

struct DoublyLinkedStack *StackHead = NULL; // we start with an empty list

// Define struct Doubly Linked Queue 
struct DoublyLinkedQueue {
 int data;
 struct DoublyLinkedQueue *next; // a pointer (address) to a Doubly Linked Queue
 struct DoublyLinkedQueue *prev; // a pointer (address) to a Doubly Linked Queue
};

struct DoublyLinkedQueue *QueueHead = NULL; // we start with an empty list

// Define struct Doubly Linked Double Ended Queue
struct DoublyLinkedDoubleEndedQueue {
 int data;
 struct DoublyLinkedDoubleEndedQueue *next; // a pointer (address) to a Doubly Linked Double Ended Queue
 struct DoublyLinkedDoubleEndedQueue *prev; // a pointer (address) to a Doubly Linked Double Ended Queue
};
struct DoublyLinkedDoubleEndedQueue *DoubleEndedQueueHead = NULL; // we start with an empty list

// Define struct Singly Linked Stack 
struct SinglyLinkedStack {
 int data;
 struct SinglyLinkedStack *next; // a pointer (address) to a Singly Linked Stack 
};
struct SinglyLinkedStack *SinglyStackHead = NULL; // we start with an empty list

// Define struct Singly Linked Queue 
struct SinglyLinkedQueue {
 int data;
 struct SinglyLinkedQueue *next; // a pointer (address) to a Singly Linked Queue
};
struct SinglyLinkedQueue *SinglyQueueHead = NULL; // we start with an empty list

// Define struct Singly Linked Double Ended Queue
struct SinglyLinkedDoubleEndedQueue {
 int data;
 struct SinglyLinkedDoubleEndedQueue *next; // a pointer (address) to a Singly Linked Double Ended Queue
};
struct SinglyLinkedDoubleEndedQueue *SinglyDoubleEndedQueueHead = NULL; // we start with an empty list

//MAIN FUNCTION
int main(int argc, char *argv[])
{
	//WELCOME MESSAGE
	printf("----------------------------------------------------------------------------------------------------------------- \n");
	printf("WELCOME TO OUR PROJECT - THIS IS THE PROJECT FOR ASSIGNMENT 2 IN PROGRAMMING TECHNIQUE - RMIT VIETNAM UNIVERSITY \n");
	printf("\n");
	printf("THE CONTRIBUTORS OF THIS PROJECT: NAM HO NGUYEN HAI (S3548200) -  LAM MINH TUNG (S3598768) \n");
	printf("\n");
	printf("PLEASE PRESS ENTER TO CONTINUE \n");
	printf("-----------------------------------------------------------------------------------------------------------------");
	getchar(); // get Enter key from user

// Display Main Menu 
 	 Menu();

 	 return 0;
}

//Main Menu Function

void Menu(){
 int choice;

   
      printf("\n******PROGRAM MENU - Choose the option below which you want to work with:******\n");
      printf(" 0. Exit Program \n 1. Doubly Linked List \n 2. Singly Linked List \n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
      	 case 0: exit(0); break;
		 case 1: DoubleLinkedList(); break;
		 case 2: SingleLinkedList(); break;
		 default: printf("\nWrong selection!!! Please try again!!!\n"); Menu();
      }
   

     return;	

}

//Continue or Exit Menu

void ContinueorExit(){
	int choice;
 	  printf("\n*********** Do you want to Continue with the program or Exit ? ************ \n ");
      printf("0. Exit Program \n 1. Go back to Main Menu \n 2. Go to Doubly Linked List Menu \n 3. Go to Singly Linked List Menu \n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
      	 case 0: exit(0); break;
      	 case 1: Menu(); break;
		 case 2: DoubleLinkedList(); break;
		 case 3: SingleLinkedList(); break;
		 default: printf("\nWrong selection!!! Please try again!!!\n"); ContinueorExit();
      }
	return;
}

//Double Linked List Menu 
void DoubleLinkedList(){
 	int choice, newData;

      printf("\n****** Doubly Linked List Menu ******\n");
      printf(" 0. Exit Program \n 1. Go back to Main Menu \n 2. Print stack \n 3. Push to stack \n 4. Pop stack \n 5. Print queue \n 6. Push to queue \n 7. Pop queue \n 8. Print double-ended queue \n 9. Push front double-ended queue \n 10. Pop front double-ended queue \n 11. Push back double-ended queue \n 12. Pop back double-ended queue \n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
      	 case 0: exit(0); break;
      	 case 1: Menu(); break;
		 case 2: DoubleLinkStackPrint(); break;
		 case 3: printf("Enter the value to be insert: ");
				 scanf("%d", &newData);
				 DoubleLinkStackPush(newData); 
				 break;
		 case 4: DoubleLinkStackPop(); break;
		 case 5: DoubleLinkQueuePrint(); break;
		 case 6: 
		 		 printf("Enter the value to be insert: ");
				 scanf("%d", &newData);
		 		 DoubleLinkQueuePush(newData); 
		 		 break;
		 case 7: DoubleLinkQueuePop(); break;
		 case 8: DoubleLinkDoubleEndedQueuePrint(); break;
		 case 9: printf("Enter the value to be insert: ");
				  scanf("%d", &newData);
		 		  DoubleLinkDoubleEndedQueuePushFront(newData); 
		 		  break;
		 case 10: DoubleLinkDoubleEndedQueuePopFront(); break;
	 	 case 11: printf("Enter the value to be insert: ");
				  scanf("%d", &newData);
		 		  DoubleLinkDoubleEndedQueuePushBack(newData); break;
		  case 12: DoubleLinkDoubleEndedQueuePopBack(); break;
		 default: printf("\nWrong selection!!! Please try again!!!\n"); DoubleLinkedList();
      }

      
   

   return;
}

// Single Linked List Menu 
void SingleLinkedList(){
 	int choice, newData;

   
      printf("\n****** Singly Linked List Menu ******\n");
      printf(" 0. Exit Program \n 1. Go back to Main Menu \n 2. Print stack \n 3. Push to stack \n 4. Pop stack  \n 5. Print queue \n 6. Push to queue \n 7. Pop queue \n 8. Print double-ended queue \n 9. Push front double-ended queue \n 10. Pop front double-ended queue \n 11. Push back double-ended queue \n 12. Pop back double-ended queue \n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
      	 case 0: exit(0); break;
      	 case 1: Menu(); break;
		 case 2: SingleLinkStackPrint(); break;
		 case 3: printf("Enter the value to be insert: ");
				 scanf("%d", &newData);
		 		 SingleLinkStackPush(newData); 
		 		 break;
		 case 4: SingleLinkStackPop(); break;
		 case 5: SingleLinkQueuePrint(); break;
		 case 6: printf("Enter the value to be insert: ");
				 scanf("%d", &newData);
		 		 SingleLinkQueuePush(newData); break;
		 case 7: SingleLinkQueuePop(); break;
		 case 8: SingleLinkDoubleEndedQueuePrint(); break;
		 case 9: printf("Enter the value to be insert: ");
				 scanf("%d", &newData);
		 		 SingleLinkDoubleEndedQueuePushFront(newData); 
		 		 break;
		 case 10: SingleLinkDoubleEndedQueuePopFront(); break;
		 case 11: printf("Enter the value to be insert: ");
				  scanf("%d", &newData);
		 		  SingleLinkDoubleEndedQueuePushBack(newData); 
		 		  break;
		 case 12: SingleLinkDoubleEndedQueuePopBack(); break;
		 
		 default: printf("\nWrong selection!!! Please try again!!!\n"); SingleLinkedList();
      }


   

     return;
}


//DOUBLY LINKED LIST - Stack , Queue , Double Ended Queue ****START HERE

//Double Linked List - Stack Print
void DoubleLinkStackPrint(){
 struct DoublyLinkedStack *current;
 current = StackHead;
 if(StackHead == NULL)
      printf(" \n***** Printing Stack Done !!! \n Your Stack is Empty!!! \n");
   else
   {
 printf("\n***** Printing Stack Done !!! \n Your Stack: ");
 while (current != NULL) { // not yet at the end
 printf(" %d -->", current->data);
 current = current->next; // point to the next Node
 }
  printf(" End\n");
}

	ContinueorExit();

	return;
};


//Double Linked List - Stack Push
void DoubleLinkStackPush(int value){
	
 struct DoublyLinkedStack *pNew;
 // create our new Node, pNew will point to it
 pNew = (struct DoublyLinkedStack *) malloc(sizeof(struct DoublyLinkedStack));
 pNew->data = value;
 
 pNew->next = StackHead; // #1
 if (StackHead != NULL) { // if the list is not empty
 StackHead->prev = pNew; // #2
 }
 pNew->prev = NULL; // #3
StackHead = pNew; // #4

	printf("\nPUSH TO STACK DONE !!! \n");

	ContinueorExit();

	return;
};

//Double Linked List - Stack Pop
void DoubleLinkStackPop(){
if(StackHead == NULL)
      printf("Your Stack is Empty!!! Deletion is not possible!!!");
   else
   {
      struct DoublyLinkedStack *temp = StackHead;
      if(temp -> prev == temp -> next)
      {
         StackHead = NULL;
         free(temp);
      }
      else{
         StackHead = temp -> next;
         StackHead -> prev = NULL;
         free(temp);
      }
      printf("\n Deletion Successful.");
   }

	ContinueorExit();

	return;
};

//Double Linked List - Queue Print
void DoubleLinkQueuePrint(){

struct DoublyLinkedQueue *current;
 current = QueueHead;
 if(QueueHead == NULL)
      printf(" \n***** Printing Queue Done !!! \n Your Queue is Empty!!! \n");
   else
   {
 printf("\n***** Printing Queue Done !!! \n Your Queue: ");
 while (current != NULL) { // not yet at the end
 printf(" %d -->", current->data);
 current = current->next; // point to the next Node
 }
  printf(" End\n");
}

	ContinueorExit();

	return;

};

//Double Linked List - Queue Push
void DoubleLinkQueuePush(int value){
	struct DoublyLinkedQueue *newNode;
   newNode = (struct DoublyLinkedQueue*)malloc(sizeof(struct DoublyLinkedQueue));
   newNode -> data = value;
   newNode -> next = NULL;
   if(QueueHead == NULL)
   {
      newNode -> prev = NULL;
      QueueHead = newNode;
   }
   else
   {
      struct DoublyLinkedQueue *temp = QueueHead;
      while(temp -> next != NULL)
         temp = temp -> next;
      temp -> next = newNode;
      newNode -> prev = temp;
   }
   printf("\nInsertion success!!!");   

	ContinueorExit();

	return;
};

//Double Linked List - Queue Pop
void DoubleLinkQueuePop(){

if(QueueHead == NULL)
      printf("Your Queue is Empty!!! Deletion is not possible!!!");
   else
   {
      struct DoublyLinkedQueue *temp = QueueHead;
      if(temp -> prev == temp -> next)
      {
         QueueHead = NULL;
         free(temp);
      }
      else{
         QueueHead = temp -> next;
         QueueHead -> prev = NULL;
         free(temp);
      }
      printf("\nDeletion Successfull.");
   }

	ContinueorExit();

	return;
};

//Double Linked List - Double Ended Queue Print
void DoubleLinkDoubleEndedQueuePrint(){

	struct DoublyLinkedDoubleEndedQueue *current;
	 current = DoubleEndedQueueHead;
	 if(DoubleEndedQueueHead == NULL)
	      printf(" \n***** Printing Double Ended Queue Done !!! \n Your Double Ended Queue is Empty!!! \n");
	   else
	   {
	 printf("\n***** Printing Double Ended Queue Done !!! \n Your Double Ended Queue: ");
	 while (current != NULL) { // not yet at the end
	 printf(" %d -->", current->data);
	 current = current->next; // point to the next Node
	 }
	  printf(" End\n");
	}

	ContinueorExit();

	return;
};

//Double Linked List - Double Ended Queue Pop Front
void DoubleLinkDoubleEndedQueuePopFront(){
if(DoubleEndedQueueHead == NULL)
      printf("Your Double Ended Queue is Empty!!! Deletion is not possible!!!");
   else
   {
      struct DoublyLinkedDoubleEndedQueue *temp = DoubleEndedQueueHead;
      if(temp -> prev == temp -> next)
      {
         DoubleEndedQueueHead = NULL;
         free(temp);
      }
      else{
         DoubleEndedQueueHead = temp -> next;
         DoubleEndedQueueHead -> prev = NULL;
         free(temp);
      }
      printf("\nDeletion Successful!!!");
   }

	ContinueorExit();

	return;
};

//Double Linked List - Double Ended Queue Pop Back 
void DoubleLinkDoubleEndedQueuePopBack(){
   if(DoubleEndedQueueHead == NULL)
      printf("Your Double Ended Queue is Empty!!! Deletion not possible!!!");
   else
   {
      struct DoublyLinkedDoubleEndedQueue *temp = DoubleEndedQueueHead;
      if(temp -> prev == temp -> next)
      {
         DoubleEndedQueueHead = NULL;
         free(temp);
      }
      else{
         while(temp -> next != NULL)
            temp = temp -> next;
         temp -> prev -> next = NULL;
         free(temp);
      }
      printf("\n Deletion Successfull.");	
}
	ContinueorExit();

	return;
};


//Double Linked List - Double Ended Queue Push Front
void DoubleLinkDoubleEndedQueuePushFront(int value){
	struct DoublyLinkedDoubleEndedQueue *pNew;
	 // create our new Node, pNew will point to it
	 pNew = (struct DoublyLinkedDoubleEndedQueue *) malloc(sizeof(struct DoublyLinkedDoubleEndedQueue));
	 pNew->data = value;
	 
	 pNew->next = DoubleEndedQueueHead; // #1
	 if (DoubleEndedQueueHead != NULL) { // if the list is not empty
	 DoubleEndedQueueHead->prev = pNew; // #2
	 }
	 pNew->prev = NULL; // #3
	DoubleEndedQueueHead = pNew; // #4

	printf("\nPUSH TO DOUBLE ENDED QUEUE DONE !!! \n");

	ContinueorExit();

	return;
};

//Double Linked List - Double Ended Queue Push Back 
void DoubleLinkDoubleEndedQueuePushBack(int value){
	struct DoublyLinkedDoubleEndedQueue *newNode;
   newNode = (struct DoublyLinkedDoubleEndedQueue*)malloc(sizeof(struct DoublyLinkedDoubleEndedQueue));
   newNode -> data = value;
   newNode -> next = NULL;
   if(DoubleEndedQueueHead == NULL)
   {
      newNode -> prev = NULL;
      DoubleEndedQueueHead = newNode;
   }
   else
   {
      struct DoublyLinkedDoubleEndedQueue *temp = DoubleEndedQueueHead;
      while(temp -> next != NULL)
         temp = temp -> next;
      temp -> next = newNode;
      newNode -> prev = temp;
   }
   printf("\nInsertion success!!!");   

	ContinueorExit();

	return;
};


//DOUBLY LINKED LIST - Stack , Queue , Double Ended Queue ****END HERE

//---------------------------------------------------------------------

//SINGLY LINKED LIST - STACK , QUEUE, DOUBLE ENDED QUEUE *** START HERE

//Singly Linked List Stack Print
void SingleLinkStackPrint(){
if(SinglyStackHead == NULL)
      printf("\n**********Printing Stack Done !!! Your Stack is Empty!!!\n");
   else{
      struct SinglyLinkedStack *temp = SinglyStackHead;
      printf("\n**********Printing Stack Done !!! Your Stack: ");
      while(temp->next != NULL){
	 printf("%d--->",temp->data);
	 temp = temp -> next;
      }
      printf("%d--->END \n",temp->data);
   }
	ContinueorExit();

	return;
};

//Singly Linked List Stack Pop
void SingleLinkStackPop(){
	if(SinglyStackHead == NULL)
      printf("\nYour Stack is Empty!!! Deletion not successful \n");
   else{
      struct SinglyLinkedStack *temp = SinglyStackHead;
      printf("\nDeletion Successfull. Deleted element: %d", temp->data);
      SinglyStackHead = temp->next;
      free(temp);
   }

	ContinueorExit();

	return;
};

//Singly Linked List Stack Push
void SingleLinkStackPush(int value){

   struct SinglyLinkedStack *newNode;
   newNode = (struct SinglyLinkedStack*)malloc(sizeof(struct SinglyLinkedStack));
   newNode->data = value;
   if(SinglyStackHead == NULL)
      newNode->next = NULL;
   else
      newNode->next = SinglyStackHead;
   SinglyStackHead = newNode;
   printf("\nInsertion is Success!!!\n");

	ContinueorExit();

	return;
};

//Singly Linked List Queue Print
void SingleLinkQueuePrint(){
	if(SinglyQueueHead == NULL)
	      printf("\n**********Printing Queue Done !!! Your Queue is Empty!!!\n");
	   else{
	      struct SinglyLinkedQueue *temp = SinglyQueueHead;
	      printf("\n**********Printing Queue Done !!! Your Queue: ");
	      while(temp->next != NULL){
		 printf("%d--->",temp->data);
		 temp = temp -> next;
	      }
	      printf("%d--->END \n",temp->data);
	   }
	ContinueorExit();

	return;
};
void SingleLinkQueuePush(int value){
   struct SinglyLinkedQueue *newNode;
   newNode = (struct SinglyLinkedQueue*)malloc(sizeof(struct SinglyLinkedQueue));
   newNode->data = value;
   newNode->next = NULL;
   if(SinglyQueueHead == NULL)
	SinglyQueueHead = newNode;
   else
   {
      struct SinglyLinkedQueue *temp = SinglyQueueHead;
      while(temp->next != NULL)
	temp = temp->next;
      temp->next = newNode;
   }
   printf("\nInsertion is Success!!!\n");

	ContinueorExit();

	return;
};
void SingleLinkQueuePop(){
	if(SinglyQueueHead == NULL)
      printf("\nYour Queue is Empty!!! Deletion not successful \n");
   else{
      struct SinglyLinkedQueue *temp = SinglyQueueHead;
      printf("\nDeletion Successfull. Deleted element: %d", temp->data);
      SinglyQueueHead = temp->next;
      free(temp);
   }
	ContinueorExit();

	return;
};
void SingleLinkDoubleEndedQueuePrint(){
	if(SinglyDoubleEndedQueueHead == NULL)
	      printf("\n**********Printing Double Ended Queue Done !!!\n Your Double Ended Queue is Empty!!!\n");
	   else{
	      struct SinglyLinkedDoubleEndedQueue *temp = SinglyDoubleEndedQueueHead;
	      printf("\n**********Printing Double Ended Queue Done !!!\n Your Double Ended Queue: ");
	      while(temp->next != NULL){
		 printf("%d--->",temp->data);
		 temp = temp -> next;
	      }
	      printf("%d--->END \n",temp->data);
	   }
	ContinueorExit();

	return;
};
void SingleLinkDoubleEndedQueuePopFront(){
	if(SinglyDoubleEndedQueueHead == NULL)
      printf("\nYour Double Ended Queue is Empty!!! Deletion not successful \n");
   else{
      struct SinglyLinkedDoubleEndedQueue *temp = SinglyDoubleEndedQueueHead;
      printf("\nDeletion Successfull. Deleted element: %d", temp->data);
      SinglyDoubleEndedQueueHead = temp->next;
      free(temp);
   }
	ContinueorExit();

	return;
};
void SingleLinkDoubleEndedQueuePopBack(){
 if(SinglyDoubleEndedQueueHead == NULL)
   {
      printf("\n******Your Double Ended Queue is Empty!!! Deletion not successful\n");
   }
   else
   {
      struct SinglyLinkedDoubleEndedQueue *temp1 = SinglyDoubleEndedQueueHead,*temp2;
      if(SinglyDoubleEndedQueueHead->next == NULL)
	SinglyDoubleEndedQueueHead = NULL;
      else
      {
	 while(temp1->next != NULL)
	 {
	    temp2 = temp1;
	    temp1 = temp1->next;
	 }
	 temp2->next = NULL;
      }
      printf("\nDeletion Successfull. Deleted element: %d", temp1->data);
      free(temp1);
 
   }
	ContinueorExit();

	return;
};
void SingleLinkDoubleEndedQueuePushFront(int value){
   struct SinglyLinkedDoubleEndedQueue *newNode;
   newNode = (struct SinglyLinkedDoubleEndedQueue*)malloc(sizeof(struct SinglyLinkedDoubleEndedQueue));
   newNode->data = value;
   if(SinglyDoubleEndedQueueHead == NULL)
      newNode->next = NULL;
   else
      newNode->next = SinglyDoubleEndedQueueHead;
   SinglyDoubleEndedQueueHead = newNode;
   printf("\nInsertion is Success!!!\n");

	ContinueorExit();

	return;
};
void SingleLinkDoubleEndedQueuePushBack(int value){
   struct SinglyLinkedDoubleEndedQueue *newNode;
   newNode = (struct SinglyLinkedDoubleEndedQueue*)malloc(sizeof(struct SinglyLinkedDoubleEndedQueue));
   newNode->data = value;
   newNode->next = NULL;
   if(SinglyDoubleEndedQueueHead == NULL)
	SinglyDoubleEndedQueueHead = newNode;
   else
   {
      struct SinglyLinkedDoubleEndedQueue *temp = SinglyDoubleEndedQueueHead;
      while(temp->next != NULL)
	temp = temp->next;
      temp->next = newNode;
   }
	ContinueorExit();

	return;
};
//SINGLY LINKED LIST - STACK , QUEUE, DOUBLE ENDED QUEUE *** END HERE