#include <iostream>
#include <iomanip>
#include "date.h"
#include <string>

using namespace std;

int main ()
{
    Date d1;
    Date d2(1, 4, 2004);

    cout << "initial\n";
    d1.Show();
    d2.Show();
    cout << "accessors\n";
    cout << d1.GetMonth() << endl;
    cout << d1.GetDay() << endl;
    cout << d1.GetYear() << endl;
    cout<<"test input function\n";
    d1.Input();
    d1.Show();
    cout <<"testing set function\n";
    d1.Set(3, 2, 2020);
    d1.Show();
    cout << "format tests \n";
    cout << "invalid input test\n";
    d1.SetFormat('g');
    d1.Show();
    cout << "two digit\n";
    d1.SetFormat('t');
    d1.Show();
    cout <<"long\n";
    d1.SetFormat('l');
    d1.Show();
    cout <<"julian\n";
    d1.SetFormat('j');
    d1.Show();
    d1.SetFormat('D');
    cout<<"testing increment\n";
    d1.Increment(1);
    d1.Show();
    d1.Increment(300);
    d1.Show();
    cout<<"testing compare\n";
    d2.Show();
    cout << d1.Compare(d2);

    return 0;
}