#include <iostream>
#include <stdlib.h>
#include <time.h>
int main(){
    int size = 10;
    int *counts = new int[size];
    srand(time(0));
    for(int i = 0; i < 100; i++){
        int value = rand() % 10;
        counts[value]++;
    }
    for (int i = 0; i < size; i++) {
        std::cout << "Count for " << i << " is " << counts[i] << std::endl;
    }
    return 0;
}