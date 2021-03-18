//date class header file

#ifndef DATE_H
#define DATE_H

class Date
{
private:
    int month, day, year;
    char format;
public:
    //Constructors
    Date();
    Date(int, int, int);

    //accessors
    int GetMonth();
    int GetDay();
    int GetYear();

    //date change
    void Input();
    bool Set(int, int, int);
    void Increment(int);

    //display functions
    bool SetFormat(char);
    void Show();

    //compare function
    int Compare(const Date&);

};

#endif
