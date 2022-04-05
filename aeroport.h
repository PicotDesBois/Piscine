#ifndef AEROPORT_H_INCLUDED
#define AEROPORT_H_INCLUDED

#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
#include "Avions.h"

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
    std::vector<Aeroport*> m_aeroportsVoisin;

public:
    Aeroport(int identifiant,std::string name,int piste,int place,int sol,int access,int duree,int anticol,int decollage,int bouc);

    std::string getNom()const;
    int getPistes()const;
    int getPlaces()const;
    int getSol()const;
    int getAcces()const;
    int getDuree()const;
    int getCollision()const;
    int getBoucle()const;
    int getDecollage()const;
    std::vector<Aeroport*>& getVoisin();

    void setNom(std::string Name);
    void setPistes(int nombrPistes);
    void setPlaces(int nombrPlaces);
    void setSol(int atterisol);
    void setAcces(int acceder);
    void setDuree(int timer);
    void setCollision(int coli);
    void setBoucle(int bou);
    void ajouterVoisin(Aeroport*voisin);

    void afficher_liste()const;
};
class Arrete
{

private:
    int m_Aeroport1;
    int m_Aeroport2;
    int m_ponderation; ///distance entre les aeroports

public:
     ///constructeur surchargé
    Arrete(int ini, int fin, int ponderation);
    int getAeroport1()const;
    int getAeroport2()const;
    int getPonderation()const;
    void setPonderation(int pond);
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
};




#endif // AEROPORT_H_INCLUDED
