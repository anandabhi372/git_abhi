#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void pushFront(struct Node** head, int data);
void pushBack(struct Node** head, int data);
void pushAtNode(struct Node** head, int node, int data);
void printOddNodes(struct Node** head);
void deletekey(struct Node** head, int key);
void printNode(struct Node** head );
void deletepos(struct Node** head, int pos);
void middleNode(struct Node** head);
void sortNode(struct Node** head);
void insertNode(struct Node** head, int data);