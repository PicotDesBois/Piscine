#include "aeroport.h"

using namespace std;

Aeroport::Aeroport(int identifiant,std::string name,int piste,int place,int sol,int access,int duree,int anticol,int decollage,int bouc):
    m_identifiant{identifiant},m_nom{name},m_nbPistes{piste},m_nbPlaces{place},m_attSol{sol},m_acces{access},m_duree{duree},m_anticollision{anticol},m_tempsDecollage{decollage},m_boucle{bouc}{}

std::string Aeroport::getNom()const{return m_nom;}
int Aeroport::getPistes()const{return m_nbPistes;}
int Aeroport::getPlaces()const{return m_nbPlaces;}
int Aeroport::getSol()const{return m_attSol;}
int Aeroport::getAcces()const{return m_acces;}
int Aeroport::getDuree()const{return m_duree;}
int Aeroport::getCollision()const{return m_anticollision;}
int Aeroport::getBoucle()const{return m_boucle;}
int Aeroport::getDecollage()const{return m_tempsDecollage;}
std::vector<Aeroport*>& Aeroport::getVoisin(){return m_aeroportsVoisin;}
void Aeroport::setNom(std::string Name){m_nom=Name;}
void Aeroport::setPistes(int nombrPistes){m_nbPistes=nombrPistes;}
void Aeroport::setPlaces(int nombrPlaces){m_nbPlaces=nombrPlaces;}
void Aeroport::setSol(int atterisol){m_attSol=atterisol;}
void Aeroport::setAcces(int acceder){m_acces=acceder;}
void Aeroport::setDuree(int timer){m_duree=timer;}
void Aeroport::setCollision(int coli){m_anticollision=coli;}
void Aeroport::setBoucle(int bou){m_boucle=bou;}
void Aeroport::ajouterVoisin(Aeroport*voisin){m_aeroportsVoisin.push_back(voisin);}

void Aeroport::afficher_liste()const
{
    std::cout<<" Aeroport: "<<m_nom<<std::endl;
    std::cout<<" Identifiant: "<<m_identifiant<<std::endl;
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
    std::cout<<std::endl;
}

Arrete::Arrete(int ini, int fin, int ponderation):
    m_Aeroport1{ini},m_Aeroport2{fin},m_ponderation{ponderation} {}

///getters
int Arrete::getAeroport1()const{return m_Aeroport1;}
int Arrete::getAeroport2()const{return m_Aeroport2;}
int Arrete::getPonderation()const{return m_ponderation;}
///setters
void Arrete::setPonderation(int pond){m_ponderation=pond;}

void Arrete::affichage()
{
    std::cout<<"Aeroport initial: "<<m_Aeroport1<<" aeroport final: "<<m_Aeroport2<<" distance: "<<m_ponderation<<std::endl;
}

Graphe::Graphe(std::string nomFichier)
{
    int ordre,taille;
    std::string nomAero;
    int PISTE,PLACE,SOL,ACC,DUR,COL,BOU,decol,identifiant;
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
           ifs>>identifiant>>nomAero>>PISTE>>PLACE>>SOL>>ACC>>DUR>>COL>>decol>>BOU;
            if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture sommet");

            m_liste_aeroport.push_back(new Aeroport{identifiant,nomAero,PISTE,PLACE,SOL,ACC,DUR,COL,decol,BOU});
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
}

Graphe::~Graphe()
{
        for(auto s: m_liste_aeroport)
            delete s;
    }

void Graphe::afficher()const
{
    std::cout<<" Ordre: "<<m_liste_aeroport.size()<<std::endl;
    std::cout<<" Taille: "<<m_arrete.size()<<std::endl;

    for(auto avion:m_listeAvions)
        avion->afficher();

    for(auto j : m_liste_aeroport)
        j->afficher_liste();

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
