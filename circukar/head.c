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
    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = x;
    current->next = head;

    if (head->next == NULL){
        head->next = current;
        head = current;
    }else{
        struct node *temp;
        for (temp = head; temp->next != head; temp = temp->next);
        temp->next = current;
        head = current;
    }
}

void display(){
    struct node *nade = head;
    if (head->next != NULL){
        printf("List->");
        do{
            printf("%d->", nade->data);
            nade = nade->next;
        }while (nade != head);
        printf("List\n");
    }else{
        printf("List->%d->List\n", head->data);
    }
}

int main(){
    int n, temp;
    scanf("%d", &n);

    while (n--){
        scanf("%d", &temp);
        addnode(temp);
    }

    int x;
    scanf("%d", &x);
    
    display();
    insert(x);
    display();
}