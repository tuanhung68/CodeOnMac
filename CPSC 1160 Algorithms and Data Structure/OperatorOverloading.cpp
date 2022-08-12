#include <iostream>

using namespace std;

class Position{

    int x, y;
     
public:  
    // left is pos1, which is operator, right is pos2, which is pos
    Position(int x, int y){
        x = x;
        y = y;
    }
    Position operator + (Position &pos){
        // operator: pos1 + pos2(pos)
        Position newPos(0, 0);
        newPos.x = x + pos.x;
        newPos.y = y + pos.y;
        return newPos;
    }
};
class Complex{
public:
    int real, imag;

    Complex(int r, int i){
        real = r;
        imag = i;
    }
    void print(){
        cout << real << " + " << imag << "i" << endl;
    }

    Complex operator + (Complex &right){
        Complex newC(0, 0);
        newC.real = real + right.real;
        newC.imag = imag + right.imag;
        return newC;
    }
};

int main(){
    // Position pos1, pos2;
    // Position pos3 = pos1 + pos2;
    Complex c1(5, 4);
    Complex c2(2, 3);
    Complex c3(0, 0);
    c3 = c1 + c2;
    cout << c3.real;

    return 0;
}