#include"func.h"

void pushFront(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    return;
}

void pushBack(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    struct Node* temp = *head;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next = newNode;
    return;
}

void pushAtNode(struct Node** head, int node, int data)
{
    int i;
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
 
    struct Node* temp = *head;
    for(i=1;i<node-1;i++)
    {
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    
    return;
}

void printOddNodes(struct Node** head)
{
    int i=0;
    struct Node* temp = *head;
    while(temp!=NULL)
    {
        printf("data at node %d = %d\n", i, temp->data);
        if(temp->next != NULL)
        {
            temp=temp->next->next;
            i++;
            i++;
        }
        else
        {
            break;
        }
    }
}

void deletekey(struct Node** head, int key)
{
    struct Node* temp = *head;
    struct Node* prev = *head;
    
    if((*head)->data == key)
    {
        *head = temp->next ;
        free(temp);
        return;
    }
    while(temp->data != key && temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    return;
}

void printNode(struct Node** head )
{
    struct Node* temp = *head;
    while(temp != NULL)
    {
        printf("data=%d\n",temp->data);
        temp=temp->next;
    }
}

void deletepos(struct Node** head, int pos)
{
    struct Node* temp = *head;
    struct Node* prev = *head;
    
    int i;
    if(pos==0)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    for(i=0;temp!=NULL&&i<pos-1;i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

void middleNode(struct Node** head)
{
    struct Node* fast = *head;
    struct Node* slow = *head;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle of linked list is %d\n", slow->data);
    return;
}

static void splitList(struct Node* head, struct Node** a, struct Node** b)
{
    struct Node* fast ;
    struct Node* slow ;

    slow = head;
    fast = head->next;
    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
    *a = head;
    *b = slow->next;
    slow->next = NULL;
    printf("a->data=%d b->data=%d \n", (*a)->data, (*b)->data);
    printf("print the list after \n");
}

static struct Node* sortedMerge(struct Node* a, struct Node* b)
{
    struct Node* result = NULL;
    if(a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    
    return result;
}

void sortNode(struct Node** head)
{
    struct Node* temp = *head;
    struct Node* a;
    struct Node* b;
    
    splitList(temp , &a, &b);
    
    sortNode(&a);
    sortNode(&b);
    
    *head = sortedMerge(a,b);
    
    printf("print the list after sorting\n");
    printNode(head);
}

void insertNode(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    struct Node* prev = *head;
    newNode->data = data;
    
    while(temp != NULL && temp->data < data)
    {
        prev = temp;
        temp=temp->next;
    }
    newNode->next = temp;
    prev->next = newNode;
    return;
}