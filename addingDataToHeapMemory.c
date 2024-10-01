#include <stdio.h>

// generating array inside heap memory
int * func(int size){  // we can use [] at a place of pointer(*) 
    int *p;
    p = (int *)malloc(size);

    for (int i = 0; i < size; i++){
        p[i] = i+1;
    }
    return p;
}

int main(){
    int *ptr, sz = 5;
    ptr = func(sz);
    for (int i = 0; i < sz; i++){
        printf("%d\n",ptr[i]);
    }
    return 0;
}

// Main function is getting arrays pionter from heap memory, which means we can point at heap storape using pointer of an
