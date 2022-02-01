#ifndef PATH_H
#define PATH_H

#include <string>
#include "time.h"
#include "airport.h"
using namespace std;

class Path{

    private:
        int id;
        Airport departureLocation;
        Airport transit;
        Airport arrivalLocation;
        Time flightTime;
        bool status; //1 for international, 0 for local
    
    public:

        int getID() const;
        Airport getDepartureLocation() const;
        Airport getArrivalLocation() const;
        Airport getTransit() const;
        void setDepartureLocation(int x, string city);
        Time getFlightTime() const;
        bool getStatus() const;
        void setStatus(bool x);
        void displayPath();
        Path* ImportPaths(Path* arr, int size);

};

#endif
