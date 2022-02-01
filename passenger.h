#ifndef PASSENGER_H
#define PASSENGER_H
#include <iostream>
#include <string>
#include "flight.h"
#include "passport.h"
using namespace std;


class Passenger : public User{

    protected:

        unsigned long long int CNIC;
        string name;
        int age;
        bool adult;
        Passport p1;
        int accountNumber;
        int PIN;
        double accountBalance;
        Flight f1;
        Flight* flightHistory;
        int NPAFSpoints;
        static int total;

    public:

        Passenger(unsigned long long int a=0, string x="", int b=0,string user="", string pass="", int pin=0 );

        //setters&getters
        void setCNIC(int x);
        void setName(string x);
        void setAge(int x);
        void setAccountNumber(int x);
        void setPin(int x);
        void setAccountBalance(double x);
        int getCNIC() const;
        string getName() const;
        int getAge() const;
        int getAccountNumber() const;
        int getPIN() const;
        double getAccountBalance() const;
        Passport& getPassport();
        void setPassport(Passport x);
        void setFlight(Flight x);
        int getTotal() const;
        //Other members
        void bookFlight();
        void cancelFlight();
        void pay();
        void calculatePoints(); 
        void updateDetails();
        void reserveSeat();
        void rescheduleFlight();

};

#endif
