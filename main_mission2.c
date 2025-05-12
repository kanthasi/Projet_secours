#include <stdio.h>
#include "librarie.h"  


int main() {
    Graphe graphe;

    generer_sommets(&graphe);  // 50 sommets : 35 villes + 15 hôpitaux

    
    connecter_sommets(&graphe);

   
    printf("=== Groupes de sommets accessibles librement (Mission 2) ===\n\n");
    trouverGroupesChemins(&graphe);

    return 0;
}
