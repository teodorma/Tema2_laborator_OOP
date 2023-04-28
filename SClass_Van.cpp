#include "SClass_Van.h"
#include "HeavyException.h"
string Van::getDriver() const{
    return Driver;
}

void Van::setDriver(const string Driver_){
    this -> Driver = Driver_;
}

int Van::getNumberOfVansAdded() const{
    return numberOfVansAdded;
}

Van::Van(){}

Van::Van(const string Driver) : Driver(Driver){
    numberOfVansAdded++;
}

Van::Van(const Van &Van_){
    setLicensePlate(Van_.getLicensePlate());
    setAvailableWeight(Van_.getAvailableWeight());
    Driver = Van_.Driver;
}

Van& Van::operator=(const Van &Van_) {
    setLicensePlate(Van_.getLicensePlate());
    setAvailableWeight(Van_.getAvailableWeight());
    this -> Driver = Van_.Driver;
    return *this;
}

std::istream &operator>>(std::istream &is, Van &Van_) {
    string buf, Driver_;
    int availableWeight_;
    cout << "Introdu numarul de inmatriculare al masinii: ";
    is >> buf;
    Van_.setLicensePlate(buf);
    cout << "Introdu capacitatea maxima de transportare (in kilograme): ";
    is >> availableWeight_;
    if(availableWeight_ >= 100){
        throw TooHeavyException();
    }
    Van_.setAvailableWeight(availableWeight_);
    cout << "Introdu numele soferului:";
    is >> Driver_;
    Van_.setDriver(Driver_);
    return is;

}
void Van::sayHello() const {
        std::cout << "Hello, I am Van"<<endl;
    }
    
std::ostream &operator<<(std::ostream &os,const Van &Van_) {
    if (Van_.getLicensePlate()=="") {
        os << "Not initialized\n";
        return os;
    }
    os << "Numarul de inmatriculare al masinii: " << Van_.getLicensePlate() << endl
    << "Capacitatea maxima de transportare (in kilograme): " << Van_.getAvailableWeight() << endl
    << "Numele soferului: "<< Van_.getDriver();
    return os;
}


Van::~Van(){}

