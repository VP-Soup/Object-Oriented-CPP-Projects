#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new> // Needed for bad_alloc exception
#include <cstdlib> // Needed for the exit function

using namespace std;

template <class T>
class SimpleVector
{
private:
    T *aptr; // To point to the allocated array
    int arraySize; // Number of elements in the array
    void memError() // Handles memory allocation errors
    {
        cout << "ERROR:Cannot allocate memory.\n";
        exit(EXIT_FAILURE);
    }
    void subError() // Handles subscripts out of range
    {
        cout << "ERROR: Subscript out of range.\n";
        exit(EXIT_FAILURE);
    }

public:
    // Default constructor
    SimpleVector()
    {
        aptr = 0; arraySize = 0;
    }

    // Constructor declaration
    SimpleVector(int size)
    {
        arraySize = size;
        // Allocate memory for the array.
        try
        {
            aptr = new T[size];
        }
        catch (bad_alloc)
        {
            memError();
        }

        // Initialize the array.
        for (int count = 0; count < arraySize; count++)
            *(aptr + count) = 0;
    }

    // Copy constructor declaration
    SimpleVector(const SimpleVector & sample)
    {
        // Copy the array size.
        arraySize = sample.arraySize;

        // Allocate memory for the array.
        aptr = new T[arraySize];
        if (aptr == 0)
            memError();

        // Copy the elements of sample's array.
        for (int count = 0; count < arraySize; count++)
            *(aptr + count) = *(sample.aptr + count);
    }

    // Destructor declaration - check to see if size > 0
    ~SimpleVector()
    {
        if (arraySize > 0)
            delete[] aptr;
    }

    // Accessor to return the array size
    int size() const { return arraySize;}

    // Accessor to return a specific element
    T getElementAt(int sub)
    {
        if (sub < 0 || sub >= arraySize)
            subError();
        return aptr[sub];
    }

    // Overloaded [] operator declaration
    T &operator[](const int & sub)
    {
        if (sub < 0 || sub >= arraySize)
            subError();
        return aptr[sub];
    }
};

#endif