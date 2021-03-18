// Created by David A Gaitros on 10/15/19 - Implemented by Vicente James C. Perez on 07/17/2020
// ******************************************************************** 
// * Name: Stack Class                                                * 
// * Description:  A template Stack class designed to be used with    * 
// *   any simple C++ type to include floating point, double          * 
// *   floating point, character, and boolean.                        *
// *   The stack pointer, as is the convention, points to the last    * 
// *   or highest element in the array. So if you allocate 100        * 
// *   elements of type "T" then the first empty element will be 99.  * 
// * Author: Dr. David A. Gaitros - Vicente James C. Perez            *
// * Date:  07/17/2020                                                *
// ********************************************************************
#include <iostream>
#include <vector>

using namespace std;
const int DEFAULTSIZE=100;

template <class T>
class Stack {
public:
    Stack();                    // Default Constructor, stack is size 100.
    explicit Stack(int size);      // Constructor, creates stack of size "size"
    Stack(const Stack<T> & item);// Copy constructor
    bool Full();                // Return true if the stack is full
    bool Empty();               // Return true if the stack is empty
    int Size();                 // Return the size of the stack
    T Top();                    // Returns the top element, does not pop it.
    bool Push (T item);   // Put an item on the stack.
    bool Pop();                 // Pop an item off and display to std out

    // *****************************************************************
    // * Function Name: friend ostream &operator <<(ostream & os, Stack<T> & s)                                      *
    // * Description: friend function for overloading ostream operator to output to template values            *
    // * Parameter Description: ostream operator - to be overloaded, s is the class Stack
    // * used for writing the overloaded defintion of the operator
    // * Date: 07/17/2020                                              *
    // * Author: Vicente James C. Perez                                *
    // * References:                                                   *
    // *****************************************************************
   friend ostream &operator <<(ostream & os, Stack<T> & s)
   {
        // Place the code to test to see if the stack is empty and
        // if so send an error message out to the os ;
        if (s.Empty())
        {
            os << "Error: empty stack";
            return os;
        }
            //  If the stack is not empty, return the top item to the os and
            //  have it function the same way as the Pop() member function.
        else
        {
            os << s._stack[s._top];
            s._top--;
            return os;
        }
   }

private:
    vector<T> _stack;                 // The "stack"
    int _size;                  // The number of elements the stack can hold
    int _top;                   // Points to the first empty node
};

// *****************************************************************
// * Function Name: Stack()                                        *
// * Description: default constructor for Class Stack              *
// * Parameter Description: N/A                                    *
// * Date: 07/17/2020                                              *
// * Author: Vicente James C. Perez                                *
// * References:                                                   *
// *****************************************************************
template <class T>
Stack<T>::Stack()
{
    _size = DEFAULTSIZE;
    _stack.resize(_size);
    _top = -1;
}

// *****************************************************************
// * Function Name: Stack(const int size)                          *
// * Description: explicit constructor for Class Stack             *
// * Parameter Description: size - user dictated integer taken in  *
// * as constant for vector sizing                                 *
// * Date: 07/17/2020                                              *
// * Author: Vicente James C. Perez                                *
// * References:                                                   *
// *****************************************************************
template <class T>
Stack<T>::Stack(const int size)
{
    if (size < 0)
        _size = DEFAULTSIZE;
    else
        _size = size;
    _stack.resize(_size);
    _top = -1;
}

// *****************************************************************
// * Function Name: Stack(const Stack<T> & item)                   *
// * Description: copy constructor for Class Stack                 *
// * Parameter Description: item - class Stack taken is as a const
// * reference - utilize private members _size and _stack elements
// * to initialize constructed Stack's vector
// * Date: 07/17/2020                                              *
// * Author: Vicente James C. Perez                                *
// * References:                                                   *
// *****************************************************************
template <class T>
Stack<T>::Stack(const Stack<T> & item)
{
    _size = item._stack.size();
    _stack.resize(_size);
    for (int i = 0; i < _size; i++)
        _stack[i] = item._stack[i];
    _top = _size-1;
}

// *****************************************************************
// * Function Name: Full                        *
// * Description: Tests truth value of  _stack being full          *
// * Parameter Description: N/a                                    *
// * Date: 07/17/2020                                              *
// * Author: Vicente James C. Perez                                *
// * References:                                                   *
// *****************************************************************
template <class T>
bool Stack<T>::Full()
{
    return (_top == _size - 1);
}

// *****************************************************************
// * Function Name: Empty
// * Description: Tests truth value of _stack being empty          *
// * Parameter Description: N/a                                    *
// * Date: 07/17/2020                                              *
// * Author: Vicente James C. Perez                                *
// * References:                                                   *
// *****************************************************************
template <class T>
bool Stack<T>::Empty()
{
    return (_top == -1);
}

// *****************************************************************
// * Function Name: Size                      *
// * Description: accessor to _size
// * Parameter Description: N/a                                    *
// * Date: 07/17/2020                                              *
// * Author: Vicente James C. Perez                                *
// * References:                                                   *
// *****************************************************************
template <class T>
int Stack<T>::Size()
{
    return _size;
}

// *****************************************************************
// * Function Name: Top
// * Description: accessor to _top element of _stack
// * Parameter Description: N/a                                    *
// * Date: 07/17/2020                                              *
// * Author: Vicente James C. Perez                                *
// * References:                                                   *
// *****************************************************************
template <class T>
T Stack<T>::Top()
{
    return _stack[_top];
}

// *****************************************************************
// * Function Name: Push
// * Description: puts an element on the _stack, Issues an error message
// * if you try to Push an element on a full _stack.
// * Parameter Description: item - of type T, as in dependent on the
// * chosen type for the constructed class, used as new element in _ stack
// * Date: 07/17/2020                                              *
// * Author: Vicente James C. Perez                                *
// * References:                                                   *
// *****************************************************************
template <class T>
bool Stack<T>::Push(T item)
{
   if (Full())
       return false;
   else
   {
       ++_top;
       _stack[_top] = item;
       return true;
   }
}

// *****************************************************************
// * Function Name: Pop
// * Description:prints then deletes _top element of _stack
// * Parameter Description: N/A
// * Date: 07/17/2020                                              *
// * Author: Vicente James C. Perez                                *
// * References:                                                   *
// *****************************************************************
template <class T>
bool Stack<T>::Pop()
{
    if (Empty())
        return false;
    else
    {
        cout << _stack[_top] << endl;
        _top--;
        return true;
    }
}

