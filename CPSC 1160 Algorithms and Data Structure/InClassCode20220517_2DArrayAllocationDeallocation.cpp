#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void Display(int** a, int rows, int cols);

int GetRandom(int min, int max);

void FillRandom(int** a, int rows, int cols, int min, int max);
// fill the 2d array with random integers between min and max (both inclusive)

int main(){

    srand(time(0));

    int rows = 3, cols = 5;
    int** page = new int*[rows];

    for(int r = 0; r < rows; r++){
        page[r] = new int[cols];
        for(int c = 0; c < cols; c++){
            page[r][c] = 0;
        }
    } 
    FillRandom(page, rows, cols, 1, 6);
    Display(page, rows, cols);

    // freeing up memory for page (a 2D array)
    for(int r = 0; r < rows; r++){
        // first free each row
        delete[] page[r];
        page[r] = nullptr;
    }
    delete[] page;
    page = nullptr;
    
    return 0;
}

void Display(int** a, int rows, int cols){
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            cout << a[r][c] << " ";
        }

        cout << endl;
    }
}

int GetRandom(int min, int max){
    return rand() % (max - min + 1) + min;
}

void FillRandom(int** a, int rows, int cols, int min, int max){
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            a[r][c] = GetRandom(min, max);
        }
    }
}

