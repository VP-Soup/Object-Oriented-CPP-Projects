#include "bitvector.h"
#include <bitset>

BitVector::BitVector()     // Default constructor 256 bits
{
    size = (256 >> 5);
    bvect = new int [size];
    bitlocations = 0;
}
BitVector::BitVector (size_t index) 	// construct a BitVector With specified size BitVector
{
    if ((index >>5)==0)
        size = (index>>5);
    else
        size = (index>>5)+1;
    bvect = new int[size];
    bitlocations = 0;
}
BitVector::BitVector (const BitVector& a)	// Copy constructor
{
    size = sizeof(a.bvect);
    cout << sizeof(a.bvect) << endl;
    bvect = new int [size];
    for (int i=0; i<size; i++)
        bvect[i] = a.bvect[i];
    bitlocations = 0;
}
size_t BitVector::Size() const //size accessor
{
    return size;
}

BitVector::~BitVector() //destructor
{
    delete bvect;
}
void BitVector::Set (const size_t index) // Make index bit=1
{
    if (index <= size*32 & index >=0)
    {
        bvect[index >> 5] |= 1 << (index & 0x1f);
        bitlocations = index;
    }
    else
        cout << "Invalid input.\n";
}
void BitVector::Set () 			// Make all bits=1
{
    for (int i=0; i<(size*32); i++)
        bvect[i >> 5] |= 1 << (i & 0x1f);
}
void BitVector::Unset(const size_t index) 	// Make index bit=0
{
    if (index <= size*32 & index >=0)
    {
        bitlocations=index;
        if(bvect[index>>5] & 1<<(index & 0x1f))
            bvect[index>>5] ^= 1<<(index & 0x1f);
        else;
    }
    else
        cout << "Invalid input.\n";

}
void BitVector::Unset ()			// Make all bits=0
{
    for (int i=0; i<size; i++)
        bvect[i]=0;
}
void BitVector::Flip (const size_t index) 	// Flip index bit
{
    if (index <= size*32 & index >=0)
    {
        bitlocations=index;
        bvect[index>>5] ^= 1<<(index & 0x1f);
    }
    else
        cout << "Invalid input.\n";

}
void BitVector::Flip ()			// Flip all bits
{
    for (int i=0; i<size; i++)
        bvect[i] ^= 0xffffffff;         //hex for 4294967295 which sets 32 bits  = 1
}
bool BitVector::Test (size_t index) const 	// Return index bit value
{
    if (index <= size*32 & index >=0)
        return bvect[index>>5] & 1<<(index & 0x1f);
    else
    {
        cout << "Invalid input.\n";
        return false;
    }

}
void BitVector::Print()			// Prints index value and ascii value of bits turned on.
{
    cout << "Index value is: " << bitlocations <<endl;
    for (int i=0; i<size; i++)
        cout << "bvect["<<i<<"] = " << bitset<32>(bvect[i]) << endl;
}

BitVector& BitVector::operator = (const BitVector& bv)  //assignment operator
        {
                if (this != &bv)
                {
                    if (size != bv.size)
                    {
                        delete [] bvect;
                        size = bv.size;
                        bvect = new int [size];
                        if (bvect == 0)
                        {
                            std::cerr << "** BitVector memory allocation failure -- terminating program.\n";
                            exit (EXIT_FAILURE);
                        }
                    }
                    for (size_t i = 0; i < size; ++i)
                        bvect[i] = bv.bvect[i];
                }
                return *this;
        }




