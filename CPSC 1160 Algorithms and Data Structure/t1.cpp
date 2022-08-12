#include <iostream>
using namespace std;
int main(){
    int n;
    // like println in java
    cout << "Welcome to 1160" << endl;
    cout << "Enter an integer" << endl;
    // get input like scanner in java
    cin >> n;
    cout << n + 1;
    //Arithmetic operators
    int t = 1+5/2;
    //cout << t << endl;
    //If statements
    int x = 5;
    int y = 10;
    if (x > y){
        cout << "First" << endl;
    }
    else{
        cout << "Second" << endl;
    }
    // arrays
    int size = 4;
    int* m = new int[size];
    m[0] = 20;
    m[1] = 30;
    m[2] = m[0] + 20;
    for(int i = 0; i < size; i++){
        cout << "Val @" << i << "=" << m[i] << endl;
    }
    int *ptr = new int[10];
    cout << ptr << endl;
    delete []ptr;
    cout << ptr << endl;

    return 0;
}