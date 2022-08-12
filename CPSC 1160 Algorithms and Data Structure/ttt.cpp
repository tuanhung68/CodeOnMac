#include <iostream>
using namespace std;

void back(int n){
    if(n >= 0){
        back(n - 1);
        cout << n << " " << endl;
    }
}
bool IsSorted(int* arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    if (arr[i] > arr[i+1]) { // items out of place
      return false;
    }
  }
 return true;
}
int sumPage(int*** book, int pageNumber, int lines, int col) {
    int sum = 0;
    for (int j = 0; j < lines; j++) {
        for (int k = 0; k < col; k++) {
            sum += book[pageNumber][j][k];// *(*(book + i) + j)
            // *(*(*(book + pageNumber) + i) + j)
        }
    }
}
void insertionSort(int list[], int listSize)
{
  for (int i = 1; i < listSize; i++)
  {
    int currentElement = list[i];
    int k;
    for (k = i - 1; k >= 0 && list[k] > currentElement; k--)
    {
       list[k + 1] = list[k];
     }
   // Insert the current element into list[k+1]
   list[k + 1] = currentElement;
   // *(list + k + 1)
  }
}



int main()
{
    int arr[] = {5, 19, 20, 3, 1, 19};
    cout << IsSorted(arr, 6);
    return 0;
}