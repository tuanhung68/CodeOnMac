#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>

using namespace std;
/**
 * @brief The sum of the series
 * 
 * @param n : The number of values in the series  
 * @return double 
 */
double F(int n)
{
    if(n == 1){
        return round(1/3.0*10000)/10000;
    }
    return round((F(n - 1) + (1.0/(n*(n+2))))*10000)/10000;
}
/**
 * @brief random values from 0 to 49
 * 
 * @return int 
 */
int FillRandomNum()
{
    return rand() % 50;
}
/**
 * @brief get the max value in an array
 * 
 * @param arr : array of integers of random numbers from 0 to 49
 * @param startingIndex : the first index of the array, integers
 * @param size : The length of the array, integers
 * @return int 
 */
int Max(int *arr, int startingIndex, int size)
{
    if (startingIndex + 1 == size) {
        return arr[startingIndex];
    }
    // Divide-and-conquer
    int midIndex = startingIndex + (size - startingIndex) / 2;
    int leftMax = Max(arr, startingIndex, midIndex);
    int rightMax = Max(arr, midIndex, size);
    
    if(leftMax >= rightMax){
        return leftMax;
    }
    return rightMax;
}

int main()
{
    srand(time(0));
    cout << "Enter the number of values you want to find the sum of the series: ";
    int n;
    cin >> n;
    cout << "The sum is: " << F(n) << endl;
    
    int startingIndex = 0;
    cout << "The length of the array is: ";
    int size;
    cin >> size;
    // create an array
    int *arr = new int[size];
    for(int i = 0; i < size; i++){
        // get random numbers
        arr[i] = FillRandomNum();
        // print out the array
        cout << arr[i] << "\t";
    }
    cout << endl;
    int max = Max(arr, startingIndex, size);
    cout << "The max value in the array is: " << max; 

    if(arr != nullptr){
        delete[] arr;
        arr = nullptr;
    }
 
    return 0;
}
