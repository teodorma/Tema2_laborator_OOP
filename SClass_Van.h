#ifndef _SCLASS_VAN_H_
#define _SCLASS_VAN_H_
#include "Class_Car.h"

class Van : public Car{
    private: 
        string Driver;
        static int numberOfVansAdded, totalVanCapacity;

    public:
        
        string getDriver() const;
        void setDriver(const string Driver_);
        int getNumberOfVansAdded() const;

        Van();
        Van(const string Driver);
        Van(const Van &Van);
        
        virtual void sayHello() const;
        Truck& operator=(const Truck &Truck_);
        friend std::istream &operator>>(std::istream &is, Van &Van_);
        friend std::ostream &operator<<(std::ostream &os,const Van &Van_);

        ~Van();
};
#endif