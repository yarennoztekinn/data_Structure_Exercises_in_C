#include <stdio.h>
#include <stdlib.h>

typedef struct  singlyNode{
    int data;
    struct singlyNode *next;
}node;

void display(node *head){
    printf("The List is\n");

    if (head == NULL)
    {
        printf("\nthe list is empty\n");
        return;
    }
    
    node *temp = head;

    while (temp!= NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

void showelement(node *head, int n){
    if (head == NULL)
    {
        printf("\nthe list is empty\n");
        return;
    }

    node *temp = head;
    int i = 1;

    while (temp != NULL && i < n){
        temp = temp->next;
        i++;  
    }
    if (temp != NULL) {
        printf("The element is: %d\n", temp->data);
    } else {
        printf("\nthe list is not that long\n");
    }
}

void sumOfData(node * head){
    if (head == NULL)
    {
        printf("\nthe list is empty\n");
        return;
    }

    node *temp = head;
    int sum = 0;
    while (temp != NULL)
    {
        sum += temp->data;
        temp = temp->next;
    }
    printf("Sum: %d\n", sum);
}

int main(){
    node *head = (node *)malloc(sizeof(node));
    node *node1 = (node *)malloc(sizeof(node));
    node *node2 = (node *)malloc(sizeof(node));
    node *node3 = (node *)malloc(sizeof(node));


    head->data = 10;
    head->next = node1;
    node1->data = 20;
    node1->next = node2;
    node2->data = 30;
    node2->next = node3;
    node3->data = 40;
    node3->next = NULL;

    display(head);

    showelement(head, 3);

    sumOfData(head);

    free(head);
    free(node1);
    free(node2);
    free(node3);

    return 0;
}

//EXERCISE 2

