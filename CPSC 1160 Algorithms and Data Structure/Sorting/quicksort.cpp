#include <iostream>
using namespace std;
int placePivot(int *arr, int len)
{
    int pivot, low, high;
    // indexes
    pivot = 0;
    low = 1;
    high = len - 1;
    // place pivot
    while(low <= high){
        if(arr[low] <= arr[pivot]){
            low++;
        }
        else if(arr[high] > arr[pivot]){
            high --;
        }
        else if(low <= high){
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }
    // swap item @ pivot with item @ high
    int temp =  arr[pivot];
    arr[pivot] = arr[high];
    arr[high] = temp;

    return high;

}
void quickSort(int *arr, int len){
    if(len == 0 || len == 1){
        return;
    }
    // once we call the following function wer giving it the small problem 1(sort left half)
    int pivotIndex = placePivot(arr, len);
    // When we return from the recursive call then we have our small solution 1(left half is sorted)
    // in place sort of left half is in arr
    quickSort(arr, pivotIndex);
    quickSort(arr, pivotIndex);

}
int main()
{

    return 0;
}