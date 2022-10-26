#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bubble_sort(int arr[]){
	
	return 0;
}


int quick_sort(int arr[]){

	return 0;
}


int merge_sort(int arr[]){

	return 0;
}


int insertion_sort(int arr[]){

	return 0;
}


int heap_sort(int arr[]){

	return 0;
}


int bogo_sort(int arr[]){

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

	int i;
	int length = 10;
	int arr[] = {1,2,3,4,5,6,7,8,9,10};

	shuffle(arr, length);

	for (i = 0 ; i < length ; i++){
		printf("%d, ", arr[i]);
	}

	printf("\n");
	printf("test\n");

	return 0;
}
