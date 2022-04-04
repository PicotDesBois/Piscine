#include "Avion.h"

using namespace std;
void ChargementAvions(std::vector<Avion*>m_listeAvions);

int main()
{
    std::vector<Avion*>m_listeAvions;
    ChargementAvions(m_listeAvions);

    return 0;
}
void ChargementAvions(std::vector<Avion*>m_listeAvions)
{
    int nombre;
    std::string nomFichier="Avion.txt";

    /***************************** Ouverture du fichier ******************************/
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    /*******************************************************************************/

    /***************************** Lecture du nombre d'avions ********************/
    ifs >> nombre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture nombre");
    /*******************************************************************************/

    /******************** Création des avions *******************/
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


