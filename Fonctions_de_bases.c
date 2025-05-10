#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Librairie.h"

// AU final j'ai mis ca dans le main principal
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



void afficher_voisins(int i) {
    printf("\nConnexions de %s :\n", sommets[i].nom);
    for (int j = 0; j < N_SOMMETS; j++) {
        if (graphe[i][j]) {
            printf(" -> %s [%dkm, %s]\n", sommets[j].nom, graphe[i][j]->distance, graphe[i][j]->etat);
        }
    }
}

Route *creer_route()
{
    Route *route = malloc(sizeof(Route)); // Allocation dynamique pour les routes

    route->distance =  rand() % 200 + 10; // génération aléatoire d'une distance (entre 10 et 200km par ex)

    route->capacite_circulation = (route->distance)*2; // 2 véhicules par km

    route->vehicules_routes = rand()% (route->capacite_circulation + 1);

    // fluide
    int estfluide =rand()%2;
    if(estfluide == 0)
    {
        route->fluide = true;
    }
    else
    {
        route->fluide = false;
    }

    // priorité
    int estprioritaire =rand()%2;
    if(estprioritaire == 0)
    {
        route->priorite = true;
    }
    else
    {
        route->priorite = false;
    }

    // securisation
    int securisation =rand()%2;
    if(securisation == 0)
    {
        route->securisee = true;
    }
    else
    {
        route->securisee = false;
    }

    // etat
    int etat_attribue = rand()%3;
    if(etat_attribue == 0)
    {
        route->etat = NON_ENDOMMAGEE;
        route->est_endommagee = false;
    }
    else if(etat_attribue == 1)
    {
        route->etat = ENDOMMAGEE;
        route->est_endommagee = true;
    }
    else 
    {
        route->etat = DETRUITE;
        route->est_endommagee = true;
    }

    return route;
}


int main() {
    srand(time(NULL));
    generer_sommets();
    connecter_sommets();
    sauvegarder_donnees("data.txt");
    afficher_voisins(0); // Exemple : afficher les voisins du sommet 0
    creer_route();
    return 0;
}

