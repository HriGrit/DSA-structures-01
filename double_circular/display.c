#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void addnode(int t){
    struct node *nade = (struct node *)malloc(sizeof(struct node));
    nade->data = t;
    nade->next = NULL;

    if (head == NULL)
        head = nade;
    else if (head->next == NULL){
        head->next = nade;
        nade->next = head;
    }
    else{
        struct node *temp;
        for (temp = head; temp != NULL; temp = temp->next);
        temp->next = nade;
        nade->next = head;
    }
}

void display(){
    struct node *nade;
    printf("List->");
    for (nade = head; nade != NULL; nade = nade->next)
        printf("%d->", nade->data);
    printf("%d->NULL\n", nade->data);
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