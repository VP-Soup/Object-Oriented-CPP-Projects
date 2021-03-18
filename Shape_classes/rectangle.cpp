#include "rectangle.h"
#include <iostream>
#include <iomanip>

using namespace std;

Rectangle::Rectangle() : Shape()
{
    length = width =1.0;
    setArea(length*width);
    setPerimeter(2*(length+width));
}
Rectangle::Rectangle(double length, double width) : Shape()
{
    if(length <1.0)
        this->length = 1.0;
    else
        this->length =length;
    if(width <1.0)
        this->width = 1.0;
    this->width =width;

    setArea(length*width);
    setPerimeter(2*(length+width));
}
void Rectangle::setLength(double length)
{
    if(length <1.0)
        this->length = 1.0;
    else
        this->length =length;
}
double Rectangle::getLength()
{
    return length;
}
void Rectangle::setWidth(double width)
{
    if(width <1.0)
        this->width = 1.0;
    else
        this->width = width;
}
double Rectangle::getWidth()
{
    return width;
}
void Rectangle::PrintData()
{
    cout<<setprecision(2) << fixed;
    cout<<"Rectangle:\n\tlength: "<<length<<"\tWidth: "<<width <<"\tArea: "<<getArea()<<" \tPerimeter: "<<getPerimeter() << endl;
}

