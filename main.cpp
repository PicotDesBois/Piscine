#include "headers.h"

using namespace std;

int main()
{
    int saisie=0;

    srand(time(NULL));
    Graphe g{"aeroport.txt"};
    g.afficher();

    while(saisie!=1)
    {
        std::cin>>saisie;
         g.gestionAeroport();
         g.gestionVol();
    }


    return 0;
}
