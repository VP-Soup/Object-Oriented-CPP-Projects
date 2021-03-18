#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"

class Triangle : Shape
{
private:
    double side1,side2,side3;

public:
    Triangle();
    Triangle(double, double, double);
    void setSide1(double);
    double getSide1();
    void setSide2(double);
    double getSide2();
    void setSide3(double);
    double getSide3();
    void PrintData();
};


#endif
