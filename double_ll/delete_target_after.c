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
    if (head->next == NULL){
        if (head->data != t)
            printf("Target Element is Not Found\n");
        else
            for (temp = head; (temp != NULL) & (temp->data != t); temp = temp->next);
    }
    
    if (temp->next == NULL){
        if (temp->data != t)
            printf("Target Element is Not Found\n");
    }else{
        temp->next->prev = temp;
        temp->next = temp->next->next;
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
    int t;
    scanf("%d", &t);

    delete(t);
    display();
    
}