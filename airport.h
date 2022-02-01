#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>
using namespace std;
class Airport{

    private:
        string cityName;
        bool north; // 1 for north, 0 for south
        int planesOnRunway;
        /* Flight* incomingFlights;
        Flight* outgoingFlights; */

    public:

        void setCityName(string x);
        void setNorth(int x);
        string getCityName() const;
        bool getNorth() const;
        friend ostream& operator<< (ostream &out, const Airport &a1);

};

#endif
