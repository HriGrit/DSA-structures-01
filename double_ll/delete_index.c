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

void delete(int pos){
    struct node *current;
    if (head != NULL){
        int i = 1;
        for (current = head; (current != NULL) && (i < pos);current = current->next, i++);
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
}

void display(){
    struct node *temp;
    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d ", temp->data);
    printf("\n");
}

int main(){
    int n, temp;
    scanf("%d", &n);

    int nn = n;
    while (n--){
        scanf("%d", &temp);
        addnode(temp);
    }
    int pos;
    scanf("%d", &pos);

    if (pos > nn)
        printf("Target Position not Found\n");
    else{
        delete(pos);
        display();
    }
}