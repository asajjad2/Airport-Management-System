#ifndef PASSPORT_H
#define PASSPORT_H

#include <iostream>
#include <string>
#include "time.h"
using namespace std;

class Passport{

    private:

        string country;
        string name;
        Time ExpiryDate;
        bool passport;//1 for has a passport, 0 for doesn't
        bool validity;
        int size;

    public:

        

        void checkValidity();
        Passport();
        Passport(Time b, bool c=0, string a= "", string d="");
        
        int getPassportNumber() const;
        bool getValidity() const;
        string getName();
        Passport* importAdultPassport(Passport* arr);
        Passport* importChildPassport(Passport* arr);
        void displayPassport();
        int getNumPassports() const;


};

#endif
