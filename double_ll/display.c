#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void addnode(int x){
    struct node *current = (struct node *)malloc(sizeof(struct node));

    current->data = x;
    current->next = NULL;
    current->prev = NULL;

    if (head == NULL)
        head = current;
    else{
        struct node *temp;
        for (temp = head; temp->next != NULL; temp = temp->next);
        temp->next = current;
        current->prev = temp;
    }
}

void display(){
    struct node *temp;
    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d ", temp->data);
}

int main(){
    int n, temp;
    scanf("%d", &n);

    while (n--){
        scanf("%d", &temp);
        addnode(temp);
    }

    display();
}