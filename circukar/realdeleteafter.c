#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
void display();
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
    struct node *temp = head;
    if (head->next != NULL){
        do{
            temp = temp->next;
        }while (temp != head && temp->data != x);
    }else{
        if (head->data != x)
            printf("Target Element is Not Found\n");
        else    
            printf("List is Empty\n");
    }
    if(temp->data == x){
        if (temp->next != head)
            temp->next = temp->next->next;
        else{
            temp->next = head->next;
            head = head->next;
        }
        display();
    }else{
        if (head->next != NULL)
            printf("Target Element is Not Found\n");
    }
}

void display(){
    struct node *nade = head;
    if (head->next != NULL){
        printf("List->");
        do{
            printf("%d->", nade->data);
            nade = nade->next;
        }while (nade->next != head);
        printf("%d->List\n", nade->data);
    }else{
        printf("List->%d->List\n", head->data);
    }
}

int main(){
    int n, temp;
    scanf("%d", &n);
    int nn = n;
    while (n--){
        scanf("%d", &temp);
        addnode(temp);
    }
    int x;
    scanf("%d", &x);
    if (nn == 2){
        if (head->data == x){
            head->next = NULL;
        }else if (head->next->data == x){
            head = head->next;
            head->next = NULL;
        }
        display();
    }else{
        display();
        insert(x);
    }
}