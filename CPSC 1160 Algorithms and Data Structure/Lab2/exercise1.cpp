#include <iostream>
using namespace std;
int *locateLargest(double **a, int *rows, int *columns) {
    int *location = new int[2];
    
    double *largest = new double;
    *largest = a[0][0];

    int *m = new int;
    int *n = new int;
    for (*m = 0; *m < *rows; (*m)++)
      for (int *n = 0; *n < *columns; (*n)++) {
        if (*largest < a[*m][*n]) {
          *largest = a[*m][*n];
          location[0] = *m;
          location[1] = *n;
        }
      }
    
    return location;

    
}
int main(){
    int *numberOfRows = new int;
    int *numberOfColumns = new int;
    cout << "Enter the number of rows of the array: ";
    cin >> *numberOfRows;
    cout << "Enter the number of columns of the array: ";
    cin >> *numberOfColumns;

    double **a = new double*[*numberOfRows];
    cout << "Enter the array: ";
    int *i = new int;
    int *j = new int;
    for (*i = 0; *i < *numberOfRows; (*i)++){
        a[*i] = new double[*numberOfColumns];
    }
    for (*i = 0; *i < *numberOfRows; (*i)++){
      for (*j = 0; *j < *numberOfColumns; (*j)++){
          cin >> a[*i][*j];
        }
    }
    
    int *location = locateLargest(a, numberOfRows, numberOfColumns);
    cout << "The location of the largest element is at ("
     << location[0] << ", " << location[1] << ")" << endl;

    for(*i = 0; *i < *numberOfRows; (*i)++){
      delete[] a[*i];
      a[*i] = nullptr;
    }
    delete[] a;
    a = nullptr;

    delete i;
    i = nullptr;
    delete j;
    j = nullptr;


    delete numberOfRows;
    numberOfRows = nullptr;
    delete numberOfColumns;
    numberOfColumns = nullptr;
    
    
    return 0;
    
}
    
  
  


