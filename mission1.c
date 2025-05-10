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
    int max_routes = 40;
    int routes_creees = 0;

    for(int indice1 = 0; indice1 < N_SOMMETS; indice1 ++)
    {
        for(int indice2 = 0; indice2 < N_SOMMETS; indice2 ++)
        {
            if(indice1 != indice2 && routes_creees < max_routes) // pas de boucles
            {
                int probabilite = rand() % 3; 

                if(probabilite == 0)
                {
                    Route *route = creer_route();

                    if(route != NULL) // si la proba est de 1 dans la fonction creer_route
                    {
                        graphe[indice1][indice2] = route; // ajout de cette route au graphe
                        routes_creees ++; 
                    }    
                }
            }
        }
    }
}

bool parcouru[N_SOMMETS];
Sommet sommet[N_SOMMETS];
Route *graphe[N_SOMMETS][N_SOMMETS];

// Parcours en profondeur
void Afficher_chemin_accessible(int num_sommet, int chemin[], int longueur_chemin, Route *graphe[N_SOMMETS][N_SOMMETS], bool parcouru[N_SOMMETS], Sommet sommet[N_SOMMETS])
{
    parcouru[num_sommet] = true; // le sommet a ete parcouru
    bool voisin_existant = false;
    chemin[longueur_chemin] = num_sommet;

    longueur_chemin ++;

    for(int indice = 0; indice < N_SOMMETS; indice ++)
    {
        if(graphe[num_sommet][indice] != NULL && graphe[num_sommet][indice]->etat != DETRUITE && parcouru[indice] == false && graphe[num_sommet][indice]->vehicules_routes < graphe[num_sommet][indice]->capacite_circulation) // s'il y a une route entre les 2 sommets qui n'est pas détruite et pas pleine et que le sommet (qui n'est pas le départ) n'a pas été visité
        {
            voisin_existant = true;
            Afficher_chemin_accessible(indice, chemin, longueur_chemin, graphe, parcouru, sommet);
        }
    }

    if(voisin_existant == false) // Si on a atteint la fin du chemin
    {
        for(int i = 0; i < longueur_chemin; i ++)
        {
            printf("%s", sommet[chemin[i]].nom);
            if(i != longueur_chemin - 1) // si on n'a pas atteint le dernier sommet du chemin sachant que : valeurs de i vont de 0 a longueur_chemin - 1
            {
                printf("->");
            }
        }
        printf("\n"); // Le chemin ne peut pas etre etendu
    }

    parcouru[num_sommet] = false;
}

// question 3
void afficher_sommets_inaccessibles(bool parcouru[N_SOMMETS], Sommet sommet[N_SOMMETS]) {
    printf("\n=== Sommets inaccessibles après le tremblement de terre ===\n");
    for (int i = 0; i < N_SOMMETS; i++) {
        if (!parcouru[i]) {
            printf(" - %s\n", sommet[i].nom);
        }
    }
}


