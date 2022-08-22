#include <stdio.h>

int main(){
    int arr[10];

    printf("Welcome to backchodi garage where niggas come to park\nHow much car dealing is need from u\t");
    int tt, plate;
    scanf("%d", &tt);
    tt *= 2;
    char mov;
    int top = 0, choice = 1, found = 0, index;
    while(tt--){
        scanf("%c %d", &mov, &plate);

        if (mov == 'A'){
            if (top == 9)
                printf("Parking lot is full\n");
            else{
                printf("Car %d has been inserted\n", plate);
                arr[top] = plate;
                top++;
            }
        }

        else if (mov == 'D'){
            printf("Search for Car %d has began\n", plate);
            int dep[10], t_top = 0;
            for (int i = top-1; i >= 0; i--){
                if (arr[i] != plate){
                    printf("Car %d has been removed\n", arr[i]);
                    dep[t_top] = arr[i];
                    t_top++;
                }
                else{    
                    printf("Car has been found and is departing\nPutting other cars back in Parking lot\n");
                    found = 1;
                    index = i;
                }
            }

            if (found == 0)
                printf("Car not found try washing mafia\n");
            else{
                for (int i = index+1; i < 10; i++)
                    arr[i-1] = arr[i];
                top--;
                for (int i = t_top-1; i >= 0; i--)
                    printf("Car %d has been put back\n", dep[i]);
            }
        }
    }
}
    // for (int mm = 0; mm < tt; mm++){
    //     scanf("%c %d", &mov, &plate);
    //     switch (mov){
    //     case 'A':
    //         printf("Car %d has just arrived\n", plate);
    //         arr[top] = plate;
    //         ++top;
    //         break;
    //     case 'D':
    //         printf("Search for Car %d has just began\n", arr[top-1]);
    //         int dep[10], t_top = 0, found = 0;
    //         for (int i = top-1; i >= 0; i--){
    //             if (arr[i] != plate){
    //                 printf("Car %d has been removed\n", arr[i]);
    //                 dep[t_top] = arr[i];
    //                 t_top++;
    //             }
    //             else{
    //                 printf("Car %d has been found and is departing\n", arr[i]);
    //                 found = 1;
    //                 break;
    //             }
    //         }
    //         if (!found){
    //             printf("The car was not found in garage\n");
    //         }else{
    //             printf("Putting back\n");
    //             for (int i = t_top-1; i >= 0; i--)
    //                 printf("Car %d is put back\n", dep[i]);
    //             --top;
    //         }
    //         break;
    //     }
    // }
