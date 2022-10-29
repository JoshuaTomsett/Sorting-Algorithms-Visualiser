#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int length){
	int i;

	for (i = 0 ; i < length ; i++){
		printf("%d, ", arr[i]);
	}
}

void swap(int* xp, int* yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubble_sort(int arr[], int length){
	int i, j;
	for (i = 0; i < length - 1; i++){
		for (j = 0; j < length - i - 1; j++){
			if (arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}


int quick_sort(int arr[], int length){

	return 0;
}


int merge_sort(int arr[], int length){

	return 0;
}


void insertion_sort(int arr[], int length){
	int i, key, j;
	for (i = 1; i < length; i++){
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j = j - 1;
		}
		arr[j+1] = key;
	}
}


int heap_sort(int arr[], int length){

	return 0;
}


int bogo_sort(int arr[], int length){

	return 0;
}


void shuffle(int arr[], int n){
	srand(time(NULL));
	if (n > 1){
		int i;
		for (i = 0; i < n - 1 ; i++){
			int j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = arr[j];
			arr[j] = arr[i];
			arr[i] = t;
		}
	}
}


int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int length = sizeof(arr) / sizeof(int);

	shuffle(arr, length);

	printArray(arr, length);
	printf("\n");
	insertion_sort(arr, length);
	printArray(arr, length);
	printf("\n");

	return 0;
}
