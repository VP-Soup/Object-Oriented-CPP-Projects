#include <iostream>
#include "square.h"
#include <iomanip>

using namespace std;

Square::Square() : Shape()
{
    length =1.0;
    setArea(length*length);
    setPerimeter(4*length);
}
Square::Square(double length) : Shape()
{
    if(length <1.0)
        this->length = 1.0;
    else
        this->length =length;
    setArea(length*length);
    setPerimeter(4*length);
}
void Square::setLength(double length)
{
    if(length <1.0)
        this->length = 1.0;
    else
        this->length =length;
}
double Square::getLength()
{
    return length;
}
void Square::PrintData()
{
    cout<<setprecision(2) << fixed;
    cout<<"Square:\n\tlength: "<<length<<"\tArea: "<<getArea()<<" \tPerimeter: "<<getPerimeter() << endl;
}

