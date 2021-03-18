#include "linklist.h"
#include <string>
#include <iostream>

using namespace std;

// *****************************************************************
// * Function Name: LinkList()                                      *
// * Description: default constructor          *
// * Parameter Description: N/A
// * Date: 07/24/2020                                              *
// * Author: Vicente James C. Perez                                *
// * References:                                                   *
// *****************************************************************
LinkList::LinkList()
{
    head = new PieCake_struct;
    tail = new PieCake_struct;
    head->lname="                       ";
    tail->lname="ZZZZZZZZZZZZZZZZZZZZZZZ";
    head->next=tail;
    tail->prev=head;
    current = new PieCake_struct;
    count = 0;
}
// *****************************************************************
// * Function Name: ~LinkList()                                      *
// * Description: destructor         *
// * Parameter Description: N/A
// * Date: 07/24/2020                                              *
// * Author: Vicente James C. Perez                                *
// * References:                                                   *
// *****************************************************************
LinkList::~LinkList()   // Destructor
{}
// *****************************************************************
// * Function Name: Empty()                                  *
// * Description:  True = link list is empty, False otherwise      *
// * Parameter Description: N/A
// * Date: 07/24/2020                                              *
// * Author: Vicente James C. Perez                                *
// * References:                                                   *
// *****************************************************************
bool LinkList::Empty()
{
    return head->next->lname== tail->lname;
}
// *****************************************************************
// * Function Name: Size()                               *
// * Description:  accessor to count    *
// * Parameter Description: N/A
// * Date: 07/24/2020                                              *
// * Author: Vicente James C. Perez                                *
// * References:                                                   *
// *****************************************************************
int  LinkList::Size() 			// Returns number of records minus head and tail
{
    return count;
}
// *****************************************************************
// * Function Name: Find()                                  *
// * Description:  Looks for a record with the id, returns true if found, false otherwise. Sets the current to the
// * record found. Sets current to null if not found.     *
// * Parameter Description: idnumber - user input search parameter corresponding to member value id
// * Date: 07/24/2020                                              *
// * Author: Vicente James C. Perez                                *
// * References:                                                   *
// *****************************************************************

bool LinkList::Find(const int idnumber)
{
    if (head->next==tail)
        return false;
    else
    {
        current = head->next;
        for (int i = 0; i < count; i++)
        {
            if (current->id == idnumber)
                return true;
            else
                current = current->next;
        }
        current = nullptr;
        return false;
    }
}

// *****************************************************************
// * Function Name: Insert()                               *
// * Description:     Inserts a record into the list. *
// * Parameter Description: p is a source structure to be copied and inserted into the linked list
// * Date: 07/24/2020                                              *
// * Author: Vicente James C. Perez                                *
// * References:                                                   *
// *****************************************************************
void LinkList::Insert(PieCake_struct * p)
{
    PieCake_struct * New = new PieCake_struct;

    //validation for each parameter
    New->lname = p->lname;
    New->fname = p->fname;
    New->id = p->id;
    New->mi = p->mi;
    New->sex = p->sex;
    New->pORc = p->pORc;

    if (head->next==tail)
    {
        head->next = New;
        tail->prev = New;
        New->next = tail;
        New->prev = head;
        count++;
    }
    else
    {
        current = head->next;
        while (!(New->lname < current->lname && New->lname > current->prev->lname))
            current = current -> next;
        current->prev->next = New;
        New->prev=current->prev;
        New->next= current;
        current->prev = New;


        count++;
        current = nullptr;
    }
}


// *****************************************************************
// * Function Name: Delete()                               *
// * Description:    Deletes current record. Must use Find() to locate the record.  *
// * Parameter Description: N/A
// * Date: 07/24/2020                                              *
// * Author: Vicente James C. Perez                                *
// * References:                                                   *
// *****************************************************************

bool LinkList::Delete()
{
    if (current==nullptr)
        return false;
    else
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        count--;
        return true;
    }
}

// *****************************************************************
// * Function Name: Print()                               *
// * Description:    Prints out all records
// * Parameter Description: N/A
// * Date: 07/24/2020                                              *
// * Author: Vicente James C. Perez                                *
// * References:                                                   *
// *****************************************************************
void LinkList::Print()
{
    cout << "\t*****\tThe Cheesecak Survey\t*****\n";
    cout << "id\tlname\t\tfname\t\tmi\t\tSex\t\tPie/Cake\n";

    int PieCount=0;
    int CakeCount=0;
    current = head->next;
    for (int i=0; i<count; i++)
    {
        cout<<current->id<<"\t"<<current->lname<<"\t\t\t"<<current->fname<<"\t\t\t";
        cout<<current->mi<<"\t"<<current->sex<<"\t"<<current->pORc<<endl;
        if (current->pORc=='P')
            PieCount++;
        else
            CakeCount++;
        current = current->next;
    }
    cout <<"Total number surveyed: "<<count<<endl;
    cout <<"Number who think Pie:"<<PieCount<<endl;
    cout <<"Number who think Cake:"<<CakeCount<<endl;

}

// *****************************************************************
// * Function Name: List()                               *
// * Description:   Prints current record
// * Parameter Description: N/A
// * Date: 07/24/2020                                              *
// * Author: Vicente James C. Perez                                *
// * References:                                                   *
// *****************************************************************
void LinkList::List() 			// instructions says see example - there is no example in assignment file
{
    cout << "id\tlname\t\tfname\t\tmi\tSex\tPie/Cake\n";
    cout<<current->id<<"\t"<<current->lname<<"\t\t"<<current->fname<<"\t\t";
    cout<<current->mi<<"\t"<<current->sex<<"\t"<<current->pORc<<endl;
}

// *****************************************************************
// * Function Name: CountPie()                               *
// * Description:  returns count of records that chose pie
// * Parameter Description: N/A
// * Date: 07/24/2020                                              *
// * Author: Vicente James C. Perez                                *
// * References:                                                   *
// *****************************************************************
int LinkList::CountPie()		// Returns number of records that thought Cheese Cake isis Pie.
{
    int PieCount=0;
    int CakeCount=0;
    current = head->next;
    for (int i=0; i<count; i++)
    {
        if (current->pORc=='P')
            PieCount++;
        else
            CakeCount++;
        current = current->next;
    }
    return PieCount;
}
// *****************************************************************
// * Function Name: CountCake()                               *
// * Description:  returns count of records that chose cake
// * Parameter Description: N/A
// * Date: 07/24/2020                                              *
// * Author: Vicente James C. Perez                                *
// * References:                                                   *
// *****************************************************************
int LinkList::CountCake()       // Returns the number of records that thought Cheese Cake is Cake.
{
    {
        int PieCount=0;
        int CakeCount=0;
        current = head->next;
        for (int i=0; i<count; i++)
        {
            if (current->pORc=='P')
                PieCount++;
            else
                CakeCount++;
            current = current->next;
        }
        return CakeCount;
    }
}