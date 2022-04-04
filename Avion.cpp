#include "Avion.h"
Avion::Avion(std::string type,int identifiant,int reservoir):
    m_type(type),m_identifiant(identifiant),m_carburant(reservoir),m_reservoir(reservoir)
{
    m_consommation=100;
}
void Avion::afficher()
{
    std::cout<<"Type : "<<m_type<<std::endl;
    std::cout<<"Identifiant : "<<m_identifiant<<std::endl;
    std::cout<<"Reservoir : "<<m_reservoir<<std::endl;
    std::cout<<"Carburant : "<<m_carburant<<std::endl;
    std::cout<<"Consommation : "<<m_consommation<<std::endl;
}
/*********** Accesseurs *****************/
int Avion::getConsommation(){return m_consommation;}
int Avion::getReservoir(){return m_reservoir;}
int Avion::getCarburant(){return m_carburant;}
int Avion::getIdentifiant(){return m_identifiant;}
void Avion::setCarburant(int carburant){m_carburant=carburant;}
void Avion::setConsomation(int consommation){m_consommation=consommation;}
/****************************************/

