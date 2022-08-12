#include <iostream>
using namespace std;
void fun(int n)
{
    for(int i = 0; i < n; i++){
        cout << i << endl;
    }
}
void funRecursive(int i, int n)
{
    if(i < n){
        cout << i << endl;
        // or i++ then funRecursive(i, n)
        funRecursive(i + 1, n);// funRecursive(++i, n);
    }
}
int main()
{
    funRecursive(0, 5);
    return 0;
}