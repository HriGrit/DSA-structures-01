#include <stdio.h>
//infix -> postfix trial #1.01
char letter[] = "", op[] = "";
int l_top = 0, op_top = 0;

void insert_op(char l){
    op[op_top] = l;
    ++op_top;
}

void delete_op(){
    --op_top;
}

void insert_letter(char l){
    letter[l_top] = l;
    l_top++;
}

void delete_letter(){
    l_top--;
}

int main(){
    char name[]="A+B+C";

    for (int i = 0; i < sizeof(name); i++){
        if (name[i] >= 65 && name[i] <= 90)
            insert_letter(name[i]);
        else    
            insert_op(name[i]);
    }

    for (int i = 0; i < l_top; i++){
        printf("%c", letter[i]);
    }
    printf("\n");
    for (int i = 0; i < op_top; i++){
        printf("%c", op[i]);
    }
}