#include"func.h"

int main()
{
    struct Node* head = NULL;
    pushFront(&head, 4); //1>Null
    pushFront(&head, 3); //2>1>Null
    pushFront(&head, 2); //3>2>1>Null
    pushFront(&head, 1); //4>3>2>1>Null
    pushBack(&head,5); //4>3>2>1>5>Null
    pushBack(&head,6); //4>3>2>1>5>6>Null
    pushAtNode(&head, 3, 7); //4>3>7>2>1>5>6>Null
    
    printf("print the list\n");
    printNode(&head);
    printf("====================================\n");
    
    //print odd nodes
    printf("print the odd nodes in the list\n");
    printOddNodes(&head);
    printf("====================================\n");
    //delete by key
    printf("delete key 7\n");
    deletekey(&head, 7);
    
    printf("print the list after deletion\n");
    printNode(&head);
    printf("====================================\n");
    
    printf("delete position 2\n");
    deletepos(&head, 2);
    
    printf("print the list after deletion\n");
    printNode(&head);
    printf("====================================\n");
    
    printf("midddle of the above linked list\n");
    middleNode(&head);
    printf("====================================\n");
    //TODO
    //printf("sort a linked list\n");
    //sortNode(&head);
    
    printf("insert node with data 2 in sorted linked list \n");
    insertNode(&head, 2);
    
    printf("print the list after inserting in sorted list\n");
    printNode(&head);
    printf("====================================\n");
    return 0;
}