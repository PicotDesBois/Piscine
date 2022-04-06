#include "headers.h"

using namespace std;

Aeroport::Aeroport(int identifiant,std::string name,int piste,int place,int sol,int access,int duree,int anticol,int decollage,int bouc,int x,int y):
    m_identifiant{identifiant},m_nom{name},m_x(x),m_y(y),m_nbPistes{piste},m_nbPlaces{place},m_attSol{sol},m_acces{access},m_duree{duree},m_anticollision{anticol},m_tempsDecollage{decollage},m_boucle{bouc}{}

std::string Aeroport::getNom()const{return m_nom;}
int Aeroport::getPistes()const{return m_nbPistes;}
int Aeroport::getPlaces()const{return m_nbPlaces;}
int Aeroport::getSol()const{return m_attSol;}
int Aeroport::getAcces()const{return m_acces;}
int Aeroport::getDuree()const{return m_duree;}
int Aeroport::getCollision()const{return m_anticollision;}
int Aeroport::getBoucle()const{return m_boucle;}
int Aeroport::getDecollage()const{return m_tempsDecollage;}
int Aeroport::getX(){return m_x;}
int Aeroport::getY(){return m_y;}
int Aeroport::getIdentifiant(){return m_identifiant;}
int Aeroport::getMarque(){return m_marque;}
std::vector<Aeroport*>& Aeroport::getVoisin(){return m_aeroportsVoisin;}
std::vector<Avion*>&Aeroport::getAvionsPiste(){return m_avionsPiste;}
std::vector<Avion*>&Aeroport::getAvionsSol(){return m_avionsSol;}
std::vector<Avion*>&Aeroport::getAvionsAttente(){return m_avionsAttente;}

void Aeroport::setMarque(int marque){m_marque=marque;}
void Aeroport::setNom(std::string Name){m_nom=Name;}
void Aeroport::setPistes(int nombrPistes){m_nbPistes=nombrPistes;}
void Aeroport::setPlaces(int nombrPlaces){m_nbPlaces=nombrPlaces;}
void Aeroport::setSol(int atterisol){m_attSol=atterisol;}
void Aeroport::setAcces(int acceder){m_acces=acceder;}
void Aeroport::setDuree(int timer){m_duree=timer;}
void Aeroport::setCollision(int coli){m_anticollision=coli;}
void Aeroport::setBoucle(int bou){m_boucle=bou;}
void Aeroport::ajouterVoisin(Aeroport*voisin){m_aeroportsVoisin.push_back(voisin);}
void Aeroport::setAjouterAvionsPiste(Avion*avion)
{
    if(m_nbPistes>m_avionsPiste.size())
        m_avionsPiste.push_back(avion);
    else
        std::cout<<"Piste de : "<<m_nom<<"pleine";
}
void Aeroport::setAjouterAvionsSol(Avion*avion)
{
    if(m_nbPlaces>m_avionsSol.size())
        m_avionsSol.push_back(avion);
    else
        std::cout<<"L aeroport de : "<<m_nom<<"est complet";
}
void Aeroport::setAjouterAvionsAttente(Avion*avion){m_avionsAttente.push_back(avion);}
void Aeroport::setSupprimerAvionsPiste(int identifiant)
{
    int i=0;
    while(m_avionsPiste[i]->getIdentifiant()!=identifiant)
    {
        i++;
    }
    m_avionsPiste.erase(m_avionsPiste.begin()+i);
}
void Aeroport::setSupprimerAvionsSol(int identifiant)
{
    int i=0;
    while(m_avionsSol[i]->getIdentifiant()!=identifiant)
    {
        i++;
    }
    m_avionsSol.erase(m_avionsSol.begin()+i);
}
void Aeroport::setSupprimerAvionsAttente(int identifiant)
{
    int i=0;
    while(m_avionsAttente[i]->getIdentifiant()!=identifiant)
    {
        i++;
    }
    m_avionsAttente.erase(m_avionsAttente.begin()+i);
}
void Aeroport::afficher()const
{
    std::cout<<" Aeroport: "<<m_nom<<std::endl;
    std::cout<<" Identifiant: "<<m_identifiant<<std::endl;
    std::cout<<" Coordonnees: "<<m_x<<" "<<m_y<<std::endl;
    std::cout<<" Pistes: "<<m_nbPistes<<std::endl;
    std::cout<<" Places: "<<m_nbPlaces<<std::endl;
    std::cout<<" Attente au sol: "<<m_attSol<<std::endl;
    std::cout<<" Acces aux pistes: "<<m_acces<<std::endl;
    std::cout<<" Duree de la boucle : "<<m_duree<<std::endl;
    std::cout<<" Anti-collision: "<<m_anticollision<<std::endl;
    std::cout<<" Boucle: "<<m_boucle<<std::endl;
    std::cout<<" Decollage/atterissage: "<<m_tempsDecollage<<std::endl;

    std::cout<<" Aeroport adjacent : ";
    for(auto voisin:m_aeroportsVoisin)
    {
        std::cout<<voisin->getNom()<<", ";
    }
    std::cout<<std::endl;

    std::cout<<" Avion en attente au sol : ";
    std::cout<<std::endl;
    for(auto avion:m_avionsSol)
    {
        avion->afficher();
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
}
bool Aeroport::pisteDisponible()
{
    if(m_nbPistes>m_avionsPiste.size())
        return true;
    else return false;
}
bool Aeroport::placeDisponible()
{
    if(m_nbPlaces>m_avionsSol.size())
        return true;
    else return false;
}
Arrete::Arrete(int ini, int fin, int ponderation):
    m_Aeroport1{ini},m_Aeroport2{fin},m_ponderation{ponderation} {}

///getters
int Arrete::getAeroport1()const{return m_Aeroport1;}
int Arrete::getAeroport2()const{return m_Aeroport2;}
int Arrete::getPonderation()const{return m_ponderation;}
std::vector<Avion*>&Arrete::getAvionVol(){return m_avionVol;}
///setters
void Arrete::setPonderation(int pond){m_ponderation=pond;}
void Arrete::setAjouterAvionVol(Avion*avion){m_avionVol.push_back(avion);}
void Arrete::setSupprimerAvionVol(int identifiant)
{
    int i=0;
    while(m_avionVol[i]->getIdentifiant()!=identifiant)
    {
        i++;
    }
    m_avionVol.erase(m_avionVol.begin()+i);
}

void Arrete::affichage()
{
    std::cout<<"Aeroport initial: "<<m_Aeroport1<<" aeroport final: "<<m_Aeroport2<<" distance: "<<m_ponderation<<std::endl;
}

Graphe::Graphe(std::string nomFichier)
{
    int ordre,taille;
    std::string nomAero;
    int PISTE,PLACE,SOL,ACC,DUR,COL,BOU,decol,identifiant,x,y;
    int ponde;
    int id1,id2;

    std::ifstream ifs{nomFichier};

    if(!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );

    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre");

        for(int i=0;i<ordre;i++)
        {
           ifs>>identifiant>>nomAero>>PISTE>>PLACE>>SOL>>ACC>>DUR>>COL>>decol>>BOU>>x>>y;
            if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture sommet");

            m_liste_aeroport.push_back(new Aeroport{identifiant,nomAero,PISTE,PLACE,SOL,ACC,DUR,COL,decol,BOU,x,y});
        }

        ifs>>taille;
          if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture taille du graphe");

        for(int i=0;i<taille;i++)
        {
            ifs>>id1>>id2>>ponde;
            if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture arc");
            m_liste_aeroport[id1]->ajouterVoisin(m_liste_aeroport[id2]);
            m_liste_aeroport[id2]->ajouterVoisin(m_liste_aeroport[id1]);
            m_arrete.push_back(new Arrete{id1,id2,ponde});
        }
        ChargementAvions();
        int random;
        for(auto avion:m_listeAvions)
        {
            do
            {
                random=rand()%(m_liste_aeroport.size());
            }while(m_liste_aeroport[random]->placeDisponible()==false);
            avion->setX(m_liste_aeroport[random]->getX());
            avion->setY(m_liste_aeroport[random]->getY());
            m_liste_aeroport[random]->setAjouterAvionsSol(avion);
        }

}

Graphe::~Graphe()
{
        for(auto s: m_liste_aeroport)
            delete s;
    }

void Graphe::afficher()const
{
    /*std::cout<<" Ordre: "<<m_liste_aeroport.size()<<std::endl;
    std::cout<<" Taille: "<<m_arrete.size()<<std::endl;

    for(auto avion:m_listeAvions)
        avion->afficher();*/

    for(auto j : m_liste_aeroport)
        j->afficher();

    std::cout<<std::endl;

    for(auto a : m_arrete)
        a->affichage();
}
void Graphe::ChargementAvions()
{
    int nombre;
    std::string nomFichier="Avion.txt";

    /***************************** Ouverture du fichier ******************************/
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    /*******************************************************************************/

    /***************************** Lecture de le nombre d'avions ********************/
    ifs >> nombre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture nombre");
    /*******************************************************************************/

    /******************** Ajout des sucesseurs et de la distance avec le sommet *******************/
    int reservoir,consommation,identifiant;
    std::string type;
    for (int i=0;i<nombre;++i){
        ifs>>type>>identifiant>>consommation>>reservoir;
        if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture arc");
        m_listeAvions.push_back(new Avion{type,identifiant,reservoir});
    }
    /*******************************************************************************/
}
void Graphe::gestionAeroport()
{
    for(auto aeroport:m_liste_aeroport)
    {
        /** Gestion des avions sur la piste **/
        for(auto avion:aeroport->getAvionsPiste())
        {
            if(avion->getUT()==(aeroport->getDecollage()+aeroport->getAcces()))
            {
                if(avion->getReservoir()==avion->getCarburant())
                {
                    Destination(aeroport,avion);
                    for(auto arrete:m_arrete)
                    {
                        if((arrete->getAeroport1()==aeroport->getIdentifiant()&&arrete->getAeroport2()==avion->getTrajet()[0])||(arrete->getAeroport2()==aeroport->getIdentifiant()&&arrete->getAeroport1()==avion->getTrajet()[0]))
                        {
                            arrete->setAjouterAvionVol(avion);
                        }
                    }
                    std::cout<<"LE vol : "<<avion->getIdentifiant();
                    std::cout<<" Decolle de "<<aeroport->getNom();
                    for(auto voisin:aeroport->getVoisin())
                    {
                        if(voisin->getIdentifiant()==avion->getTrajet()[0])
                            std::cout<<" pour "<<voisin->getNom();
                    }
                    std::cout<<std::endl;
                    avion->setUT(0);
                    avion->setVitesse(1000);
                    aeroport->setSupprimerAvionsPiste(avion->getIdentifiant());
                }
                else if(aeroport->placeDisponible()==true)
                {
                    std::cout<<"Le vol : "<<avion->getIdentifiant();
                    std::cout<<" atterrit a : " <<aeroport->getNom()<<std::endl;
                    std::cout<<std::endl;
                    avion->setUT(0);
                    avion->setVitesse(0);
                    aeroport->setAjouterAvionsSol(avion);
                    aeroport->setSupprimerAvionsPiste(avion->getIdentifiant());
                }
            }
            else
            {
                std::cout<<"Le vol : "<<avion->getIdentifiant()<<" est sur la piste de : " <<aeroport->getNom()<<std::endl;
                avion->setUT(avion->getUT()+1);
            }
        }
        /** Gestion des avions en attente **/
        for(auto avion:aeroport->getAvionsAttente())
        {
            if(avion->getUT()==aeroport->getBoucle())
            {
                if(aeroport->pisteDisponible()==true)
                {
                    if(aeroport->placeDisponible()==true)
                    {
                        avion->setUT(0);
                        aeroport->setAjouterAvionsPiste(avion);
                        aeroport->setSupprimerAvionsAttente(avion->getIdentifiant());
                        std::cout<<"Le vol : "<<avion->getIdentifiant();
                        std::cout<<" va pouvoir atterrir a : " <<aeroport->getNom()<<std::endl;
                    }
                    else
                    {
                        avion->setUT(0);
                        std::cout<<"Il n y a pas de place a "<<aeroport->getNom();
                        std::cout<<" pour le vol "<<avion->getIdentifiant()<<std::endl;
                    }
                }
                else
                {
                    avion->setUT(0);
                    std::cout<<"Il n y a pas de piste a "<<aeroport->getNom();
                    std::cout<<" pour le vol "<<avion->getIdentifiant()<<std::endl;
                }
            }
            else
            {
                avion->setUT(avion->getUT()+1);
                std::cout<<"Le vol "<<avion->getIdentifiant()<<std::endl;
                std::cout<<"est en attente au dessus de "<<aeroport->getNom();
            }
        }
        /** Gestion des avions au sol **/
        for(auto avion:aeroport->getAvionsSol())
        {
            if(avion->getUT()==aeroport->getSol())
            {
                if(aeroport->pisteDisponible()==true)
                {
                    avion->setUT(0);
                    avion->setCarburant(avion->getReservoir());
                    aeroport->setAjouterAvionsPiste(avion);
                    aeroport->setSupprimerAvionsSol(avion->getIdentifiant());
                    std::cout<<"Le vol : "<<avion->getIdentifiant();
                    std::cout<<" va pouvoir decoller de : " <<aeroport->getNom()<<std::endl;
                }
            }
            else
            {
                avion->setUT(avion->getUT()+1);
                std::cout<<"Le vol : "<<avion->getIdentifiant();
                std::cout<<" est en attente a : " <<aeroport->getNom()<<std::endl;
            }
        }
    }
}
void Graphe::gestionVol()
{
    for(auto arrete:m_arrete)
    {
        for(auto avion:arrete->getAvionVol())
        {
            std::cout<<"Le vol : "<<avion->getIdentifiant();
            std::cout<<" est en vol entre ";
            std::cout<<m_liste_aeroport[arrete->getAeroport1()]->getNom()<<" "<<m_liste_aeroport[arrete->getAeroport1()]->getIdentifiant();
            std::cout<<" et ";
            std::cout<<m_liste_aeroport[arrete->getAeroport2()]->getNom()<<" "<<m_liste_aeroport[arrete->getAeroport2()]->getIdentifiant();
            std::cout<<" la distance est : "<<arrete->getPonderation()<<std::endl;
        }
    }
}
void Graphe::Destination(Aeroport* aeroport,Avion*avion)
{
    int random;
    random=rand()%(aeroport->getVoisin().size());
    avion->setAjouterTrajet(aeroport->getVoisin()[random]->getIdentifiant());
}
