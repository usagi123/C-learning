/*
    Prog 6-2: Binary trees and their algorithms
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int left(int i){return i*2+1;}
int right(int i){return i*2+2;}
int parent(int i){return (i-1)/2;}

void pre_order(char *tree, int node);
void in_order(char *tree, int node);
void post_order(char *tree, int node);

int main(int argc, char *argv[]){
    char tree[200];
    strcpy(tree, "+-/*5^423nn41nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn");
    printf("\n Pre-order: ");
    pre_order(tree, 0);
    printf("\n In-order: ");
    in_order(tree, 0);
    // printf("\n Post-order: ");
    // post_order(tree, 0);
    // printf("\n");
    return 0;
}


void pre_order(char *tree, int node){
    if(tree[node] != 'n'){
        printf("%c", tree[node]);
    }
    pre_order(tree, left(node));
    pre_order(tree, right(node));
}

void in_order(char *tree, int node){
    if(tree[node] != 'n'){
        in_order(tree, left(node));
        printf("%c", tree[node]);
        in_order(tree, right(node));
    }
    in_order(tree, left(node));
    in_order(tree, right(node));
}