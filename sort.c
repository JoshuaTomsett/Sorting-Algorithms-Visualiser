#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int length){
	int i;

	for (i = 0 ; i < length ; i++){
		printf("%d, ", arr[i]);
	}
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

void swap(int* xp, int* yp){ // x pointer , y pointer
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// first subarray is arr[l..m]
// second subarray is arr[m+1..r]

void merge(int arr[], int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2]; // temp arrays

	for(i = 0; i < n1; i++){
		L[i] = arr[l + i]; // copy data to temp arrays
	}
	for(j = 0; j < n2; j++){
		R[j] = arr[m + 1 + j];
	}

	i = 0; // index of first subarray
	j = 0; // index of second subarray
	k = l; // index of merged subarray

	while(i < n1 && j < n2){
		if (L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1){ // add any remaining elements of L[]
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2){ // add any remaining elements of R[]
		arr[k] = R[j];
		j++;
		k++;
	}
}

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++){
		if (arr[j] < pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return (i + 1);
}

int is_sorted(int arr[], int length){
	int i;
	for (i = 0 ; i < length - 2; i++){
		if (arr[i] > arr[i + 1]){ // current index > next index = not sorted
			return 0;
		}
	}
	return 1; // if it is sorted
}

// l = left index (0) , r = right index (length - 1) of subarray to be sorted

void merge_sort(int arr[], int l, int r){
	if (l < r){
		int m = l + (r - l) / 2;
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
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

void quick_sort(int arr[], int low, int high){
	if (low < high){
		int pi = partition(arr, low, high);

		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
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


void bogo_sort(int arr[], int length){
	while (! is_sorted(arr, length)){
		shuffle(arr, length);
		printArray(arr, length);
		printf("\n");
	}
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int length = sizeof(arr) / sizeof(int);

	shuffle(arr, length);

	printArray(arr, length);
	printf("\n");
	bogo_sort(arr, length);
	printArray(arr, length);

	if (is_sorted(arr, length)){
		printf("\nArray is sorted!");
	}

	printf("\n");

	return 0;
}
