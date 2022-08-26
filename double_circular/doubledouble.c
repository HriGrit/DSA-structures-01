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
    struct node *nade = (struct node *)malloc(sizeof(struct node));
    nade->data = x;
    nade->next = NULL;
    nade->prev = NULL;

    struct node *temp;
    if (head == NULL)
        head = nade;
    else if (head->next == NULL){
        head->prev = nade;
        head->next = nade;
        nade->next = head;
        nade->prev = head;
    }else{
        for (temp = head; temp->next != head; temp = temp->next);
        temp->next = nade;
        nade->next = head;
        nade->prev = temp;
        head->prev = nade;
    }
}

void middle(){
    struct node *l1, *l2;
    if (head->next == NULL)
        printf("Middle Element is %d\n", head->data);
    else{
        for (l1 = head, l2 = head->prev; l1 != l2 && l2->data > l1->data; l1 = l1->next, l2 = l2->prev);
        printf("Middle element is %d\n", l2->data);
    }
}

void display(){
    struct node *temp = head;
    printf("List<=>");
    if (head != NULL && head->next != NULL){
        // for (temp = head; temp != head; temp = temp->next)
        //     printf("%d ", temp->data);
        do{
            printf("%d<=>", temp->data);
            temp = temp->next;
        }while (temp != head);
    }else{
        if (head != NULL)
            printf("%d<=>", head->data);
    }
    printf("List\n");
}

int main(){
    int n, temp;
    scanf("%d", &n);

    while (n--){
        scanf("%d", &temp);
        addnode(temp);
    }

    display();
    middle();
}