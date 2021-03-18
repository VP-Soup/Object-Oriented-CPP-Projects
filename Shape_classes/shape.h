#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
private:
    double area, perimeter;

public:
    Shape();
    Shape(double, double);
    void setArea(double);
    void setPerimeter(double);
    double getArea();
    double getPerimeter();
    virtual void PrintData()=0;
};

#endif
