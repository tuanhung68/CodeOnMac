#include <iostream>
#include <cmath>
using namespace std;
void showBoundingRectangle(int *N, double *xCoords, double *yCoords);
int main(){
    // Number of points
    cout << "The number of points: ";
    int *N = new int;
    cin >> *N;

    double *xCoords = new double[*N];
    double *yCoords = new double[*N];
    cout << "------------------" << endl;

    int *i = new int;
    cout << "Enter the value of X coors" << endl;
    for(*i = 0 ; *i < *N; (*i)++){
        cin >> xCoords[*i];
    }
    cout << "Enter the values of Y coords" << endl;
    for(*i = 0 ; *i < *N; (*i)++){
        cin >> yCoords[*i];
    }
    showBoundingRectangle(N, xCoords, yCoords);

    delete[] xCoords;
    xCoords = nullptr;
    delete[] yCoords;
    yCoords = nullptr;
    delete N;
    N = nullptr;
    delete i;
    i = nullptr;
    
    

    return 0;
}
void showBoundingRectangle(int *N, double *xCoords, double *yCoords){
    // Find the largest and smallest Coor of X
    int *largestX = new int;
    *largestX = xCoords[0];
    int *smallestX = new int;
    *smallestX = xCoords[0];

    int *i = new int;
    for(*i = 0 ; *i < *N; (*i)++){
        if(xCoords[*i] > *largestX){
            *largestX = xCoords[*i];
        }
        if(xCoords[*i] < *smallestX){
            *smallestX = xCoords[*i];
        }
    }
    // Find the largest  and smallest Coor of Y
    int *largestY = new int;
    *largestY = yCoords[0];
    int *smallestY = new int;
    *smallestY = yCoords[0];
    for(*i = 0 ; *i < *N; (*i)++){
        if(xCoords[*i] > *largestY){
            *largestY = yCoords[*i];
        }
        if(yCoords[*i] < *smallestY){
            *smallestY = yCoords[*i];
        }
    }
    // Find the width
    int *width = new int;
    *width = *largestX - *smallestX;
    cout << "The width is: " << *width << endl;
    // Find the heigh
    int *height = new int;
    *height = *largestY - *smallestY;
    cout << "The height is: " << *height << endl;
    // Find center
    int *xCen = new int; 
    *xCen = *width/2 + *smallestX;
    int *yCen = new int; 
    *yCen = *height/2 + *smallestY;
    cout << "The center x and y are: " << *xCen << ", " << *yCen << endl;

    delete largestX;
    largestX = nullptr;
    delete largestY;
    largestY = nullptr;
    delete smallestX;
    smallestX = nullptr;
    delete smallestY;
    smallestY = nullptr;
    delete i;
    i = nullptr;
    delete width;
    width = nullptr;
    delete height;
    height = nullptr;
    delete xCen;
    xCen = nullptr;
    delete xCen;
    yCen = nullptr;

}