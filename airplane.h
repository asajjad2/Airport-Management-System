#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <string>
using namespace std;

class Airplane{

    private:
        string name;
    
    public:

        string getName() const;
        void setName(string x);

};

#endif

