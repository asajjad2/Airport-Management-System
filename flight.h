#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
using namespace std;
#include "airplane.h"
#include "path.h"
#include "time.h"

class Flight{

    private:

        int ID;
        int total;
        string flightName;
        Airplane inUse;
        Path p1;
        Time departureTime;
        Time arrivalTime;
        double cost;
        double tax;
        /* Passenger* economy;
        Passenger* business; */
        
    
    public:
        
        Flight();
        int getID() const;
        void setID(int x);
        Airplane getPlane() const;
       
        Time getDepartureTime() const;
        Time getArrivalTime() const;
        void setPath(Path x);
        void setDepartureTime(int a,int b,int c, int d);
        double getCost() const;
        double getTax() const;
        /* void displayGeneralFlightInfo(){
            cout << "Flight#" << ID;
            p1.displayPath();
            cout << "\nDeparture:: " << departureTime << "Arrival:: " << arrivalTime;
        } */
        string getFlightName();
        void calculateFlightTime();
        void setFlightName(string x);
        void calculateAvailableSeats();
        void createFlight(Path* availablePaths, int numPaths);
        void calculateFare();
        Flight* importFlightData(Flight* f1, int numFlights, Path* availablePaths, int numPaths);

        void displayFlight();
        int getTotal() const;

        


};

#endif
