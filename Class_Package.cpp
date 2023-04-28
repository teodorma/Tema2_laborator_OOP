#include "Class_Package.h"

string Package::getName() const{
    return name;
}

void Package::setName(const string name_){
    this -> name = name_;
}

int Package::getId() const{
    return id;
}

void Package::setId(const int id_){
    Package::id = id_;
}

int Package::getWeight()const {
    return weight;
}

void Package::setWeight(const int weight_){
    Package::weight = weight_;
}

int Package::getDeliveryTime()const {
    return deliveryTime;
}

void Package::setDeliveryTime(const int deliveryTime_){
    Package::deliveryTime = deliveryTime_;
}

Package::Package(){}

Package::Package(const string name,const int id) : name(name) , id(id){}


Package::Package(const Package &package_){
    name = package_.name;
    id = package_.id;
    weight = package_.weight;
    deliveryTime = package_.deliveryTime;
}
Package& Package::operator=(const Package &package_){
    this -> name = package_.name;
    this -> id = package_.id;
    this -> weight = package_.weight;
    this -> deliveryTime = package_.deliveryTime;   
    return *this;
}
std::istream& operator>>(std::istream &is, Package &package_){
    char buf[100];
    int id_;
    cout << "Introdu numele pachetului: ";
    is >> buf;
    package_.setName(buf);
    cout << "Introdu Id-ul pachetelui: ";
    is >> id_;
    package_.setId(id_);
    return is;
}

std::ostream& operator<<(std::ostream &os,const Package &package_){
    if(package_.name==""){
        os << "Not initialized\n";
        return os;
    }
    os << "Numele coletului: " << package_.name << endl << "Id colet: " << package_.id << endl;
    return os;
}
bool Package::operator==(const Package &package_){
    return name==package_.name && id == package_.id;  
}

bool Package::operator!=(const Package &package_){
    return name==package_.name && id != package_.id;
}

Package::~Package(){}