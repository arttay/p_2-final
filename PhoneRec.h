#ifndef PHONEREC_H
#define PHONEREC_H


#include <iostream>
#include <cstring>

using namespace std;

class PhoneRec
{
    public:
            PhoneRec();
            PhoneRec(char*, int, int, int);
            PhoneRec(PhoneRec&);
            ~PhoneRec();
            //constructors
            PhoneRec& operator=(PhoneRec&);//overloaded assinment operator
            
            
            //class functions
            char* getName();
            int getExchange();
            int getNumber();
            int getAreaCode();
            void setName(char*);
            void setAreaCode(int);
            void setExchange(int);
            void setNumber(int);
            char* toString();
            
    private:
        //class data
            char* name;
            int areaCode;
            int exchange;
            int number;
    
    //friend functions
  friend ostream& operator<<(ostream&, PhoneRec&);
  friend istream& operator>>(istream&, PhoneRec&);
    
    
    
    
};

#endif
