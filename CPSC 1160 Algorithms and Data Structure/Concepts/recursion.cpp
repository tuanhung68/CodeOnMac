#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
#include <cstdlib>
using namespace std;

// Sum numbers between m-n
int recursiveSum(int m, int n){// m = 2, n = 4
    if(m == n)
        return m;
    return m + recursiveSum(m + 1, n); // 2 + (3 + (4))
}

int factorial(int n){

    // step3: find smallest problem and return solution
    //Base case
    if (n == 0)
        return 1;
    //Step1: find a smaller problem and solve it
    int smallSolution = factorial(n - 1);

    //Step2: use small solution to solve big problem
    return smallSolution * n;
}
bool isVowel(char c){
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}
int countVowels(string s){
    // step3: find smallest possible problem(s) and its solution(s)
    if(s.size() == 1){
        if(isVowel(s[0])){
            return 0;
        }
        else {
            return 0;
        }
    }
    else if (s.size() == 0){
        return 0;
    }
    else {
        // step1: find a smaller problem and its solution
        char first = s.at(0); //s[0]
        string smallProblem = s.substr(1, s.size() - 1);
        int smallSolution = countVowels(smallProblem);

        // step2: use small solution to make big solution
        if(isVowel(first)){
            return 1 + smallSolution;
        }
        return smallSolution;
    }


}
void Generate(int *arr, int n){// hw
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 100;
    }
}
void Display(int *arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << ", ";
    }
}
// use /** enter
/**
 * @brief Take a slice (a piece) out of sourceArray where items begin at startIndex
 * and ends at endIndex including endIndex
 * 
 * Invalid parameters result
 * 
 * @param source : an array of integers
 * @param sourceSize : number of items in sourceArray, integer
 * @param startIndex : starting index of slice, integer, must be between 0 and (sourceSize - 1) both inclusive
 * @param endIndex : ending index of slice, integer, must be between 0 and (sourceSize - 1) both inclusive, endIndex >= startIndex
 * @param sliceArray : the items in the slice, memory allocated within this function
 * @param sliceSize : the number of items in sliceArray
 */
void Slice(int *sourceArray, int sourceSize, int startIndex, int endIndex, int *&sliceArray, int &sliceSize){// pass by reference
    if(sourceSize <= 0 || startIndex < 0 || startIndex >= sourceSize || 
    endIndex < 0 || endIndex >= sourceSize || startIndex > endIndex){
        cout << "Invalid parameters set for the function\n";
        sliceArray = nullptr;
        sliceSize = 0;
        return;
    }
    sliceSize = endIndex - startIndex + 1;
    sliceArray = new int[sliceSize];
    for(int i = startIndex, j = 0; i <= endIndex && j < sliceSize; i++, j++){
        sliceArray[j] = *(sourceArray + i);// *(sourceArray + i) == sourceArray[i]; go to the address, and dereference
    }
}
int Max(int *arr, int n){
    // step 3 base case
    if(n == 1){
        return arr[n - 1];// arr[0]
    }
    
    // else
    // step1: make small problems and its solution
    int m = Max(arr, n - 1);// ignore the last element
    // step2
    if (m > arr[n - 1]){
        return m;
    }
    return arr[n - 1];

}
int sum (int n){
    // sum from 0 to 10
    if (n == 0)
        return 0;
    return n + sum(n-1);
}
int main()
{
    srand(time(0));
    int size = 10;
    int *arr = new int[size];
    int *slice = nullptr;
    int sliceLength = 0;
    


    Generate(arr, size);
    Display(arr, size);
    cout << "The max is ";
    cout << Max(arr, size) << endl;
    Slice(arr, size, 1, 5, slice, sliceLength);
    cout << "The slice\n";
    Display(slice, sliceLength);

    if(arr != nullptr){
        delete[] arr;
        arr = nullptr;
    }
    if(slice != nullptr){
        cout << "Free memory for the slice";
        delete[] slice;
        slice = nullptr;
    }

    // // recursion = the precess in which a method calls itself continuously
    // int m = 2, n = 4;
    // int sum = recursiveSum(m, n);
    // // cout << "Sum is " << sum;
    // // int sum = 0;

    // // for(int i = m; i <=n; i++){
    // //     sum += i;
    // // }
    // // cout << "The sum from m to n is " << sum << endl;

    // // how to swap values of two variables without third variable
    // // int a = 20;
    // // int b = 10;

    // // a = a + b;//30
    // // b = a - b;//20
    // // a = a - b;//10
    // int x = 5;
    // cout << "Factorial of " << n << " is: " << factorial(x) << endl;

    // string s;
    // cout << "Enter a string: ";
    // getline(cin, s);
    // int i = countVowels(s);
    // cout << i << endl;
    // cout << sum(10) << endl;
    return 0;
}