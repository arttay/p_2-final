//**********************************************************
//              Programmer: Art taylor
//              Final Lab: LoA
//              date: 6/19/2012
//
//              description:
//                          Acts as a phone book, asks user
//                          to enter various phone numbers 
//                          and names into records
//*******************************************************


#include <cstdlib>
#include <iostream>
#include <cctype>
#include "PhoneList.h"


using namespace std;

char menu();//function prototype for menu

int main(int argc, char *argv[])
{
    char c;
    PhoneList theList;//creates new object of type PhoneList
    
    if(argc<2)
    {
              theList.open("default.dat");
    }
    else
    {
        theList.open(argv[1]);
    }
//*********************************************
//  if statement continues when argc is less than two
//  otherwise it goes to open file argv of array index 1
//*****************************************
    
    theList.print();//calls function print, to initally print the records
    
    while((c=tolower(menu())) != 'q')
    {
        switch(c)
        {
            case 'e': 
                    theList.edit();
                    break;
            case 'l':
                    theList.print();
                    break;
            case 's':
                    theList.save();
                    break;
        }//endswitch
    }//endwhile
//***************************************************
//  while loop that houses main switch statement for menu 
//  the while loop continues while the user does not hit q(quit)
//  it also uses tolower, breaking down a capital if the user enters on
//  the switch statement calls various functions 
//*************************************************
if(theList.isModified())
{
    theList.save();
}//endif
//***********************************************
//  if statement that checks function isModified
//  is modified returns a bool var, the if statement    
//  checks if its true, and calls function save if so
//*****************************************8
                        
    
    system("PAUSE");
    return EXIT_SUCCESS;
}





char menu()//inline function menu
{
    string buf;
    
    cout << "(E)dit, (L)ist, (Q)uit" << endl;//outputs visual menu
    getline(cin, buf);//gets option user selected
    
    return buf[0];//returns string buf of array index 0
    
    
    
    
    
}//end menu
















