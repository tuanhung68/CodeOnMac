#include <iostream>
using namespace std;

// void cout(int n){
//     if(n >= 0){
//         cout << n << " " << endl;
//         cout(n - 1);
//     }
// }

int main()
{
    double *arr = new double[10];
    // cout << arr[0] << endl;
    // cout << &arr[3] << endl;
    int *a = new int;
    *a = 5;
    cout << a << endl;
    cout << *a << endl;
    int x = 10;
    int *y = &x;
    *y = 1;
    cout << x << endl;

    return 0;
}