/* C++ implementation of QuickSort */
#include <iostream> 
using namespace std; 

void swap(int* a, int* b) { 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
}

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int low, int high) { 
	int pivot = arr[high]; 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high - 1; j++) { 
		// If current element is smaller than the pivot 
		if (arr[j] < pivot) { 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) { 
	if (low < high) { 
		/* pi is partitioning index, arr[p] is now 
		at right place */
		int pi = partition(arr, low, high); 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

void printArray(int arr[], int size) { 
	int i; 
	for (i = 0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

int main() { 
	int arr[] = {11, 10, 20, 19, 25}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	quickSort(arr, 0, n - 1); 
	cout << "Sorted array: "; 
	printArray(arr, n); 
	return 0; 
} 
