#ifndef PHONELIST_H
#define PHONELIST_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include "PhoneRec.h"

enum listSize {size = 20};//creats max number of elements 

class PhoneList
{
  
  public:
        PhoneList();
        PhoneList(PhoneList&);
        ~PhoneList();
        //constructors
        PhoneList& operator=(PhoneList&);//assinment operator
        //class functions
        bool isModified();
        void edit();
        void open(char*);
        void print();
        void save();
        
    private:
        //class data
            bool modified;
            char* fname;
            PhoneRec theList[size];
};
#endif
