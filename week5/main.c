/*
    Prog 5-1: Creating libraries, compliling and linking
*/

#include "lib_single_link_list.h" //single linked list
// #include "lib_double_link_list.h" //double linked list
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    struct SingleLinkNode *shead;
    shead = NULL; //make the list empty
    insertFirsteElement_SLL( &shead, 2, 45);
    insertFirsteElement_SLL( &shead, 3, 13);
    insertFirsteElement_SLL( &shead, 1, 27);
    printList_SLL( shead );
    return 0;
}