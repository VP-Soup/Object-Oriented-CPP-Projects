/* Name: Vicente James Caballero Perez
Date: 5/15/2020
Section: 3330
Assignment: Lottery Numbers Program
Due Date: 5/15/2020
About this project: Assumes proper integer input by user.

All work below was performed by Vicente James Caballero Perez */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getticket (int, int);                           //function for producing one ticket
string getmanytickets (int, int, int);               //function for producing many tickets

int main()
{
    int numbercount;                //number of numbers within each ticket
    int range;                      //highest possible value of a number within ticket
    int ticketcount;                //number of tickets

    //Begin User Input and Validation of input
    cout << "How many numbers would you like to be generated per ticket? (3-7).\n";
    cin >> numbercount;
    while (numbercount < 3 || numbercount > 7)
    {
        cout << "Please choose a number from 3-7. \n";
        cin >> numbercount;
    }
    cout << "What is the highest possible value you would like to be in the range of numbers? (45-70) \n";
    cin >> range;
    while (range < 45 || range > 70)
    {
        cout << "Please choose a value from 45-70. \n";
        cin >> range;
    }
    cout << "How many tickets would you like to generate? (1-100)\n";
    cin >> ticketcount;
    while (ticketcount < 1 || numbercount > 100)
    {
        cout << "Please choose a number from 1-100.\n";
        cin >> ticketcount;
    }
    //END User Input and Validation

    //Echoing User Input
    cout << "You will select " << numbercount << " numbers\n";
    cout << "The numbers will range from 1 to " << range << " .\n";
    cout << "There will be "<< ticketcount << " tickets.\n\n";

    //seed rand()
    srand(time(NULL));
    cout << "YOUR LOTTERY SELECTIONS ARE: \n";

    //calling function to produce desired number of tickets with given parameters.
    cout << getmanytickets(numbercount, range, ticketcount);

    return 0;
}

void getticket (const int numbercount, const int range)
{

    int rngTest;            //placeholder variable to hold randomly generated number to test if it is unique within ticket
    vector <int> ticket;    //vector array for holding ticket numbers

    //creating initial value for comparisons
    ticket.push_back(rand()%range +1);

    //loop for populating vector with appropriate number of numbers that are unique to each other
    for (int index=1; index < numbercount; index++)
    {
        rngTest = rand()%range + 1;
        //inner loop for validation of uniqueness
        for (int secondindex = 0; secondindex < index; secondindex++)
            while (rngTest == ticket[secondindex])
                rngTest = rand()%range + 1;
        ticket.push_back(rngTest);
    }

    //output all values in ticket
    for (int number : ticket)
    {
        cout << number <<"\t";
    }
    cout<<endl;
}

string getmanytickets (const int numbercount, const int range, const int ticketcount)
{
    //loop ticket generation for appropriate number of tickets.
    for (int index=0; index<ticketcount; index++)
    {
        getticket(numbercount, range);
        cout << endl;
    }

    return ("Good Luck!\n");
}