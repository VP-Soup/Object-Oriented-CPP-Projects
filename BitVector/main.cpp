#include <iostream>
#include "bitvector.h"
//
using namespace std;
int main() {
    BitVector  DefaultVector;
    BitVector  BigVector(500);
        DefaultVector.Set(); 		// Test set all bits to one.
    DefaultVector.Print(); 
    DefaultVector.Unset(); 		// Unset all bits.
    DefaultVector.Print();  
    DefaultVector.Set(32); 		// Set one bit.
    DefaultVector.Print();
    DefaultVector.Flip(32); 		// Flip the bit.
    DefaultVector.Flip(); 		// Test flip all.
    DefaultVector.Set(33); 		// Set one bit.
    DefaultVector.Unset(33); 		// Test Unset for a single bit.
    cout<< "Test the call to Test()" << DefaultVector.Test(16) << endl; 
    cout<< "Test the call to Size()" << DefaultVector.Size() << endl; 
    
    DefaultVector.Print();
    BitVector  CopyVector(DefaultVector);// Copy Constructor;
    CopyVector.Print();
    return 0;
}
