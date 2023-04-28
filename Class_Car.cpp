#include "Class_Car.h"

string Car::getLicensePlate() const{
    return licensePlate;
}

void Car::setLicensePlate(const string licensePlt) {
    this -> licensePlate = licensePlt;
}

int Car::getAvailableWeight() const {
    return availableWeight;
}

void Car::setAvailableWeight(const int availableWeight_) {
    Car::availableWeight = availableWeight_;
}

Car::Car(){}   

Car::Car(const string licensePlate, const int availableWeight) : licensePlate(licensePlate), availableWeight(availableWeight){}

Car::Car(const Car &Car_) {
    licensePlate = Car_.licensePlate;
    availableWeight = Car_.availableWeight;
}

Car& Car::operator=(const Car &car_) {
    this -> licensePlate = car_.licensePlate;
    this -> availableWeight = car_.availableWeight;
    return *this;
}

std::istream &operator>>(std::istream &is, Car &Car_) {
    char buf[100];
    int availableWeight_;
    cout << "Introdu numarul de inmatriculare al masinii: ";
    is >> buf;
    Car_.setLicensePlate(buf);
    cout << "Introdu capacitatea maxima de transportare (in kilograme): ";
    is >> availableWeight_;
    Car_.setAvailableWeight(availableWeight_);
    return is;
}


std::ostream &operator<<(std::ostream &os,const Car &Car_) {
    if (Car_.licensePlate=="") {
        os << "Not initialized\n";
        return os;
    }
    os << "Numarul de inmatriculare al masinii: " << Car_.getLicensePlate() << endl
    << "Capacitatea maxima de transportare (in kilograme): " << Car_.getAvailableWeight() << endl;
    return os;
}

bool Car::operator==(const Car &car_){
    return licensePlate==car_.licensePlate  && availableWeight == car_.availableWeight;
}

bool Car::operator!=(const Car &car_){
    return Car::licensePlate == car_.licensePlate  && availableWeight != car_.availableWeight;
}
Car::~Car(){}

