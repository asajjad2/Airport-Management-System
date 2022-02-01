#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;
#include <ctime>
class Time{

    private:
         
        int year;
        int month;
        int date;
        int hours;
        int min;

    public:

        Time(int m=0,int d=0, int h=0, int mi=0,int y=0);
        void setMonth(int x);
        void setDate(int x);
        void setHours(int x);
        void setMin(int x);
        void setYear(int x);
        int getMonth() const;
        int getDate() const;
        int getHours() const;
        int getMin() const;
        int getYear() const;
        friend bool operator> (const Time &d1, const Time &d2);
        friend ostream& operator<< (ostream &out, const Time &t1);
        Time operator+(Time& t1);

};
#endif
