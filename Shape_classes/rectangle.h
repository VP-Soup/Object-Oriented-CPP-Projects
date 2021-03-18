#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"


class Rectangle : Shape
{
private:
    double length,width;

public:
    Rectangle();
    Rectangle(double, double);
    void setLength(double);
    double getLength();
    void setWidth(double);
    double getWidth();
    void PrintData();
};


#endif
