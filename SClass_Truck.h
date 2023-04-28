#ifndef _SClass_Truck_H_
#define _SClass_Truck_H_
#include "Class_Car.h"

class Truck : public Car{
    private:
        string Driver;
        int height;
        static int numberOfTrucksAdded, totalTruckCapacity;

    public:

        string getDriver()const;
        void setDriver(const string Driver);
        int getHeight() const;
        void setHeight(const int height);
        int getNumberOfTrucksAdded() const;

        Truck();
        Truck(const string Driver);
        Truck(const Truck &Truck_);
        Truck& operator=(const Truck &Truck_);
        
        virtual void sayHello() const override;
        friend std::istream &operator>>(std::istream &is, Truck &Truck_);
        friend std::ostream &operator<<(std::ostream &os,const Truck &Truck_);
        
        ~Truck();
};
#endif