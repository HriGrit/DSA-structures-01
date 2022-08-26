#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void addnode(int x){
    struct node *nade = (struct node *)malloc(sizeof(struct node));
    nade->next = NULL;
    nade->data = x;

    if (head == NULL)
        head = nade;
    else if (head->next == NULL){
        head->next = nade;
        nade->next = head;
    }else{
        struct node *temp;
        for (temp = head; temp->next != head; temp = temp->next);
        temp->next = nade;
        nade->next = head;
    }
}

void insert(int x){
    struct node *nade = (struct node *)malloc(sizeof(struct node));
    nade->data = x;
    nade->next = head;

    struct node *temp;
    for (temp = head; temp->next != head; temp = temp->next);
    temp->next = nade;
    head = nade;
}

void display(){
    struct node *nade = head;
    printf("List->");
    do{
        printf("%d->", nade->data);
        nade = nade->next;
    }while (nade->next != head);
    printf("%d->List\n", nade->data);
}

int main(){
    int n, temp;
    scanf("%d", &n);

    while (n--){
        scanf("%d", &temp);
        addnode(temp);
    }
    display();

    int t;
    scanf("%d", &t);
    insert(t);

    display();
}