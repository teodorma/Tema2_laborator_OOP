#include "SClass_Truck.h"
#include "HeavyException.h"
#include "HighException.h"
string Truck::getDriver() const{
    return Driver;
}

void Truck::setDriver(const string Driver_){
    this -> Driver = Driver_;
}
int Truck::getHeight() const{
    return height;
}
void Truck::setHeight(const int height_){
    this -> height = height_;
}
int Truck::getNumberOfTrucksAdded() const{
    return numberOfTrucksAdded;
}

Truck::Truck(){}

Truck::Truck(const string Driver) : Driver(Driver){
    numberOfTrucksAdded++;
}

Truck::Truck(const Truck &Truck_){
    setLicensePlate(Truck_.getLicensePlate());
    setAvailableWeight(Truck_.getAvailableWeight());
    Driver = Truck_.Driver;
}

Truck& Truck::operator=(const Truck &Truck_) {
    setLicensePlate(Truck_.getLicensePlate());
    setAvailableWeight(Truck_.getAvailableWeight());
    this -> Driver = Truck_.Driver;
    this -> height = Truck_.height;
    return *this;
}

std::istream &operator>>(std::istream &is, Truck &Truck_) {
    string buf, Driver_;
    int availableWeight_,height_;
    cout << "Introdu numarul de inmatriculare al masinii: ";
    is >> buf;
    Truck_.setLicensePlate(buf);
    cout << "Introdu capacitatea maxima de transportare (in kilograme): ";
    is >> availableWeight_;
    if(availableWeight_ > 1000){
        throw TooHeavyException();
    }
    Truck_.setAvailableWeight(availableWeight_);
    cout << "Introdu numele soferului:";
    is >> Driver_;
    Truck_.setDriver(Driver_);
    cout << "Introdu inaltimea camionului:";
    is >> height_;
    if(availableWeight_ > 10){
        throw TooHighException();
    }
    Truck_.setHeight(height_);
    return is;
}
void Truck::sayHello() const{
        std::cout << "Hello, I am truck "<<endl;
    }
std::ostream &operator<<(std::ostream &os,const Truck &Truck_) {
    if (Truck_.getLicensePlate()=="") {
        os << "Not initialized\n";
        return os;
    }
    os << "Numarul de inmatriculare al masinii: " << Truck_.getLicensePlate() << endl
    << "Capacitatea maxima de transportare (in kilograme): " << Truck_.getAvailableWeight() << endl
    << "Numele soferului: "<< Truck_.getDriver();
    return os;
}

Truck::~Truck(){}

