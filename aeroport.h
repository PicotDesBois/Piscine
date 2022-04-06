#ifndef AEROPORT_H_INCLUDED
#define AEROPORT_H_INCLUDED

#include "headers.h"

class Aeroport
{
private:
    int m_identifiant;
    std::string m_nom;
    int m_x;
    int m_y;
    int m_nbPistes;
    int m_nbPlaces;
    int m_attSol;
    int m_acces;
    int m_duree;
    int m_anticollision;
    int m_tempsDecollage;
    int m_boucle;
    int m_marque;
    std::vector<Aeroport*> m_aeroportsVoisin;
    std::vector<Avion*>m_avionsPiste;
    std::vector<Avion*>m_avionsSol;
    std::vector<Avion*>m_avionsAttente;

public:
    Aeroport(int identifiant,std::string name,int piste,int place,int sol,int access,int duree,int anticol,int decollage,int bouc,int x,int y);

    std::string getNom()const;
    int getPistes()const;
    int getPlaces()const;
    int getSol()const;
    int getAcces()const;
    int getDuree()const;
    int getCollision()const;
    int getBoucle()const;
    int getDecollage()const;
    int getX();
    int getY();
    int getIdentifiant();
    int getMarque();
    std::vector<Aeroport*>&getVoisin();
    std::vector<Avion*>&getAvionsPiste();
    std::vector<Avion*>&getAvionsSol();
    std::vector<Avion*>&getAvionsAttente();

    void setMarque(int marque);
    void setNom(std::string Name);
    void setPistes(int nombrPistes);
    void setPlaces(int nombrPlaces);
    void setSol(int atterisol);
    void setAcces(int acceder);
    void setDuree(int timer);
    void setCollision(int coli);
    void setBoucle(int bou);
    void setAjouterAvionsPiste(Avion*avion);
    void setAjouterAvionsSol(Avion*avion);
    void setAjouterAvionsAttente(Avion*avion);
    void setSupprimerAvionsPiste(int identifiant);
    void setSupprimerAvionsSol(int identifiant);
    void setSupprimerAvionsAttente(int identifiant);

    void ajouterVoisin(Aeroport*voisin);
    void afficher()const;
    bool placeDisponible();
    bool pisteDisponible();
};
class Arrete
{

private:
    int m_Aeroport1;
    int m_Aeroport2;
    int m_ponderation; ///distance entre les aeroports
    std::vector<Avion*> m_avionVol;

public:
     ///constructeur surchargé
    Arrete(int ini, int fin, int ponderation);
    int getAeroport1()const;
    int getAeroport2()const;
    int getPonderation()const;
    std::vector<Avion*>&getAvionVol();

    void setPonderation(int pond);
    void setAjouterAvionVol(Avion*avion);
    void setSupprimerAvionVol(int numAvion);

    void affichage();

};
class Graphe
{
private:
    std::vector<Aeroport*> m_liste_aeroport;
    std::vector<Arrete*> m_arrete;
    std::vector<Avion*>m_listeAvions;

public:
    Graphe(std::string nomFichier);
    ~Graphe();
    void afficher()const;
    void ChargementAvions();

    void gestionAeroport();
    void gestionVol();
    void Destination(Aeroport*aeroport,Avion*avion);
};




#endif // AEROPORT_H_INCLUDED
