#include <iostream>
#include <vector>
#include <cstring>
#include <memory>
#include "HeavyException.h"
#include "HighException.h"
#include "Class_Package.h"
#include "Class_Car.h"
#include "SClass_Van.h"
#include "SClass_Truck.h"
using namespace std;
int Van::numberOfVansAdded = 0;
int Truck::numberOfTrucksAdded = 0;
int main() {
int numarColete = 0, numarMasini = 0, choice, carChoice;
    vector<unique_ptr<Package>> colet;
    vector<Truck> camioane;
    vector<Van*> dubite;
    
    do{
        try{
        cout << endl << endl;
        cout << "Meniu" << endl;
        cout << "1.Inregistrati coletele" << endl;
        cout << "2.Adaugati masinile disponibile" << endl;
        cout << "3.Vizualizare coletele adaugate" << endl;
        cout << "4.Vizualizati masini disponibile" << endl;
        cout << "0.Iesire" << endl;
        cin >> choice;

        if(choice == 1){
            cout << "Introduceti numarul de colote:";
            cin >> numarColete;
            Package aux;
            for(int i = 0; i < numarColete; i++){
                cin >> aux;
                colet.push_back(make_unique<Package>(aux));
            }
        }
        
        if(choice == 2){
            cout<< "Introduceti tipul de masina pe care doriti sa il adaugati:"<<endl;
            cout << "1.Camioane"<<endl;
            cout << "2.Dubite"<<endl;
            cin >> carChoice;
            if(carChoice == 1){
                cout << "Introduceti numarul de camioane pe care doriti sa l adaugati"<<endl;
                cin >> numarMasini;
                Truck aux;
                for(int i=0; i < numarMasini; i++){
                    cin >> aux;
                    camioane.push_back(aux);
                }
            }
            if(carChoice == 2){
                cout << "Introduceti numarul de dubite pe care doriti sa l adaugati"<<endl;
                cin >> numarMasini;
                Van aux;
                for(int i=0; i < numarMasini; i++){
                    cin >> aux;
                    dubite.push_back(new Van(aux));
                }
            }
        }

        if(choice == 3){
            if(colet.size() == 0)
                cout << "Nu ati adaugat colete." << endl;
            else
                for(int i = 0;i < colet.size();i++){
                    cout<<*colet[i];
                }
        }

        if(choice == 4){
            if(camioane.size() == 0 && dubite.size() == 0)
                cout << "Nu ati adaugar nicio masina."<<endl;
            else{
                cout << "Numarul de camioane introdus este:" << camioane.size() << endl;
                for(int i=0;i < camioane.size(); i++)
                    cout<<camioane[i];
                cout << "Numarul de dubite introdus este:" << dubite.size() << endl;
                for(int i=0;i < dubite.size(); i++)
                    cout<<*dubite[i];
            }     
        }

        if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 0){
            cout << "Optiune invalida, mai incercati o data" << endl;
        }
        
    }
    catch(const TooHeavyException &e){
        cout << e.what();
    }
    catch(const TooHighException &p){
        cout << p.what();
    }
    }while(choice != 0);

    for(auto dubita : dubite){
        delete dubita;
    }
    
    return 0;
}
