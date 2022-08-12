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
    double *largestX = new double;
    *largestX = xCoords[0];
    double *smallestX = new double;
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
    double *largestY = new double;
    *largestY = yCoords[0];
    double *smallestY = new double;
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
    double *width = new double;
    *width = *largestX - *smallestX;
    cout << "The width is: " << *width << endl;
    // Find the heigh
    double *height = new double;
    *height = *largestY - *smallestY;
    cout << "The height is: " << *height << endl;
    // Find center
    double *xCen = new double; 
    *xCen = *width/2.0 + *smallestX;
    double *yCen = new double; 
    *yCen = *height/2.0 + *smallestY;
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