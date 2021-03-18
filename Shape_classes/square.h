#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

class Square : public Shape
{
private:
    double length;

public:
    Square();
    Square(double);
    void setLength(double);
    double getLength();
    void PrintData();
};

#endif
