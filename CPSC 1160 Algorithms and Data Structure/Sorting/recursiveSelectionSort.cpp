#include <iostream>
using namespace std;

// double findMinIndex(double list[], int listSize, int start){
//     double currentMin = list[start];
//     int currentMinIndex = start;
//     for (int i = start + 1; i < listSize; i++){
//         if (currentMin > list[i]){
//         currentMin = list[i];
//         currentMinIndex = i;
//         }
//     }
//     return currentMinIndex;
// }
void findMinIndexRecursive(double list[], int listSize, int startingIndex, double &currentMin, int &currentMinIndex){
    
    if(startingIndex == listSize){
        return;
    }

    if(list[startingIndex] < currentMin){
        currentMin = list[startingIndex];
        currentMinIndex = startingIndex;
    }
    findMinIndexRecursive(list, listSize, ++startingIndex, currentMin, currentMinIndex);

}
void selectionSort(double [], int);
void printArray(double list[], int arraySize); // function prototype


void selectionSort(double list[], int listSize)
{
  for (int i = 0; i < listSize; i++){
    // Find the minimum in the list[i..listSize-1]
    double currentMin = list[i];
    int currentMinIndex = i;
    findMinIndexRecursive(list, listSize, i, currentMin, currentMinIndex);
    // Swap list[i] with list[currentMinIndex] if necessary;
    if(currentMinIndex != i){
        double temp = list[currentMinIndex];
        list[currentMinIndex] = list[i];
        list[i] = temp;
    }
  }
}

void printArray(double list[], int arraySize)
{
  for (int i = 0; i < arraySize; i++){
    cout << list[i] <<  " ";
  }
}
int main()
{
  double list[] = {9, 1, 2, 5, 4, 8, 6};
  selectionSort(list, 7);

  printArray(list, 7);
  return 0;
}


