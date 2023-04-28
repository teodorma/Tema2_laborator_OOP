#ifndef _CLASS_PACKAGE_H_ // include guard
#define _CLASS_PACKAGE_H_ // folosit pentru a ne asigura ca nu includem acelasi header de mai multe ori
#include <cstring>
#include <iostream>
using namespace std;
class Package{
    private:
        int id, weight, deliveryTime;
        string name;
 
    public:
        string getName() const;
        void setName(const string name_);
        int getId() const;
        void setId(const int id_);
        int getWeight()const;
        void setWeight(const int weight_);
        int getDeliveryTime()const;
        void setDeliveryTime(const int deliveryTime_);

        Package();
        Package(const string name,const int id);
        Package(const Package &package_);

        Package& operator=(const Package &package_);
        friend std::istream &operator>>(std::istream &is, Package &package_);
        friend std::ostream &operator<<(std::ostream &os,const Package &package_);

        bool operator==(const Package &package_);  
        bool operator!=(const Package &package_);


        /// clasa de exceptie
        void deliveryType(int weight);

        virtual ~Package();

};

#endif // _STUDENT_H_