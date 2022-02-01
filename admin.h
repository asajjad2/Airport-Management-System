#include "user.h"
#include <iostream>
using namespace std;

class Admin : public User{

    private:

        string name;
        int age;
        static int total; //number of admins

    public:

        Admin(string a="", int b=0, string user="", string pass="", int pin=0);

        //setters&getters
        void setName(string x);
        void setAge(int x);
        string getName() const;
        int getAge() const;
        int getTotal() const;
        void incrementTotal();
        //Other members
        void createNewFlight();
        void cancelFlight();
        void changeSchedule();
        void restrictPassengers();
        void updateFlightDetails();

        Admin* importAdmins(Admin* arr);
        


};
