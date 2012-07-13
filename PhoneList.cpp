#include <iostream>
#include <fstream>
#include <iomanip>
#include "PhoneRec.h"
#include "PhoneList.h"


using namespace std;

PhoneList::PhoneList()
{
 fname = 0;
 modified = false;   
}//end default constructor
//************************************
//  default constructor 
//  sets fname to 0
//  and bool var to false
//*****************************

PhoneList:: PhoneList(PhoneList& rPL)
{
    int i;
    for(i=0; i = size-1; i++)
    {
        theList[i] = rPL.theList[i];
    }//end for
    
    fname = 0;
    modified = false;
}//end copy constructor
//*************************************
//  copy constructor, for use in copying elements from one
//  object to another 
//  the for loop goes through each element in the object 
//  and copying it to another
//  sets fname to 0 and bool var to false
//*****************************************

PhoneList::~PhoneList()
{
}//end destructor
//****************************
// destructor, does nothing
//**********************************

PhoneList& PhoneList::operator=(PhoneList& rPL)
{
    int i;
    if(&rPL != this)
    {
        for(i=0; i = size - 1; i++)
        {
            theList[i] = rPL.theList[i];
        }//endfor
    }//endif
    fname = 0;
    modified = true;
    return *this;
}//end overlaoded assinment

//*************************************************
//  assinment overloaded operator 
//  for use in copying from one object ot another 
//  if statement check for the reference object rPL is not equal to
//  object in question(this)
//  see above for description of for loop
//*********************************************

bool PhoneList::isModified()
{
    return modified;
}//end ifModified
//********************************
//  bool function, returns modified
//*********************************


void PhoneList::edit()
{
    char c;
    int i;
    int ac = 0;
    int ex = 0;
    int num = 0;
    string buf;
    
    cout << "please enter a record: " << endl;
    cin >> i;
    i--;
    cin.ignore();
    
    if(i >= 0 && i < size)
    {
        cout << "Enter the informationi for this record(format ex: ima winner, 123-456-7898)" << endl;
        cin >> theList[i];
        modified = true;
    }//end if
}//end edit

//******************************************
//  function edit
//  adds record if user wants to
//  prompts user to enter a record,
//  decreases it by 1, and then gets rid of the newline
//  by the cin(cin.ignore) 
//  if statement makes sure tah tteh record entered by the user
//  is within the requirements of the list
// also sets modified to true
//*****************************************8

void PhoneList::open(char* fnam)
{
    char buf[512];
    ifstream fin;
    int i;
    
    if(fname != 0)
    {
        delete fname;
    }//end if
    
    fname = new char[strlen(fnam) + 1];
    strcpy(fname, fnam);
    fin.open(fname);
    
    for(i=0; i <= size - 1; i++)
    {
        fin >> theList[i];   
        
    }//end for
    fin.close();
}//end open
//***************************************************
//  functino open, opens file
//  checks if fname is not equal to 0
//  deletes name if so
//  then sets fname to a new pointer to fnam
//  copies fname into fnam
//  opens the file 
//  for loop copies elements to file
//**************************************************


void PhoneList::print()
{
    int i;
    
    for(i=0; i <= size - 1; i++)
    {
        cout << right << setfill(' ')<< setw(2) << (int)(i+1) << "." <<endl;
        char* rec = theList[i].toString();
        cout << rec << endl;
    }//end for
}//end print
//******************************************
//  function open
//  outputs elements to the screen
//*****************************************


void PhoneList::save()
{
    char buf[512];
    int i;
    ofstream fout;
    char* cp;
    
    if(fname != 0)
    {
        fout.open(fname);
            for(i=0; i <= size - 1; i++)
            {
                fout << theList[i] << endl;
                
            }//endfor
        fout.close();
        modified = false;
    }//end if
}//endsave

//************************************************************
//  function save
//  saves to the file set above 
//  checks if fname is not equal to 0
//  opens the file
//  the for loop goes through each element and outputs it to the file
//  then sets modifed to false
//*******************************************************88







