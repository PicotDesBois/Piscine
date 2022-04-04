#include <iostream>
#include <fstream>

#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

class Avion{
private:
    int m_type;
    int m_carburant;
    int m_reservoir;
    int m_consommation;
public:
    Avion(int type,int reservoir);
    ~Avion();

    int getConsommation();
    int getReservoir();
    int getCarburant();

    void setConsomation(int consommation);
    void setCarburant(int carburant);
    void afficher();
};

#endif // AVION_H_INCLUDED
