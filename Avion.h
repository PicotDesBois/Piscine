#include <iostream>
#include <fstream>
#include <vector>

#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

class Avion{
private:
    std::string m_type;
    int m_identifiant;
    int m_carburant;
    int m_reservoir;
    int m_consommation;
public:
    Avion(std::string type,int identifiant,int reservoir);
    ~Avion();

    int getConsommation();
    int getReservoir();
    int getCarburant();
    int getIdentifiant();

    void setConsomation(int consommation);
    void setCarburant(int carburant);
    void afficher();
};

#endif // AVION_H_INCLUDED
