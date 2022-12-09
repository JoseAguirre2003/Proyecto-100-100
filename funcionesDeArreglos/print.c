#include <stdio.h>
#include <stdlib.h>

int insertSorted(int arr[], int n, int key, int capacity){

    if (n >= capacity){ 
        printf("Cumplio\n");
        return n;
    }

    arr[n] = key;

    return (n + 1);
}

int main(){

    int arr[20] = {8, 5, 6, 9, 0, 7};
    int capacity = sizeof(arr) / sizeof(arr[0]);
    int n = 20;
    int i, key = 2;

    printf("\n Before Insertion: ");

    for (i = 0; i < n; i++)
        printf("%d  ", arr[i]);

    printf("\ncapacidad es %i\n", capacity);

    n = insertSorted(arr, n, key, capacity);

    printf("\n After Insertion: ");

    for (i = 0; i < n; i++)
        printf("%d  ", arr[i]);

    system("\npause");

    return 0;

}