#include <stdio.h>

int precedence(char a);

char blame[] = "";
int top = 0;

void pop(){

}

void push(char name){
    if (precedence(blame[top-1]) <= precedence(name)){
        blame[top] = name;
        top++;
    }else{
        while (precedence(blame[top-1]) >= precedence(name))
            pop(blame[top-1]);
    }
}

int precedence(char a){
    if (a == '/' || a == '*')
        return 2;
    else if (a == '+' || a == '-')
        return 1;
    else if (a == '(' || a == ')')
        return 3;
    else
        return -1;
}

int main(){
    char name[] = "A+z/C*D";
    for (int i = 0; i < sizeof(name); i++){
        if (name[i] == '+' || name[i] == '-' || name[i] == '*' || name[i] == '/' || name[i] == '(' || name[i] == ')'){
            push(name[i]);
        }
    }
    for (int i = 0; i < top; i++){
        printf("%c", blame[i]);
    }
}