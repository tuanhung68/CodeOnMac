#include <iostream>
#include <cmath>
using namespace std;
  /** Method for computing mean of an array of double values*/
double mean1(double* x, int length) {
  double sum = 0;
  for (int i = 0; i < length; i++)
    sum += x[i];

  return sum / length;
}

  /** Method for computing mean of an array of int values*/
double mean2(int* x, int length) {
  int sum = 0;
  for (int i = 0; i < length; i++){
    sum += x[i];
  }
  return sum / length;
}
  /** Method for computing deviation of double values*/
double deviation(double* x, int length) {
  double mean = mean1(x, length);
  double squareSum = 0;
  for (int i = 0; i < length; i++) {
    squareSum += pow(x[i] - mean, 2);
  }

  return sqrt(squareSum / (length - 1));
}

  /** Method for computing deviation of int values*/
double deviation(int* x, int length) { // or int x[]
  double mean = mean2(x, length);
  double squareSum = 0;
  for (int i = 0; i < length; i++) {
    squareSum += pow(x[i] - mean, 2);
  }

  return sqrt(squareSum / (length - 1));
}


  /** Method for printing array */
void printArray(double* x, int length) {
  for (int i = 0; i < length; i++)
      cout << x[i] << " ";
  cout << "" << endl;
}

int main(){
  const int SIZE = 10;
  double *numbers = new double[SIZE];
  cout << "Enter ten numbers: ";
  for (int i = 0; i < SIZE; i++) {
      cin >> numbers[i];
  }
  // Display mean and deviation
  cout << "The mean is " << mean1(numbers, SIZE) << endl;
  cout << "The standard deviation is " <<
    deviation(numbers, SIZE) << endl;
  return 0;
}
  
