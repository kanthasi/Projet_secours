#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Librairie.h"

Sommet sommets[N_SOMMETS];
Route* graphe[N_SOMMETS][N_SOMMETS];
void generer_sommets() {
    int i;
    for (i = 0; i < N_SOMMETS; i++) {
        if (i < 35) { // Ville
            strcpy(sommets[i].nom, villes[i % 35]);
            sommets[i].est_hopital = 0;
            sommets[i].nb_habitants = rand() % 500000 + 10000;
        } else { // Hôpital
            strcpy(sommets[i].nom, hopitaux[i % 15]);
            sommets[i].est_hopital = 1;
            sommets[i].nb_malade = rand() % 300;
            sommets[i].place_disponible = rand() % 200 + 50;
        }
    }
}

void connecter_sommets() {
    for (int i = 0; i < N_SOMMETS; i++) {
        int connexions = rand() % 5 + 3; // entre 3 et 7
        for (int j = 0; j < connexions; j++) {
            int cible = rand() % N_SOMMETS;
            if (cible != i && graphe[i][cible] == NULL) {
                graphe[i][cible] = creer_route();
            }
        }
    }
}

void afficher_voisins(int i) {
    printf("\nConnexions de %s :\n", sommets[i].nom);
    for (int j = 0; j < N_SOMMETS; j++) {
        if (graphe[i][j]) {
            printf(" -> %s [%dkm, %s]\n", sommets[j].nom, graphe[i][j]->distance, graphe[i][j]->etat);
        }
    }
}

int main() {
    srand(time(NULL));
    generer_sommets();
    connecter_sommets();
    sauvegarder_donnees("data.txt");
    afficher_voisins(0); // Exemple : afficher les voisins du sommet 0
    return 0;
}

