#include <stdio.h>
#include <stdbool.h>

bool descending(int a, int b){
    return a >= b;
}

bool ascending(int a, int b){
    return a <= b;
}

void swap(int* a, int* b){
    int hold = *a;
    *a = *b;
    *b = hold;
}

void qsort(int[], int, bool(*)(int, int));

void print(int arr[], int size){
    for(int i = 0; i < size-1; ++i){
        printf("%d, ", arr[i]);
    }
    printf("%d\n", arr[size-1]);
}

int main(int argc, char* argv[]){

    int arr[] = {1,4,3,5,6,10,7,12,34};
    int size = sizeof(arr)/sizeof(int);

    print(arr, size);
    qsort(arr, size, ascending);
    print(arr, size);
    qsort(arr, size, descending);
    print(arr, size);

    return 0;
}

void qsort(int arr[], int size, bool(*test)(int, int)){

    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size - 1; ++j){
            if(!test(arr[j], arr[j+1])){
                swap(&arr[j], &arr[j+1]);
            }

        }
    }
}