#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
void display();
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

void delete(int x){
    if (head->next == NULL){
        if (head->data != x)
            printf("Target Element is Not Found\n");
        else
            display();
    }else{
        struct node *temp = head;
        do{
            temp = temp->next;
        }while(temp->next != NULL && temp->data != x);
        if (temp->next == NULL){
            if (temp->data != x)
                printf("Target Element is Not Found\n");
        }else if (temp->next->next == NULL){
            temp->next->prev = NULL;
            temp->next = NULL;
        }else{
            temp->next->next->prev = temp;
            free(temp->next);
            temp->next = temp->next->next;
        }
        display();
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
    display();
    
    int t;
    scanf("%d", &t);
    delete(t);
}