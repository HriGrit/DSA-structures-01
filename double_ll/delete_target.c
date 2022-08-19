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

void delete(int t){
    struct node *temp;
    if (head->data == t){
        head->next->prev = NULL;
        head = head->next;
    }else if (head != NULL){
        for (temp = head; (temp != NULL) && (temp->data != t); temp = temp->next);
    
        if (temp->next == NULL){
            if (temp->data == t){
                temp->prev->next = NULL;
                temp = NULL;
            }
        }else if (temp->next->next == NULL){
            if (temp->next->data == t)
                temp->next = NULL;
        }else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
    }
}

void display(){
    struct node *temp;
    printf("List->");
    for (temp = head; temp->next != NULL; temp = temp->next)
        printf("%d ", temp->data);
    printf("%d->NULL\n", temp->data);
}

int main(){
    int n, temp;
    scanf("%d", &n);

    while (n--){
        scanf("%d", &temp);
        addnode(temp);
    }
    int t;
    scanf("%d", &t);

    if (head->next == NULL){
        if (head->data == t)
            printf("List is Empty\n");
        else    
            printf("Target Element is Not Found\n");
    }else{
        delete(t);
        display();
    }
}