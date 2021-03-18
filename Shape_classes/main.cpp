/* Name: Vicente James Caballero Perez
Date: 6/26/2020
Section: 3330
Assignment: Shape Classes
Due Date: 6/26/2020
About this project:
Assumptions:

All work below was performed by Vicente James Caballero Perez */

#include "square.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

int main()
{
    Square s1;
    s1.PrintData();
    Square s2(2);
    s2.PrintData();

    Rectangle r1;
    r1.PrintData();
    Rectangle r2(1, 2);
    r2.PrintData();

    Circle c1;
    c1.PrintData();
    Circle c2(2);
    c2.PrintData();

    Triangle t1;
    t1.PrintData();
    Triangle t2(1, 2, 3);
    t2.PrintData();

    return 0;
}
