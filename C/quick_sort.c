//Implementation of Merge Sort in C
#include <stdio.h>
#include <stdlib.h>
typedef int TYPE;
void merge(TYPE [], int, int, int);
void merge_sort(TYPE [], int, int);
void print_array(TYPE [], int);

int main(){
	puts("-----Merge Sort-----");
	TYPE A[] = {7, 13, 6, 234, 2995, 1332, 3, 44};
	int n = sizeof(A) / sizeof(TYPE);
	
	printf("Unsorted: ");
	print_array(A, n);
	
	printf("Sorted: ");
	merge_sort(A, 0, n - 1);
	print_array(A, n);
	
	return EXIT_SUCCESS;
}
void merge(TYPE A[], int p, int q, int r) {
	int i, j, k;
	int nL = q - p + 1; 
	int nR = r - q;

	TYPE *L = malloc(sizeof(TYPE)*nL);
	TYPE *R = malloc(sizeof(TYPE)*nR);
	
	for (i = 0; i < nL; i++)	
		L[i] = A[p + i];
	
	for (j = 0; j < nR; j++)	
		R[j] = A[q + 1 + j];
	
	i = j = 0;
	k = p;
	
	while (i < nL && j < nR) 
		if (L[i] <= R[j])  A[k++] = L[i++];
		else  A[k++] = R[j++];
	
	while (i < nL)	A[k++] = L[i++];
	while (j < nR)	A[k++] = R[j++];
		
	free(L);
	free(R);
}
void merge_sort(TYPE A[], int p, int r) {
	if(p < r) {
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}
}
void print_array(TYPE A[], int n) {
	int i = 0;
	putchar('[');
	while(i < n) {
		if(i > 0) printf(", ");
		printf("%d", A[i++]); 
	}
	puts("]");
}