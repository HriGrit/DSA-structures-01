#include <stdio.h>

int main(){
    int n, temp;
    scanf("%d", &n);
    int arr[n];

    int max = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &temp);
        if (temp > max)
            max = temp;
        arr[i] = temp;
    }
    int count[max], res[n];
    for (int i = 0; i < max; i++){  // making 0
        count[i] = 0;
    }
    
    for (int i = 0; i < n; i++){    // taking input
        count[arr[i]]++;
    }
    
    for (int i = 1; i < max; i++){  // changing the array
        count[i] += count[i-1];
    }

    for (int i = max - 1; i >= 0; i--){
        printf("%d ", count[arr[i]]);
    }
    
    for (int i = 0; i < n; i++){ // printing
        printf("%d ",res[i]);
    }
}