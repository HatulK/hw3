#include <stdio.h>

#include <math.h>
#include <stdio.h>
#define LENGTH 50

void shift_element(int *(arr), int i) {
    for (int j = i; j >= 0; j--) {
        *(arr + j + 1) = *(arr + j);
    }
}

void insertion_sort(int *arr, int len) {
    int i, key, j, counter;
    for (i = 1; i < len; i++) {
        key = *(arr + i);
        j = i - 1;
        counter = 0;
        while (j >= 0 && *(arr+j) > key) {
            counter++;
            j = j - 1;
        }
        shift_element((arr + j), counter);
        *(arr+ j + 1) = key;
    }
}

void printArray(int *arr, int n) {
    for (size_t i =0; i< LENGTH-1;i++){
        printf("%d,",*(arr+i));
    }
    printf("%d",*(arr+n-1));
    printf("\n");
}

int main() {
    int text[LENGTH] ;
    for (int i = 0;i<LENGTH+1;i++){
        scanf("%d",&text[i]);
    }
    insertion_sort(text, LENGTH);
    printArray(text, LENGTH);
}