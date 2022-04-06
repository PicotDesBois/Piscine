#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

#include "headers.h"


class Avion{
private:
    std::string m_type;
    int m_identifiant;
    int m_carburant;
    int m_reservoir;
    int m_consommation;
    int m_ut;
    int m_x;
    int m_y;
    int m_vitesse;
    std::vector<int> m_trajet;

public:
    Avion(std::string type,int identifiant,int reservoir);
    ~Avion();

    int getConsommation();
    int getReservoir();
    int getCarburant();
    int getIdentifiant();
    int getUT();
    int getX();
    int getY();
    int getVitesse();
    std::vector<int>&getTrajet();

    void setAjouterTrajet(int id);
    void setSupprimerTrajet(int id);
    void setVitesse(int vitesse);
    void setX(int x);
    void setY(int y);
    void setConsomation(int consommation);
    void setCarburant(int carburant);
    void setUT(int ut);
    void afficher();
};

#endif // AVION_H_INCLUDED
