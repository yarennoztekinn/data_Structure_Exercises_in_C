#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} node;

void insertatEnd(node **head, int data){
    node *newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("\nOVERFLOW\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

   
    if (*head == NULL) {
        *head = newNode;
    } else {
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(node *head){
    if (head == NULL) {
        printf("\nthe list is empty\n");
        return;
    }

    node *temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void compare(node *head1, node *head2){
    node *temp1 = head1;
    node *temp2 = head2;

    int flag = 1;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data != temp2->data) {
            flag = 0;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if (temp1 != NULL || temp2 != NULL) {
        flag = 0;
    }

    if (flag == 1) {
        printf("The 2 list are equal\n");
    } else {
        printf("The 2 list are not equal\n");
    }
}

void merge(node *head1, node *head2){
    node *head3 = NULL;
    node *last = NULL;

    node *temp1 = head1;
    while (temp1 != NULL) {
        node *newNode = (node*)malloc(sizeof(node));
        if (newNode == NULL) {
            printf("\nMemory allocation failed!\n");
            return;
        }
        newNode->data = temp1->data;
        newNode->next = NULL;

  
        if (head3 == NULL) {
            head3 = newNode;
            last = head3;
        } else {
            last->next = newNode;
            last = newNode;
        }
        temp1 = temp1->next;
    }
    last->next = head2;


    display(head3);
}

int main(){
    node *head1 = NULL; 
    node *head2 = NULL;

    insertatEnd(&head1, 10); 
    insertatEnd(&head1, 20);
    insertatEnd(&head1, 30);

    insertatEnd(&head2, 10);
    insertatEnd(&head2, 20);
    insertatEnd(&head2, 30);

    printf("\nList 1\n");
    display(head1);

    printf("\nList 2\n");
    display(head2);

    compare(head1, head2);

    printf("\n******************\n");
    printf("\nThe merged list\n");
    merge(head1, head2);

    return 0;
}
