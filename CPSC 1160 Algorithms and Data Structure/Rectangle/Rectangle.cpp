#include <iostream>
#include "RectangleWithPointersOperatorOverloading.h"
using namespace std;
int main(){
    Rectangle r1 = Rectangle(5, 10);
    Rectangle r2 = Rectangle(2, 3);

    Rectangle r3 = r1 * r2;
    if(r1 > r2){
        cout << "first rect has bigger area\n";
    }
    else{
        cout << "second rect has bigger area\n";
    
    }

    cout << r3.GetWidth() << ", " << r3.GetHeight() << endl;

    return 0;
}