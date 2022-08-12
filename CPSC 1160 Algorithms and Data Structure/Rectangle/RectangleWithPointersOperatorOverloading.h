#include <iostream>

using namespace std;

#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle {
private:
	double* width;
	double* height;

public:
	double GetArea() const{
		return *width * *height;
	}

	Rectangle() {
		width = new double;
		height = new double;
		*width = 0;
		*height = 0;
	}

	Rectangle(double w, double h) {
		width = new double;
		height = new double;
		SetWidth(w);
		SetHeight(h);
	}

	// copy constructor - creates a new object based off of an existing object
	// a deep copy
	Rectangle(const Rectangle& copyFrom){
		width = new double;
		height = new double;

		*width = *(copyFrom.width);
		*height = *(copyFrom.height);

		// // shallow copy
		// width =   copyFrom.width;
		// height = copyFrom.height;
	}

	~Rectangle(){
		cout << "destructor called " << 
		"for rectangle with width " << *width << endl;

		if(width){
			delete width;
			width = nullptr;
		}
		
		if(height){
			delete height;
			height = nullptr;
		}
	}

	void SetWidth(double w) {
		if (w < 0) {
			cout << "Invalid width value. Cannot be negative" << endl;
			return;
		}
		*width = w;
	}

	double GetWidth() const {
		return *width;
	}

	void SetHeight(double h) {
		if (h < 0) {
			cout << "Invalid height value. Cannot be negative" << endl;
			return;
		}
		*height = h;
	}

	double GetHeight() const {
		return *height;
	}

	Rectangle operator=(const Rectangle& right){
		

		*width = *(right.width);
		*height = *(right.height);

		return *this;
	}
	// overload the * operator so that it is capable of multiplying two rectangles
	// When w rectangles are multiplied their widths and heights are multiplied serarately
	// Rectangles rProduct = r1 * r2;// r1 and r2 are rectangles
	Rectangle operator*(const Rectangle& right){
		Rectangle newRect = Rectangle();
		*(newRect.width) = *width* *(right.width);
		newRect.SetHeight(*height * *(right.height));
		return newRect;
	}

	// overload the > operator so that it is capable of comparing two rectangles
	// bool b = r1 > r2; // b will be true if r1's area is greater than r2's area
	// test overloaded operators in a main function
	bool operator > (const Rectangle& right){
		// if(this->GetArea() > right.GetArea()){
		// 	return true;
		// }
		// else{
		// 	return false;
		// }
		if(this->GetWidth() > right.GetWidth() && this->GetHeight() > right.GetHeight()){
			return true;
		}
		else{
			return false;
		}
	}
	
	friend istream& operator >>(istream &in, Rectangle &right);
	
};
istream& operator >> (istream &in, Rectangle &right){
	cout << "Enter the width: ";
	double w;
	in >> w;
	cout << "Enter the height: ";
	double h;
	in >> h;

	right.SetWidth(w);
	right.SetHeight(h);

	return in;		
}
#endif // !RECTANGLE_H


