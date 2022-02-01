#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User{

    protected:

        string username;
        string password;
        int backUpPin;

    public:

        User(string x="",string y="",int z=0);

        //setters&getters
        void setUsername(string x);
        void setPassword(string x);
        void setPin(int x);
        string getUsername() const;
        string getPassword() const;
        int setPin() const;
        //Other members
        void updateDetails();

        void displayAccount();
        


}; 

#endif
