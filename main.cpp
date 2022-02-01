#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <iomanip>
#include <cstring>
#include "time.h"
#include "passport.h"
#include "user.h"
#include "airplane.h"
#include "airport.h"
#include "city.h"
#include "path.h"
#include "flight.h"
#include "passenger.h"
#include "adult.h"
#include "admin.h"
using namespace std;


class Time;
class Passport;
class User;
class Passenger;
class Admin;
class City;
class Airport;
class Flight;
class Airplane;
class path;


Time::Time(int m,int d, int h, int mi,int y){
    month = m;
    date = d;
    hours = h;
    min = mi;
    year = y;
}
void Time::setMonth(int x){
    month = x;
}
void Time::setDate(int x){
    date = x;
}
void Time::setHours(int x){
    hours = x;
}
void Time::setMin(int x){
    min = x;
}
void Time::setYear(int x){
    year = x;
}
int Time::getMonth() const{
    return month;
}
int Time::getDate() const{
    return date;
}
int Time::getHours() const{
    return hours;
}
int Time::getMin() const{
    return min;
}
int Time::getYear() const{
    return year;
}
Time Time::operator+(Time& t1){
    Time temp;
    temp.year = year + t1.year;
    temp.month = month + t1.month;
    temp.date = date + t1.date;
    temp.hours = hours + t1.hours;
    temp.min = min + t1.min;

    if(temp.min>=60){
        while(temp.min>=60){
            temp.min-=60;
            temp.hours++;
        }
    }

    return temp;
}


ostream& operator<< (ostream &out, const Time &t1){
    out << setw(0) << t1.hours << " h, " << t1.min << " min";
    return out;
}
bool operator> (const Time &d1, const Time &d2){

    bool check=false;
    if(d1.getYear()!=d2.getYear()){//different years
        if(d1.getYear()>d2.getYear())
            check=true;
    }
    else{

        if(d1.getMonth()!=d2.getMonth()){//same years, different months

            if(d1.getMonth()>d2.getMonth()){
                check=true;
            }

            
        }
        else{//same years, same months

            if(d1.getDate()>d2.getDate())
                check=true;
                
        }
    }
    return check;
}

        

void Passport::checkValidity(){
    bool temp;
    time_t now;
    now = time(NULL);
    tm *localTime = localtime(&now);
    Time current;
    current.setYear((localTime->tm_year)+1900);
    current.setMonth(localTime->tm_mon);
    current.setDate(localTime->tm_mday);
    if(current>ExpiryDate)
        validity = false;
    else
        validity = true;
}
Passport::Passport(){
    country = "";
    passport = 0;
    validity = false;
    name = "";
}
Passport::Passport(Time b, bool c, string a, string d){
    country = a;
    ExpiryDate = b;
    passport = c;
    name = d;
    checkValidity();
}

int Passport::getPassportNumber() const{
    return passport;
}
bool Passport::getValidity() const{
    return validity;
}
string Passport::getName(){
    return name;
}
Passport* Passport::importAdultPassport(Passport* arr){
    ifstream in("adult-passports.txt");
    int temp;
    in >> temp;
    for(int i=0;i<temp;i++){
        arr[i].size = temp;
        in >> arr[i].country >> arr[i].name;
        in >> arr[i].passport;
    }
    return arr;
}
Passport* Passport::importChildPassport(Passport* arr){
    ifstream in("children-passports.txt");
    in >> size;
    for(int i=0;i<size;i++){
        in >> country >> name;
        in >> passport;
    }
    return arr;
}
void Passport::displayPassport(){
    cout << "Nationality:" << country;
    cout << "\nName: " << name;
    cout << "\nHas a passport: " << passport << endl;
}
int Passport::getNumPassports() const{
    return size;
}





User::User(string x,string y,int z){
    username = x;
    password = y;
    backUpPin = z;
}

//setters&getters
void User::setUsername(string x){
    username = x;
}
void User::setPassword(string x){
    password = x;
}
void User::setPin(int x){
    backUpPin = x;
}
string User::getUsername() const{
    return username;
}
string User::getPassword() const{
    return password;
}
int User::setPin() const{
    return backUpPin;
}
//Other members
void User::updateDetails(){}

void User::displayAccount(){
    cout << "\nUsername: " << username << "  Password: ";
    int passLength = password.length();
    for(int i=0;i<passLength;i++){
        cout << "*";
    }
    cout << "  PIN " << "***" << endl;
}
        




string Airplane::getName() const{
    return name;
}
void Airplane::setName(string x){
    name = x;
}



string City::getName() const{
    return name;
}
        






void Airport::setCityName(string x){
    cityName = x;
}
void Airport::setNorth(int x){
    if(x==1||x==0){
        north = x;
    }
}
string Airport::getCityName() const{
    return cityName;
}
bool Airport::getNorth() const{
    return north;
}
ostream& operator<< (ostream &out, const Airport &a1);




int Path::getID() const{
    return id;
}
Airport Path::getDepartureLocation() const{
    return departureLocation;
} 
Airport Path::getArrivalLocation() const{
    return arrivalLocation;
}
Airport Path::getTransit() const{
    return transit;
}
void Path::setDepartureLocation(int x, string city){
    departureLocation.setCityName(city);
    departureLocation.setNorth(x);
}
Time Path::getFlightTime() const{
    return flightTime;
}
bool Path::getStatus() const{
    return status;
}
void Path::setStatus(bool x){
    status = x;
}
void Path::displayPath(){
    /* cout << departureLocation << "  --->  ";
    if(transit.getCityName()!="-")
        cout << transit;
    cout << "  --->  "  << arrivalLocation << "  FlightTime:: " << flightTime; */

    cout << left << setw(11) << departureLocation << " " << setw(9) << transit << " " << setw(16) << arrivalLocation << " " << setw(0) << flightTime << " " << id;

}
Path* Path::ImportPaths(Path* arr, int size){
    ifstream in("paths.txt");
    string Dcity,Acity,Tcity;
    int h, m;
    int temp_id;
    in >> size;
    for(int i=0;i<size;i++){
        //in >> id >> Dcity >> Tcity >> Acity;
        in >> temp_id >> Dcity >> Tcity >> Acity;
        arr[i].id = temp_id;
        arr[i].departureLocation.setCityName(Dcity);
        arr[i].transit.setCityName(Tcity);
        arr[i].arrivalLocation.setCityName(Acity);
        in >>  h >> m;
        arr[i].flightTime.setHours(h);
        arr[i].flightTime.setMin(m);
        in >> h;
        arr[i].setStatus(h);
    }
    return arr;
}



        
Flight::Flight(){
    ID = total;
    total++;
    /* economy = new Passenger[50];
    business = new Passenger[10]; */
    cost = 0;
    tax = 0;
}
int Flight::getID() const{
    return ID;
}
void Flight::setID(int x){
    ID = x;
}
Airplane Flight::getPlane() const{
    return inUse;
}

Time Flight::getDepartureTime() const{
    return departureTime;
}
Time Flight::getArrivalTime() const{
    return arrivalTime;
}
void Flight::setPath(Path x){
    p1 = x;
}
void Flight::setDepartureTime(int a,int b,int c, int d){
    departureTime.setMonth(a);
    departureTime.setDate(b);
    departureTime.setHours(c);
    departureTime.setMin(d);
}
double Flight::getCost() const{
    return cost;
}
double Flight::getTax() const{
    return tax;
} 
/* void displayGeneralFlightInfo(){
    cout << "Flight#" << ID;
    p1.displayPath();
    cout << "\nDeparture:: " << departureTime << "Arrival:: " << arrivalTime;
} */
string Flight::getFlightName(){
    return flightName;
}
void Flight::calculateFlightTime(){
    Time temp;
    arrivalTime = p1.getFlightTime()+departureTime;   
}
void Flight::setFlightName(string x){
    flightName = x;
} 
void Flight::calculateAvailableSeats(){}
void Flight::createFlight(Path* availablePaths, int numPaths){
    //display paths, ask for path id, create new route maybe, ask for departure time, calculate if landing possible, and then create or not, if created, export to file
}
void Flight::calculateFare(){
    int temp = p1.getFlightTime().getHours();
    if(p1.getStatus()){
        while(temp>0){
            cost+=20000;
            temp--;
        }
        tax = 0.1*cost;
    }
    else{
        while(temp>0){
            cost+=10000;
            temp--;
        }
        tax = 0.05*cost;
    }


}
Flight* Flight::importFlightData(Flight* f1, int numFlights, Path* availablePaths, int numPaths){
    ifstream in;
    in.open("flights.txt");
    int temp;
    in >> temp;
    int tempID,mon,dat,min,hour;

    
    string tempName;
    for(int i=0;i<temp;i++){
        in >> tempID;
        f1[i].total = temp;
        for(int j=0;j<numPaths;j++){
            //cout << tempID << " = " << availablePaths[j].getID() << endl;
            if(tempID == availablePaths[j].getID()){
                f1[i].setPath(availablePaths[j]);
                break;
            }
        }
        in >> mon >> dat >> hour >> min >> f1[i].flightName;
        //cout << mon << dat << hour << min << f1[i].flightName << endl;
        f1[i].setDepartureTime(mon,dat,hour,min);
        f1[i].calculateFlightTime();
        f1[i].calculateFare();
    }
    return  f1;
}

void Flight::displayFlight(){
    cout << left << setw(11) << flightName << " " << setw(11) << p1.getDepartureLocation();
    cout << " " << setw(9) << p1.getTransit() << " " << setw(16) << p1.getArrivalLocation() << " " << setw(14) << departureTime <<  "   " << setw(0) << arrivalTime;
}
int Flight::getTotal() const{
    return total;
}

        






ostream &operator<<(ostream &out, const Airport &a1)
{
    /* if(a1.north == 1){
        cout << "North Airport, ";
    }
    else if(a1.north == 0)
        cout << "South Airport, ";
 */
    out << a1.cityName;
    return out;
}


Passenger::Passenger(unsigned long long int a, string x, int b,string user, string pass, int pin ){

    CNIC = a;
    name = x;
    age = b;
    username = user;
    password = pass;
    backUpPin = pin;
    f1.setFlightName("-");
    total++;

}

//setters&getters
void Passenger::setCNIC(int x){
    CNIC = x;
}
void Passenger::setName(string x){
    name = x;
}
void Passenger::setAge(int x){
    age = x;
}
void Passenger::setAccountNumber(int x){
    accountNumber = x;
}
void Passenger::setPin(int x){
    PIN = x;
}
void Passenger::setAccountBalance(double x){
    accountBalance = x;
}
int Passenger::getCNIC() const{
    return CNIC;
}
string Passenger::getName() const{
    return name;
}
int Passenger::getAge() const{
    return age;
}
int Passenger::getAccountNumber() const{
    return accountNumber;
}
int Passenger::getPIN() const{
    return PIN;
}
double Passenger::getAccountBalance() const{
    return accountBalance;
}
Passport& Passenger::getPassport(){
    return p1;
}
void Passenger::setPassport(Passport x){
    p1 = x;
}
void Passenger::setFlight(Flight x){
    f1 = x;
}
int Passenger::getTotal() const{
    return total;
}




Adult::Adult(unsigned long long int a, string x, int b,string user, string pass, int pin ){

    CNIC = a;
    name = x;
    age = b;
    username = user;
    password = pass;
    backUpPin = pin;
    total++;

}
Adult* Adult::importAdults(Adult* arr,Passport* passArr, int passSize,Flight* flightArr, int flightSize){
    int size;
    Passport temp;
    Flight tempFlight;
    ifstream in("adults.txt");
    in >> size;
    string tempFlightNo;
    for(int i=0;i<size;i++)
    {
        arr[i].total = size;
        in >> arr[i].name >> arr[i].age >> arr[i].CNIC >> tempFlightNo;
        //cout << arr[i].name << arr[i].age << arr[i].CNIC << tempFlightNo << endl;
        for(int j=0;j<flightSize;j++){
            if(tempFlightNo==flightArr[j].getFlightName()){
                tempFlight = flightArr[j];
                //cout << tempFlightNo << flightArr[j].getFlightName() << endl;
                arr[i].setFlight(tempFlight);
                break;
            }

        }
        
    }
    
    adult = true;
    for(int i=0;i<size;i++){//this sets passports
        for(int j=0;j<passSize;j++){
            if(arr[i].name == passArr[j].getName()){
                temp = passArr[j];
                arr[i].setPassport(temp);
                break;
            }
        }
    }
    in.close();
    //getting account data
    in.open("accounts.txt");
    string tempName;
    string tempPass;
    int tempPin;
    for(int i=0;i<size;i++){
        in >> tempName >> tempPass >> tempPin;
        //cout << tempName << tempPass << tempPin << endl;
        for(int j=0;j<size;j++){
            if(tempName == arr[j].getName()){
                arr[j].setUsername(tempName);
                arr[j].setPassword(tempPass);
                arr[j].setPin(tempPin);
            }
        }
    }
    
    return arr;
}

void Adult::displayPassengerInfo(){
    cout << "Name: " << name << "\nAge: " << age << "\nCNIC: " << CNIC << "\n";
    f1.displayFlight();
    cout << endl;
    p1.displayPassport();
    this->displayAccount();
}




Admin::Admin(string a, int b, string user, string pass, int pin){
    name = a;
    age = b;
    username = user;
    password = pass;
    backUpPin = pin;
    total++;
}

//setters&getters
void Admin::setName(string x){
    name = x;
}
void Admin::setAge(int x){
    age = x;
}
string Admin::getName() const{
    return name;
}
int Admin::getAge() const{
    return age;
}
int Admin::getTotal() const{
    return total;
}
void Admin::incrementTotal(){
    total++;
}
//Other members
void createNewFlight();
void cancelFlight();
void changeSchedule();
void restrictPassengers();
void updateFlightDetails();

Admin* Admin::importAdmins(Admin* arr){
    int size;
    ifstream in("admins.txt");
    in >> size;
    string tempFlightNo;
    for(int i=0;i<size;i++)
    {
        arr[i].total = size;
        in >> arr[i].name >> arr[i].age;
        //cout << arr[i].name << arr[i].age << endl;
    }
    
    in.close();
    //getting account data
    in.open("admin-accounts.txt");
    string tempName;
    string tempPass;
    int tempPin;
    for(int i=0;i<size;i++){
        in >> tempName >> tempPass >> tempPin;
        //cout << tempName << tempPass << tempPin << endl;
        for(int j=0;j<size;j++){
            if(tempName == arr[j].getName()){
                arr[j].setUsername(tempName);
                arr[j].setPassword(tempPass);
                arr[j].setPin(tempPin);
            }
        }
    }
    
    return arr;
}
        



int Admin::total=0; 
int Passenger::total=0;

bool checkAdminAccount(Admin* arr){
        string tempName, tempPass;
        int index,i=0;
        bool checkName = false, checkPass=false;
        cout << "Please input your username\n";
        cin.ignore();
        getline(cin,tempName);
        for(i=0;i<arr[0].getTotal();i++){
            if(tempName == arr[i].getUsername()){
                checkName = true;
                index = i;
                break;
            }
        }
        if(checkName){
            cout << "Please input your password\n";
            cin >> tempPass;
            if(tempPass == arr[i].getPassword()){
                checkPass = true;
            }
        }
        if(checkName&&checkPass){
            cout << "Welcome, " << arr[i].getName() << "!" <<  endl;
            return true;
        }
        else{
            cout << "Wrong username or password\n";
            return false;
        }
            
        

}
bool checkPassengerAccount(Adult* arr){
    string tempName, tempPass;
        int index,i=0;
        bool checkName = false, checkPass=false;
        cout << "Please input your username\n";
        cin.ignore();
        getline(cin,tempName);
        for(i=0;i<arr[0].getTotal();i++){
            if(tempName == arr[i].getUsername()){
                checkName = true;
                index = i;
                break;
            }
        }
        if(checkName){
            cout << "Please input your password\n";
            cin >> tempPass;
            if(tempPass == arr[i].getPassword()){
                checkPass = true;
            }
        }
        if(checkName&&checkPass){
            cout << "Welcome, " << arr[i].getName() << "!" << endl;
            return true;
        }
        else{
            cout << "Wrong username or password\n";
            return false;
        }
            
        return arr;
}
bool checkPassword(string x){

    bool eightChars, specialChar, upperChar, lowerChar, digit;
    eightChars = specialChar = upperChar = lowerChar = digit = false;
    if(x.length()>=8){
        eightChars = true;
    }
    else 
        cout << "Password less than 8\n";
        
    
    for(int i=0;i<x.length();i++){
        if((x[i]>=97 && x[i]<=122)||(x[i]>=65 && x[i]<= 90)||(x[i]>=48 && x[i]<57))
            continue;
        else{
            specialChar = true;
            break;
        }
    }
    if(!specialChar)
        cout << "no special char\n";
    for(int i=0;i<x.length();i++){
        if(isupper(x[i])){
            upperChar = true;
            break;
        }
        else
            continue;
    }
    if(!upperChar)
        cout << "No upper char\n";
    for(int i=0;i<x.length();i++){
        if(islower(x[i])){
            lowerChar = true;
            break;
        }
        else
            continue;
    }
    if(!lowerChar)
        cout << "No lower char\n";
    for(int i=0;i<x.length();i++){
        if(isdigit(x[i])){
            digit = true;
            break;
        }
        else
            continue;
    }
    if(!digit)
        cout << "No digits\n";
    if(eightChars && specialChar && upperChar && lowerChar && digit)
        return true;
    else
        return false;

}
bool checkCNIC(unsigned long long int x){
    int count=0;
    while(x!=0){
        x/=10;
        count++;
    }
    if(count==13)
        return true;
    else
        return false;
}
int countDigits(int x){
    int count=0;
    while(x!=0){
        x/=10;
        count++;
    }
    return count;
}
Admin createAdminAccount(){

    bool checkPass;
    string name, pass;
    int age, pin;
    cout << "Please input your name\n";
    cin >> name;
    cout << "Please input your age\n";
    cin >> age;
    cout << "Please input your password\n";
    cin >> pass;
    checkPass = checkPassword(pass);
    while(!checkPass){
        cout << "Password must be 8 characters long and use of minimum one special character, uppercase, lowercase, and numeric digit is must.\nPlease input again\n";
        cin >> pass;
        checkPass = checkPassword(pass);
    }
    cout << "Input 3 digit backup pin\n";
    cin >> pin;
    int digits = countDigits(pin);
    while(digits!=3){
        cout << "Backup pin must be 3 digit only\nInput again\n";
        cin >> pin;
        digits = countDigits(pin);
    }    
    Admin x(name,age,name,pass,pin);
    //writing to file
    ofstream out;
    out.open("admins.txt");
    out << x.getTotal();
    out.close();
    out.open("admins.txt",ios::app);
    out << name << " " << age << endl;
    out.close();
    out.open("admin-accounts.txt",ios::app);
    out << name << " " << pass << " " << pin << endl;
    return x;

}
Adult createPassengerAccount(){
    bool checkPass,checkCard;
    string name, pass;
    int age, pin;
    unsigned long long int tempCNIC;
    cout << "Please input your name\n";
    cin >> name;
    cout << "Please input your age\n";
    cin >> age;
    while(age<18){
        cout << "Age must be greater than 19\n";
        cin >> age;
    }
    cout << "Please input you CNIC number\n";
    cin >> tempCNIC;
    checkCard = checkCNIC(tempCNIC);
    while(!checkCard){
        cout << "CNIC must be 13 digit long\nInput again\n";
        cin >> tempCNIC;
        checkCard = checkCNIC(tempCNIC);
    }
    cout << "Please input your password\n";
    cin >> pass;
    checkPass = checkPassword(pass);
    while(!checkPass){
        cout << "Password must be 8 characters long and use of minimum one special character, uppercase, lowercase, and numeric digit is must.\nPlease input again\n";
        cin >> pass;
        checkPass = checkPassword(pass);
    }
    cout << "Input 3 digit backup pin\n";
    cin >> pin;
    int digits = countDigits(pin);
    while(digits!=3){
        cout << "Backup pin must be 3 digit only\nInput again\n";
        cin >> pin;
        digits = countDigits(pin);
    }    
    string nationality;
    cout << "Input your nationality\n";
    cin >> nationality;
    Adult x(tempCNIC,name,age,name,pass,pin);
    //writing to file
    bool validPass;
    cout << "Do you have a valid passport?\n";
    cin >> validPass;
    ofstream out("adults.txt",ios::app);
    out << name << " " << age << " " << tempCNIC << " " << "-" << endl;
    out.close();
    out.open("adult-passports.txt",ios::app);
    out << nationality << " " << name << " " << validPass << endl;
    out.close();
    out.open("accounts.txt",ios::app);
    out << name << " " << pass << " " << pin << endl;
    return x;
}

int main(){

    Path* currentPaths;
    int numPaths=100;
    currentPaths = new Path[numPaths];
    Flight* currentFlights;
    int numFlights =50;

    currentFlights = new Flight[numFlights];

    currentPaths = currentPaths[0].ImportPaths(currentPaths,numPaths);
    currentFlights = currentFlights[0].importFlightData(currentFlights,numFlights,currentPaths,numPaths);
    /* for(int i=0;i<12;i++){
        cout << currentFlights[i].getFlightName() << endl;
    } */
 
    int mainMenu = 1;
    
    

    Passport* adultPassports;
    adultPassports = new Passport[50];
    adultPassports = adultPassports[0].importAdultPassport(adultPassports);
    //cout << currentFlights[0].getTotal();

    /*for(int i=0;i<adultPassports[0].getNumPassports();i++){
        adultPassports[i].displayPassport();
        cout << endl;
    } */ 
    Adult* currentAdults;
    int numAdults = 50;
    currentAdults = new Adult[numAdults];
    currentAdults = currentAdults[0].importAdults(currentAdults,adultPassports,adultPassports[0].getNumPassports(),currentFlights,currentFlights[0].getTotal());
    Admin* currentAdmins;
    int numAdmins = 15;
    currentAdmins = new Admin[numAdmins];
    currentAdmins = currentAdmins[0].importAdmins(currentAdmins);

    /* for(int i=0;i<currentAdults[i].getTotal();i++){
        currentAdults[i].displayPassengerInfo();
        cout << endl;
    }  */
    
    do{

        if (mainMenu != 1 && mainMenu != 2 && mainMenu != 3)
            cout << "You pressed a wrong button\n";

        cout << "~~Main Menu~~\n";
        cout << "Press 1 to view NPAFS flights\nPress 2 to Log-In\nPress 3 to Register a new account\nPress 4 to exit\n";
        cin >> mainMenu;
        int submenu;
        switch (mainMenu)
        {

        case 1:
            {
                cout << left << setw(11) << "Flight#" << " " << setw(11) << "Departure" << " " << setw(9) << "Transit" << " " << setw(16) << "ArrivalLocation" << " " << setw(0) << "DepartureTime" <<  " " << setw(0) << "ArrivalTime" << endl;
                for(int i=0;i<76;i++){
                    cout << "-";
                }
                cout << endl; 
                for(int i=0;i<12;i++){
                    currentFlights[i].displayFlight();
                    cout << endl;
                } 
            }
            
            break;

        case 2:
            {
                char input;
                bool admin,passger;
                cout << "\n\n~~Welcome to the Login menu~~\n\n";
                cout << "Are you an admin? [y/n]\n";
                cin >> input;
                if(input=='y'||input=='Y'){
                    admin = checkAdminAccount(currentAdmins);
                    if(admin){
                        cout << "~~Admin Menu~~\n";
                        cout << "What do you wish to do?\n";
                        int submenu = 1;
                        cout << "1.Create New Flight\n2.Cancel Flight\n3.Change Schedule\n4.Restrict Passengers\n5.Update Account Details\n6.Exit\n";
                        cin >> submenu;
                        switch(submenu){
                            case 1:
                            {
                                int path;
                                cout << "Here's a list of paths available, kindly select one\n";
                                cout << left << setw(12) << "Departure" << setw(10) << "Transit" << setw(17) << "ArrivalLocaiton" << setw(6) << "FlightTime" << endl;
                                cout << endl; 
                                for(int i=0;i<30;i++){
                                    currentPaths[i].displayPath();
                                    cout << endl;
                                }   
                                cin >> path;
                            }
                            break;
                            case 2:
                            {
                                int flight;
                                cout << left << setw(11) << "Flight#" << " " << setw(11) << "Departure" << " " << setw(9) << "Transit" << " " << setw(16) << "ArrivalLocation" << " " << setw(0) << "DepartureTime" <<  " " << setw(0) << "ArrivalTime" << endl;
                                for(int i=0;i<76;i++){
                                    cout << "-";
                                }
                                cout << endl; 
                                for(int i=0;i<12;i++){
                                    currentFlights[i].displayFlight();
                                    cout << endl;
                                } 
                                cout << "\n\nHere's a list of flights available, Please select the one you would like to cancel\n\n";
                                cin >> flight;
                            }
                            break;
                            case 3:
                            {

                            }
                            break;
                            case 4:
                            {

                            }
                            break;
                            case 5:
                            {

                            }
                            break;
                            case 6:
                            {

                            }
                            break;
                        }
                    }
                }
                else if(input == 'n' || input == 'N'){
                    cout << "You must be a passenger!\n";
                    passger = checkPassengerAccount(currentAdults);
                    if(passger){
                        cout << "~~Passenger Menu~~\n";
                        cout << "What do you wish to do?\n";
                        cout << "1.Book Flight\n2.Cancel Flight\n3.Pay for flight\n4.See NPAFS points\n5.Update Account Details\n6.Exit\n";
                        int submenu;
                        cin >> submenu;
                        switch(submenu){
                            case 1:
                            {
                                int flight;
                                cout << left << setw(11) << "Flight#" << " " << setw(11) << "Departure" << " " << setw(9) << "Transit" << " " << setw(16) << "ArrivalLocation" << " " << setw(0) << "DepartureTime" <<  " " << setw(0) << "ArrivalTime" << endl;
                                for(int i=0;i<76;i++){
                                    cout << "-";
                                }
                                cout << endl; 
                                for(int i=0;i<12;i++){
                                    currentFlights[i].displayFlight();
                                    cout << endl;
                                } 
                                cout << "\n\nHere's a list of flights available, Please select the one you would like\n\n";
                                cin >> flight;
                            }
                            break;
                            case 2:
                            {

                            }
                            break;
                            case 3:
                            {

                            }
                            break;
                            case 4:
                            {

                            }
                            break;
                            case 5:
                            {

                            }
                            break;
                            case 6:
                            {

                            }
                            break;
                        }
                    }
                }
                else 
                    cout << "wrong input\n";
            }
            break;
            

        case 3:
            {
                cout << "\n\n~~Welcome to the registration menu~~\n\n";
                char input;
                bool admin;
                cout << "Would you like to register as an Admin? [y/n]\n";
                cin >> input;
                if(input=='y'||input=='Y'){
                    Admin temp = createAdminAccount();
                    currentAdmins[currentAdmins->getTotal()] = temp;
                }
                else if(input == 'n' || input == 'N'){
                    cout << "Would you like to register as a Passenger? [y/n]\n";
                    cin >> input;
                    if(input=='y'||input=='Y'){
                        Adult temp = createPassengerAccount();
                        currentAdults[currentAdults->getTotal()] = temp;
                    }
                    else if(input == 'n' || input == 'N')
                        cout << "Alright,thanks!\n";
                    else
                        cout << "wrong input\n";
                        
                }
                else 
                    cout << "wrong input\n";
            }
            break;

        default:
            break;
        }

    } while (mainMenu != 4); 

    return 0;
}