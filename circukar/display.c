#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void addnode(int t){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = t;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL)
        head = temp;
    else if (head->next == NULL){
        temp->prev = head;
        temp->next = head;
        head->next = temp;
    }else{
        struct node *nade;
        for (nade = head; nade->next != head; nade = nade->next);
        temp->next = head;
        temp->prev = nade;
        nade->next = temp;
    }
}

void display(){
    struct node *temp = head;
    printf("List->%d->", temp->data);
    for (temp = head->next; temp != head; temp = temp->next)
        printf("%d->", temp->data);
    printf("NULL\n");
}

int main(){
    int x, temp;
    scanf("%d", &x);

    while (x--){
        scanf("%d", &temp);
        addnode(temp);
    }
    display();
}