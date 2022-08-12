#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int getDice(){
    // current time
    srand(time(0));
    // 0 - 32767
    // 1 - 6
    int i1 = 1 + rand() % 6;
    int i2 = 1 + rand() % 6;

    cout << "You rolled " << i1 << " + " << i2 << " = " << (i1 + i2) << endl;
    return i1 + i2;
}
int main(){
    int dice = getDice();
    if (dice == 7 || dice == 11) {
      cout << "You win" << endl;
      //System.exit(1);
    }
    else if (dice == 2 || dice == 3 || dice == 12) {
      cout << "You lose" << endl;
      //System.exit(2);
    }

    int point = dice;
    cout << "point is " << point << endl;
    do {
      dice = getDice();
    } while (dice != 7 && dice != point);

    if (dice == 7)
      cout << "You lose" << endl;
    else
      cout << "You win" << endl;
    return 0;
}