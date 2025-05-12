#include <stdio.h>
#include <stdbool.h>
#include "librarie.h"




void dfs(bool* visite, int sommet, Graphe* g) {
    visite[sommet] = true;

    Route* route = g->noeud[sommet].liste_adjacence;
    while (route != NULL) {
        int voisin = route->destination;

        
        if (route->etat != DETRUITE && !visite[voisin]) {
            dfs(visite, voisin, g);
        }

        route = route->frere;  // Passage à la route suivante
    }
}


void trouverGroupesChemins(Graphe* g) {
    bool visite[N_SOMMETS] = {false};  
    int groupe = 1;

    for (int i = 0; i < g->Ordre; i++) {
        if (!visite[i]) {
            printf("Groupe %d : ", groupe);

            dfs(visite, i, g);

            for (int j = 0; j < g->Ordre; j++) {
                if (visite[j]) {
                    printf("%s (%d) ", g->noeud[j].sommet.nom, j);
                }
            }

            printf("\n");

           
            for (int j = 0; j < g->Ordre; j++) {
                if (visite[j]) {
                    visite[j] = false;
                }
            }

            groupe++;
        }
    }
}
