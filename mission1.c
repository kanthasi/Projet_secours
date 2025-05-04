void afficherRoutes(Graphe* g) {
    printf("Liste des routes du graphe :\n");
    for (int i = 0; i < g->Ordre; i++) {
        Route* route = g->noeud[i].liste_adjacence;
        while (route != NULL) {
            printf("Route de %d vers %d - Distance: %d - État: %d - Capacité: %d\n",
                   i,
                   route->destination,
                   route->distance,
                   route->etat,
                   route->capacite_circulation);
            route = route->frere;
        }
    }
}

void Creation_graphe(Route *graphe[N_SOMMETS][N_SOMMETS])
{
    for(int indice1 = 0; indice1 < N_SOMMETS; indice1 ++)
    {
        for(int indice2 = indice1 + 1; indice2 < N_SOMMETS; indice2 ++)
        {
            if(indice1 != indice2) // pas de boucles
            {
                Route *route = creer_route();

                if(route != NULL) // si la proba est de 1 dans la fonction creer_route
                {
                    graphe[indice1][indice2] = route; // ajout de cette route au graphe
                }
            }
        }
    }
}

bool parcouru[N_SOMMETS];
Sommet sommet[N_SOMMETS];
Route *graphe[N_SOMMETS][N_SOMMETS];

// Parcours en profondeur
void Afficher_chemin_accessible(int num_sommet, Route *graphe[N_SOMMETS][N_SOMMETS], bool parcouru[N_SOMMETS], Sommet sommet[N_SOMMETS])
{
    parcouru[num_sommet] = true; // le sommet a été parcouru
    printf("Le sommet %s a été parcouru. \n", sommet[num_sommet].nom);

    for(int indice = 0; indice < N_SOMMETS; indice ++)
    {
        if(graphe[num_sommet][indice] != NULL && graphe[num_sommet][indice]->etat != DETRUITE && parcouru[indice] == false && graphe[num_sommet][indice]->vehicules_routes < graphe[num_sommet][indice]->capacite_circulation) // s'il y a une route entre les 2 sommets qui n'est pas détruite et pas pleine et que le sommet (qui n'est pas le départ) n'a pas été visité
        {
            printf("Le chemin entre %s et %s est accessible ! \n", sommet[num_sommet].nom, sommet[indice].nom);
            Afficher_chemin_accessible(indice, graphe, parcouru, sommet);
        }
    }
}

