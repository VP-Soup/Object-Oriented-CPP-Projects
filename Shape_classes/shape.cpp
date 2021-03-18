#include "shape.h"

Shape::Shape()
{
    area =1.0;
    perimeter = 1.0;
}
Shape::Shape(double area,double perimeter)
{
    this->area = area;
    this->perimeter =perimeter;
}
void Shape::setArea(double area)
{
    if(area <1.0)
        this->area = 1.0;
    else
        this->area =area;
}
void Shape::setPerimeter(double perimeter)
{
    if(perimeter <1.0)
        this->perimeter = 1.0;
    else
        this->perimeter =perimeter;
}
double Shape::getArea()
{
        return area;
}
double Shape::getPerimeter()
{
        return perimeter;
}


