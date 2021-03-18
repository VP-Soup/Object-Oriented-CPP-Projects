#include "circle.h"
#include <iostream>
#include <iomanip>

using namespace std;

Circle::Circle() : Shape()
{
    radius =1.0;
    setArea(3.14159265*radius*radius);
    setPerimeter(2*3.14159265*radius);
}
Circle::Circle(double radius) : Shape()
{
    if(radius <1.0)
        this->radius = 1.0;
    else
        this->radius = radius;
    setArea(3.14159265*radius*radius);
    setPerimeter(2*3.14159265*radius);
}
void Circle::setRadius(double radius)
{
    if(radius <1.0)
        this->radius = 1.0;
    else
        this->radius = radius;
}
double Circle::getRadius()
{
    return radius;
}
void Circle::PrintData()
{
    cout<<setprecision(2) << fixed;
    cout<<"Circle:\n\tRadius: "<<radius<<"\tArea: "<<getArea()<<" \tPerimeter: "<<getPerimeter() << endl;
}
