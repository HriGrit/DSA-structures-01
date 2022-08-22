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

int mt = 0;

void display();

void insert_last(int x){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;

    struct node *nade;
    for (nade = head; nade->next != head; nade = nade->next);
    temp->next = head;
    temp->prev = nade;
    nade->next = temp;
}

void insert(int x, int m){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = m;
    temp->next = NULL;
    temp->prev = NULL;

    struct node *nade;
    for (nade = head; nade->next != head && nade->data != x; nade = nade->next);
    if (nade->data == x){
        temp->next = nade->next;
        nade->next->prev = temp;
        temp->prev = nade;
        nade->next = temp;

        display();
    }else{
        printf("Element Not Found\n");
        mt = 1;
    }
}

void display(){
    struct node *temp = head;
    printf("List->%d->", temp->data);
    for (temp = head->next; temp != head; temp = temp->next)
        printf("%d->", temp->data);
    printf("List\n");
}
int main(){
    int n, temp;
    scanf("%d", &n);
    
    int nn = n;
    while (n--){
        scanf("%d", &temp);
        addnode(temp);
    }
    
    int x, m;
    scanf("%d %d", &x, &m);
    if (nn == 1){
        printf("List->%d->List\n", head->data);
        if (head->data != x)
            printf("Target Element is Not Found\n");
        else
            addnode(m);
    }else{
        display();
        insert(x, m);
    }
}