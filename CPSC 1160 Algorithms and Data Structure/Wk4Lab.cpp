#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
// get random numbers from 10 to 50, both are inclusive
int GenerateRandomValue(int min, int max){
	return min + (rand() % (max - min + 1));
}
// generate random items for the array from 10 to 50
int *GenerateRandomArray(int *arr, int size, int min, int max){
	for(int i = 0; i < size; i++){
        arr[i] = GenerateRandomValue(min, max);
	}
	return arr;
}

void Display(int* arr, int size) {
	for(int i = 0; i < size; i++){
		cout << arr[i] << "\t";
	}
	cout << endl;
	cout << "--------------\n" << endl;
}
void Swap(int* a, int leftIndex, int rightIndex) {
	int temp = a[leftIndex];
	a[leftIndex] = a[rightIndex];
	a[rightIndex] = temp;
}
int PlacePivot(int *arr, int len){
	int pivot, low, high;

    pivot = 0;
    low = 1;
    high = len - 1;

    // place pivot.
    while (low <= high) {
        if (arr[low] <= arr[pivot]) {
            low++;
        }
        else if (arr[high] > arr[pivot]) {
            high--;
        }
        else if(low <= high) {
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high]= temp;
        }
    }
    //swap item @ pivot with item @ high
    int temp = arr[pivot];
    arr[pivot] = arr[high];
    arr[high] = temp;

    return high;
}
// QuickSort
void QuickSort(int *arr, int len){
	// in place sort, ascending order

    if(len == 0 || len == 1){
        return;
    }
    else if(len == 2){
        int temp;
        if(arr[0] > arr[1]){
            temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
        }
    }
    else{
        int pivotIndex = PlacePivot(arr, len); 

        // once we call the following function we are giving it the small problem 1 (sort left half)
        QuickSort(arr, pivotIndex); 
        // when we return from the recursive call then we have our small solution 1 (left half is sorted)
        // in place sort of left half is in arr 

        // once we call the following function we are giving it the small problem 2 (sort right half)
        QuickSort(arr+pivotIndex+1, len - pivotIndex - 1); 
        // when we return from the recursive call then we have our small solution 2 (right half is sorted)
        // in place sort of left half 
    }
    

}
void findMinIndexRecursive(int *list, int listSize, int startingIndex, int &currentMin, int &currentMinIndex){
    if(startingIndex == listSize){
        return;
    }
    if(list[startingIndex] < currentMin){
        currentMin = list[startingIndex];
        currentMinIndex = startingIndex;
    }
    findMinIndexRecursive(list, listSize, ++startingIndex, currentMin, currentMinIndex);
}
void SelectionSort(int *list, int i, int listSize)
{
	// return when starting and size are the same
	if(i == listSize){
		return;
	}
    // Find the minimum in the list[i..listSize-1]
    int currentMin = list[i];
	// i is the startingIndex
    int currentMinIndex = i;
    findMinIndexRecursive(list, listSize, i, currentMin, currentMinIndex);
    // Swap list[i] with list[currentMinIndex] if necessary;
    if(currentMinIndex != i){
        int temp = list[currentMinIndex];
        list[currentMinIndex] = list[i];
        list[i] = temp; 
	}
	// call the function recursively and increment i after each call
    SelectionSort(list, ++i, listSize);
}
// bubble sort
void BubbleSort(int *arr, int i, int j){
	// i is the current index of rows
	// j is the current index of columns 
	// base case: if the row = len, terminate the code
	if(i == 0){
		return;
	}
    // The current item needed to be sorted
    if(j < i){
        if(arr[j] > arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
        BubbleSort(arr, i, ++j);
    }
	// if j = i, increment row by one, set cols = 0
    else{
        BubbleSort(arr, --i, 0);
    }
	
}
// InsertionSort
void InsertionSort(int *arr, int i, int j, int len){
	if(i == len){
		return;
	}
	// The current item needed to be sorted
	int current = arr[i];
	j = i - 1;
    while(j >= 0 && arr[j] > current){
        // copy
        arr[j + 1] = arr[j];
        j--;
    }
	arr[j + 1] = current;
	InsertionSort(arr, ++i, j, len);
}
// merge the divided array
void Merged(int A[], int low, int high, int mid)
{
    int i, j, k;
    // create a new array to contain the sorted items
    int *merged = new int[high + 1];
    i = k = low;
    j = mid + 1;
    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            merged[k] = A[i];
            k++;
            i++;
        }
        else{
            merged[k] = A[j];
            k++;
            j++;
        }
    }
    while (i <= mid){
        merged[k] = A[i];
        k++;
        i++;
    }
    while (j <= high){
        merged[k] = A[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++){
        A[i] = merged[i];
    }
}
void MergeSort(int *arr, int low, int high){
    if(low >= high){
        return;
    }
    // divide the array into half
    int mid = (low + high) / 2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    // Merge them
    Merged(arr, low, high, mid);
}
int main()
{
	srand(time(0));
    cout << "What is the size of the array? ";
    int M;
    cin >> M;
    int *arr = new int[M];
    int min = 10;
    int max = 50;
    arr = GenerateRandomArray(arr, M, min, max);
    Display(arr, M);
	
	
	auto start = chrono::steady_clock::now();
   
	//SelectionSort(arr, 0, M);
	//BubbleSort(arr, M - 1, 0);
    //QuickSort(arr, M);
	//InsertionSort(arr, 1, 0, M);
    MergeSort(arr, 0, M - 1);
	auto stop = chrono::steady_clock::now();
	Display(arr, M);
	auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
	cout << "Time taken by function: " << duration.count() << " nanoseconds"; // /1e9
    
    if(arr != nullptr){
        delete[] arr;
        arr = nullptr;
    }
    return 0;
}