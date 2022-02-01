#include <string>
using namespace std;
#include "passenger.h"

class Adult : public Passenger{

    public:
        Adult(unsigned long long int a=0, string x="", int b=0,string user="", string pass="", int pin=0 );
        Adult* importAdults(Adult* arr,Passport* passArr, int passSize,Flight* flightArr, int flightSize);

        void displayPassengerInfo();

};
