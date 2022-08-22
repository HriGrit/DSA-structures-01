#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    
    int t, choice = 1;
    int top = 0, temp;
    do
    {
        printf("Please choose a thing from the menu\n1.Insert Element in the list\n2.Delete element from list\n3.Display element from list\t");
        scanf("%d", &t);

        switch (t)
        {
            case 1:
                scanf("%d", &temp);

                arr[top] = temp;
                ++top;
                break;
            case 2: //only diff in stack and q
                printf("Deleted %d\n", arr[0]);
                for(int i = 1; i < top; i++)
                    arr[i-1] = arr[i];
                top--;
                break;
            case 3:
                for (int i = 0; i < top; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;
                
            default:
                printf("Please enter a valid number\n");
        }

        printf("Do you wish to continue\t(0/1)\t");
        scanf("%d", &choice);
    } while (choice == 1);
    
}
