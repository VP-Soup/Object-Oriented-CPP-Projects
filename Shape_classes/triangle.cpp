#include "triangle.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

Triangle::Triangle() : Shape()
{
    side1 =side2 =side3 =1.0;

    double s = (side1 +side2+side3)/2;
    setArea(sqrt(s*(s-side1)*(s-side2)*(s-side3)));
    setPerimeter(side1+side2+side3);
}
Triangle::Triangle(double side1,double side2, double side3) : Shape()
{
    if(side1 <=0.0)
        this->side1 = 1.0;
    else
        this->side1 = side1;
    if(side2 <=0.0)
        this->side2 = 1.0;
    else
        this->side2 = side2;
    if(side3 <=0.0)
        this->side3 = 1.0;
    else
        this->side3 = side3;
    double s = (side1 +side2+side3)/2;

    setArea(sqrt(s*(s-side1)*(s-side2)*(s-side3)));
    setPerimeter(side1+side2+side3);

}
void Triangle::setSide1(double side1)
{
    if(side1 <1.0)
        this->side1 = 1.0;
    else
        this->side1 = side1;
}
double Triangle::getSide1()
{

    return side1;
}
void Triangle::setSide2(double side2)
{
    if(side2 <1.0)
        this->side2 = 1.0;
    else
        this->side2 = side2;
}
double Triangle::getSide2()
{
    return side2;
}
void Triangle::setSide3(double side3)
{
    if(side3 <1.0)
        this->side3 = 1.0;
    else
        this->side3 =side3;
}
double Triangle::getSide3()
{
    return side3;
}
void Triangle::PrintData()
{
    cout<<setprecision(2) << fixed;
    cout<<"Triangle:\n\tside1: "<<side1<<"\tside2: "<<side2<<"\tside3: " <<side3<<"\tArea: "<<getArea()<<" \tPerimeter: "<<getPerimeter()<<endl;
}

