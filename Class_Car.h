#ifndef CLASS_CAR_H
#define CLASS_CAR_H
#include <string>
#include <iostream>

using namespace std;
class Car{
    private:
        int availableWeight;
        string licensePlate;
    public:
        string getLicensePlate()const;
        void setLicensePlate(const string licensePlate);
        int getAvailableWeight() const;
        void setAvailableWeight(const int availableWeight);

        Car();
        Car(const string licensePlate, const int availableWeight);
        Car(const Car &Car_);

        friend std::istream &operator>>(std::istream &is, Car &Car_);
        friend std::ostream &operator<<(std::ostream &os,const Car &Car_);
        Car& operator=(const Car &car_);
        
        virtual void sayHello() const;
        bool operator==(const Car &car_);
        bool operator!=(const Car &car_);

        virtual ~Car();
};

#endif 