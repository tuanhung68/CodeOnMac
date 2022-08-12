#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
// multidimensional array
// array of arrays
int getRandom(int min, int max){
    return rand() % (max - min + 1) + min;
}
void FillRandom(int** a, int rows, int cols, int min, int max){
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            a[r][c] = getRandom(min, max);
        }
    }
}
int main()
{   
    srand(time(0));
    // dynamic array
    //number of rows cols
    int rows, cols;
    cout << "Number of rows: ";
    cin >> rows;
    cout << "NUmber cols: ";
    cin >> cols;

    //a pointer to a pointer
    int **table = new int*[rows];// an integer array of pointers
    for(int i = 0; i < rows; i++){
        table[i] = new int[cols];
        for(int j = 0; j < cols; j++){
            table[i][j] = 0;
        }
    }
    FillRandom(table, rows, cols, 1, 10);
    

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    // Free up memory
    for(int i = 0; i < rows; i++){
        delete[] table[i];
        table[i] = nullptr; 
    }
    delete[] table;
    table = nullptr;



    return 0;
}