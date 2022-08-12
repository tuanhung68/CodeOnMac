#include <iostream>
using namespace std;

int getRandom(int min, int max){
    return rand() % (max - min + 1) + min;
}

void fillRandom(double **a, int rows, int cols, int min, int max){
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            a[r][c] = getRandom(min, max);
        }
    }
}
void display(double **a, int rows, int cols){
  cout << "The values in the array: " << endl;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      cout << a[i][j] << " "; 
    }
    cout << endl;
  }
}

void locateLargest(double **a, int *rows, int *columns, int *x, int *y) {
    
    double *largest = new double;
    *largest = a[0][0];

    int *m = new int;
    int *n = new int;
    for (*m = 0; *m < *rows; (*m)++)
      for (*n = 0; *n < *columns; (*n)++) {
        if (*largest < a[*m][*n]) {
          *largest = a[*m][*n];
          *x = *m;
          *y = *n;
        }
      }
}
int main(){
    int *numberOfRows = new int;
    int *numberOfColumns = new int;
    cout << "Enter the number of rows of the array: ";
    cin >> *numberOfRows;
    cout << "Enter the number of columns of the array: ";
    cin >> *numberOfColumns;

    double **a = new double*[*numberOfColumns];
    cout << "Enter the array: ";
    int *i = new int;
    int *j = new int;
    for (*i = 0; *i < *numberOfRows; (*i)++){
        a[*i] = new double[*numberOfColumns];
        for (*j = 0; *j < *numberOfColumns; (*j)++){
            a[*i][*j] = 0;
        }
    }
    fillRandom(a, *numberOfRows, *numberOfColumns, 1, 9);
    display(a, *numberOfRows, *numberOfColumns);

    int locationX = 0;
    int locationY = 0;
    

    locateLargest(a, numberOfRows, numberOfColumns, &locationX, &locationY);
    
    cout << "The location of the largest element is at ("
    << locationX << ", " << locationY << ")" << endl;
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
    
  
  


