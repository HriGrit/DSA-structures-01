// #include <stdio.h>
// #include <stdlib.h>

// struct node{
//     int data;
//     struct node *next;
//     struct node *prev;
// };
// struct node *head = NULL;
// void display();

// void addnode(int x){
//     struct node *nade = (struct node *)malloc(sizeof(struct node));
//     nade->data = x;
//     nade->next = NULL;
//     nade->prev = NULL;

//     struct node *temp;
//     if (head == NULL)
//         head = nade;
//     else if (head->next == NULL){
//         head->prev = nade;
//         head->next = nade;
//         nade->next = head;
//         nade->prev = head;
//     }else{
//         for (temp = head; temp->next != head; temp = temp->next);
//         temp->next = nade;
//         nade->next = head;
//         nade->prev = temp;
//         head->prev = nade;
//     }
// }

// void delete(int x){
//     struct node *temp = head;
//     if (head->next == NULL){
//         printf("List is Empty\n");
//     }else if (head->prev->data == x){
//         head->prev->next = head->next;
//         head->next->prev = head->prev;
//         head = head->next;
//     }else{
//         for (temp = head; temp->next != head && temp->data != x; temp = temp->next);
//         temp->next->next->prev = temp;
//         temp->next = temp->next->next;
//         free(temp->next);
//     }
// }

// void display(){
//     struct node *temp = head;
//     if (head != NULL && head->next != NULL){
//         // for (temp = head; temp != head; temp = temp->next)
//         //     printf("%d ", temp->data);
//         do{
//             printf("%d ", temp->data);
//             temp = temp->next;
//         }while (temp != head);
//     }else{
//         if (head != NULL)
//             printf("%d", head->data);
//     }
// }

// int main(){
//     int n, temp;
//     scanf("%d", &n);

//     while (n--){
//         scanf("%d", &temp);
//         addnode(temp);
//     }

//     int t;
//     scanf("%d", &t);

//     delete(t);
//     display();
// }
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

void delete(int x){
    if (head->next == NULL){
        if (head->data == x)
            printf("List is Empty\n");
        else
            printf("Target Element is Not Found\n");
    }else{
        struct node *temp;
        for(temp = head; temp->next != head && temp->data != x; temp = temp->next);//temp is on place to delete
        // move temp pointers and make the next one delete
        if (temp->next == head){
            if (temp->data != x)
                printf("Target Elemnt Not Found\n");
            else{
                temp->next = head->next;
                head = head->next;
                head->prev = temp;
            }
        }else{
            temp->next->next->prev = temp;
            temp->next = temp->next->next;
        }
        display();
    }
}

void display(){
    struct node *temp = head;
    if (head != NULL && head->next != NULL){
        printf("List->");
        // for (temp = head; temp != head; temp = temp->next)
        //     printf("%d ", temp->data);
        do{
            printf("%d ", temp->data);
            temp = temp->next;
        }while (temp->next != head);
        printf("%d->List\n", temp->data);
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
    delete(x);
}