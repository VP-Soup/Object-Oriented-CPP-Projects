#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

class Circle : Shape
{
private:
    double radius;

public:
    Circle();
    Circle(double);
    void setRadius(double);
    double getRadius();
    void PrintData();
};

#endif
