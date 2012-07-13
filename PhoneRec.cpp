#include <iostream>
#include <fstream>
#include <iomanip>
#include "PhoneRec.h"


using namespace std;

PhoneRec::~PhoneRec()
{
    if(name != 0)
    {
        delete name;   
    }//end if
}//enddestructor

//******************************
// destructor
//  if statement continues if name does not equal 0
//  deletes point name
//****************************

PhoneRec::PhoneRec()
{
name = 0;
areaCode = 0;
exchange = 0;
number = 0;    
    
}//end default constructor

//***********************************
//  default constructor
//  sets all var's in constructor to 0
//*************************************


PhoneRec::PhoneRec(char* pc, int p1, int p2, int p3)
{
    setName(pc);
    areaCode = p1;
    exchange = p2;
    number = p3;
}//end copy constructor

//*************************************
//  copy constructor
//  calls function setname with paramater pc
//  sets the rest of the var's to various numbered ints
//
//
//************************************

PhoneRec::PhoneRec(PhoneRec& rPR)
{
    setName(rPR.name);
    areaCode =rPR.areaCode;
    exchange = rPR.exchange;
    setNumber(rPR.number);
}//end some constructor

//*****************************************
//  random copy constructor constructor
//  sets var's to above as object rPR
//***************************************

PhoneRec& PhoneRec::operator=(PhoneRec& rPR)
{
     setName(rPR.name);
    areaCode =rPR.areaCode;
    exchange = rPR.exchange;
    setNumber(rPR.number);
    
    return *this;
}//end overloaded assinment

//*****************************************8
//  overloaded assinment operator
//  see above function for description
//  returns pointer to this
//****************************************8


char* PhoneRec::getName()
{
    return name;
}//end getname
//****************
//  returns var name
//****************

int PhoneRec::getAreaCode()
{
    return areaCode;
}//end areacode
//********************
//  returns var areaCode
//*********************

int PhoneRec::getExchange()
{
    return exchange;
}//end exchange
//***********************8
// returns var exchange
//***********************

int PhoneRec::getNumber()
{
    return number;
}//end number

//********************
//  returns var number
//*****************8

void PhoneRec::setName(char* nam)
{
    if(name !=0)
    
        delete name;
        name = new char(strlen(nam)+1);
        strcpy(name, nam);
   //got help with this functions
}//end setname

//****************************************
//  functiosn setName
//  continues if name does not equal 0
//  deletes pointer to name
//  creates new char pointer nam plus an extra at the end
//  copies name into nam
//*************************************

void PhoneRec::setAreaCode(int ac)
{  
    if(ac > 0)
    {
        areaCode = ac;
    }//end if
}//end setAreaCode
//***********************
//  continues if ac is greater than 0
//  sets areaCode to var ac
//*****************************

void PhoneRec::setExchange(int ex)
{
    if(ex > 0)
    {
        exchange = ex;
    }//end if
}//end setExchange

//************************
//  does same as above function
//  but with exchange and ex
//**********************

void PhoneRec::setNumber(int num)
{
    if(num > 0)
    {
        number = num;
    }//end if
    
}//end setNumber
//************************
//  see above function
//************************

char* PhoneRec::toString()
{
    static char str[50] = {'\0'};
    str[0] = '\0';
    sprintf(str, "%-20s(%03d) %03d-%04d", name, areaCode, exchange, number);
    return str;
}//end tostring
//*********************************************
// function(pointer) toString
//  creates static char(var) str of array 50 elements, and sets
//  all of them to 0
//  returns str
//******************************************888

ostream& operator<<(ostream& os, PhoneRec& rPR)
{
    if(rPR.name !=0)
    {
        os << rPR.name;
    }//endif
    
    os << "," << rPR.areaCode << "-" << rPR.exchange << "-" << rPR.number << endl;
    return os;
}//end overlaoded ostream
//**********************************************************
//  overloaded function insertion operator
//  continues if object.name is not equal to 0
//  outputs object rpr.name
//  ouputes rest in a set format
//  returns object os
//****************************************************

istream& operator>>(istream& is, PhoneRec& rPR)
{
    char nam[50] = {" "};
    int ac = 0;
    int ex = 0;
    int num = 0;
    string buf;
    
    getline(is, buf);
    sscanf(buf.c_str(), "%[^,], %d-%d-%d", nam, &ac, &ex, &num);
    rPR.setName(nam);
    rPR.setAreaCode(ac);
    rPR.setExchange(ex);
    rPR.setNumber(num);
    
    return is;
}//end overloaded istream

//*************************************************
//  overloaded exstraction function
//  creats char array nam of 50 elements and sets all
//  elements to " "
//  creats var ac, ex, and num, sets all to 0
//  gets user inputs from user for string buf
//  calls functions of object rPR
//***************************************************




