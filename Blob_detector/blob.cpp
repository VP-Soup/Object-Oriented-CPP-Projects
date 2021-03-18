/* Name: Vicente James Caballero Perez
Date: 6/19/2020
Section: 3330
Assignment: Blob Detector
Due Date: 6/19/2020
About this project: Detect blobs in input file, print image, output number of blobs and where they were detected
Assumptions:

All work below was performed by Vicente James Caballero Perez */

#include <iostream>
#include <fstream>

using namespace std;

// prototype for function for finding blobs
int blobFinder(char**, int, int, int, int);

// prototype for function that prints the image of the blob
void printImage(char**, int, int);

int main()
{
    const int imgRows = 20;			// Given image row count.
    const int imgCols = 70;			// Given image column count.
    const int arrRows = imgRows+2;	// Expanded array rows for assignment specs
    const int arrCols = imgCols+2;	// Expanded array columns for assignment specs
    ifstream inFile;
    char nextChar;					// Temporary character placeholder
    int blobCount = 0;				// # of blobs found

    // Creating the 2D array for file to be read into
    char** image = new char*[arrRows];
    for(int indexRow = 0; indexRow < arrRows; indexRow++)
    {
        image[indexRow] = new char[arrCols];
    }

    inFile.open("blob.txt", ifstream::in);

    // Reading file into array
    for(int indexRow = 0; indexRow < imgRows; indexRow++)
    {
        for( int indexCol = 0; indexCol < imgCols; indexCol++ )
        {
            inFile.get(nextChar);
            image[indexRow+1][indexCol+1] = nextChar;
        }
        // Reading the return line character
        inFile.get(nextChar);
    }

    inFile.close();

    //printing Image array
    printImage(image, imgRows, imgCols);

    // Searching for blobs
    for(int indexRow = 1; indexRow < arrRows-1; indexRow++){
        for( int indexCol = 1; indexCol < arrCols-1; indexCol++ )
        {
            if( blobFinder(image, arrRows, arrCols, indexRow, indexCol) == 1 )
            {
                blobCount += 1;
                cout << "Found one at row=" << indexRow << " and col=" << indexCol << endl;
            }
        }
    }

    cout << "There are " << blobCount << " BLOBS in the file" << endl;

    for(int indexRow = 0; indexRow < arrRows; indexRow++)
    {
        delete image[indexRow];
    }

    delete[] image;
}

int blobFinder(char** image, const int arrRows, const int arrCols, const int searchRow, const int searchCol)
{
    int found = 0;      //return value

    // Check if a blob exists at this location.
    if( image[searchRow][searchCol] != ' ' )
    {
        found = 1;
        // clear the x
        image[searchRow][searchCol] = ' ';
        // Search up.
        if(searchRow > 1)
        {
            blobFinder(image, arrRows, arrCols, searchRow-1, searchCol);
        }
        // Search right.
        if( searchCol < arrCols-2 )
        {
            blobFinder(image, arrRows, arrCols, searchRow, searchCol+1);
        }
        // Search down.
        if( searchRow < arrRows-2 )
        {
            blobFinder(image, arrRows, arrCols, searchRow+1, searchCol);
        }
        // Search left.
        if( searchCol > 1)
        {
            blobFinder(image, arrRows, arrCols, searchRow, searchCol-1);
        }
        // Searching upper right diagonal
        if( searchCol < arrCols-2 && searchRow > 1)
        {
            blobFinder(image, arrRows, arrCols, searchRow-1, searchCol+1);
        }
        // Search lower right diagonal
        if( searchCol < arrCols-2 && searchRow < arrRows-2)
        {
            blobFinder(image, arrRows, arrCols, searchRow+1, searchCol+1);
        }
        // Search lower left diagonal
        if( searchCol > 1 && searchRow < arrRows-2)
        {
            blobFinder(image, arrRows, arrCols, searchRow+1, searchCol-1);
        }
        // Search upper left diagonal
        if( searchCol > 1 && searchRow > 1)
        {
            blobFinder(image, arrRows, arrCols, searchRow-1, searchCol-1);
        }
    }

    return found;
}

void printImage(char** image, const int imgRows, const int imgCols)
{

    // Print the header.

    // Print tens label row.
    const int tensCount = imgCols/10;
    for( int indexTens = 0; indexTens < tensCount; indexTens++ )
    {
        cout << "         " << indexTens+1;
    }
    cout << endl;

    // Print ones label row.
    for( int onesCount = 0; onesCount < imgCols; onesCount++ )
    {
        cout << (onesCount+1)%10;
    }
    cout << endl;

    // Print the image.
    for( int indexRow = 0; indexRow < imgRows; indexRow++ )
    {
        for( int indexCol = 0; indexCol < imgCols; indexCol++ )
        {
            cout << image[indexRow+1][indexCol+1];
        }
        cout << endl;
    }
}
