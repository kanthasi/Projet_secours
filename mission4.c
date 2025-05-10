#include <stdio.h>
#include <stdlib.h>
#include "librarie.h"



// Fonction de comparaison pour trier les routes candidates par distance croissante
int comparer_routes(const void *a, const void *b) {
    return ((RouteCandidate *)a)->distance - ((RouteCandidate *)b)->distance;
}

// Trouve le représentant d’un sommet dans l’ensemble (avec compression de chemin)
int trouver_representant(int parent[], int sommet) {
    if (parent[sommet] != sommet)
        parent[sommet] = trouver_representant(parent, parent[sommet]);
    return parent[sommet];
}

// Fusionne deux ensembles (union des composantes connexes)
void fusion_ensembles(int parent[], int x, int y) {
    int representant_x = trouver_representant(parent, x);
    int representant_y = trouver_representant(parent, y);
    if (representant_x != representant_y)
        parent[representant_y] = representant_x;
}

// Fonction principale pour identifier les routes à sécuriser (Kruskal)
void identifier_routes_a_securiser(Graphe *graphe) {
    RouteCandidate routes_possibles[N_SOMMETS * N_SOMMETS];
    int nombre_routes = 0;

    // Étape 1 : collecter toutes les routes du graphe
    for (int i = 0; i < graphe->Ordre; i++) {
        Route *r = graphe->noeud[i].liste_adjacence;
        while (r != NULL) {
            routes_possibles[nombre_routes].depart = i;
            routes_possibles[nombre_routes].arrivee = r->destination;
            routes_possibles[nombre_routes].distance = r->distance;
            nombre_routes++;
            r = r->frere;
        }
    }

    // Étape 2 : trier les routes par distance croissante
    qsort(routes_possibles, nombre_routes, sizeof(RouteCandidate), comparer_routes);

    // Étape 3 : initialiser les ensembles pour l’union-find
    int representants[N_SOMMETS];
    for (int i = 0; i < graphe->Ordre; i++)
        representants[i] = i;

    // Étape 4 : appliquer l’algorithme de Kruskal
    printf("\n--- Routes à sécuriser (coût minimal) ---\n");

    int cout_total = 0;
    int routes_choisies = 0;

    for (int i = 0; i < nombre_routes && routes_choisies < graphe->Ordre - 1; i++) {
        int a = routes_possibles[i].depart;
        int b = routes_possibles[i].arrivee;

        if (trouver_representant(representants, a) != trouver_representant(representants, b)) {
            printf(" %s → %s (%d km)\n",
                   graphe->noeud[a].sommet.nom,
                   graphe->noeud[b].sommet.nom,
                   routes_possibles[i].distance);
            fusion_ensembles(representants, a, b);
            cout_total += routes_possibles[i].distance;
            routes_choisies++;
        }
    }

    printf("Coût total des routes sécurisées : %d km\n", cout_total);
}
