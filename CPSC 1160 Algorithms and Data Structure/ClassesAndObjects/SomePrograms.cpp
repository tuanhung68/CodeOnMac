#include <iostream>

using namespace std;
// custom data types 
struct Player{
    int health;
    int ammo;
};

int main(){

    Player p;
    p.health = 500;
    p.ammo = 200;

    return 0;
}