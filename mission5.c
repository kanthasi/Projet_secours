void envoyer_vehicules_secours(Graphe *g, int nb_vehicules, Vehicule_Secours *vs, int sommet_depart) 
{
    for (int i = 0; i < g->Ordre; i++) {
        if (i == sommet_depart)
            continue;

        Sommet s = g->noeud[i].sommet;

        if (s.nb_malade > 0 || s.nb_habitants > 0) {
            TypeUrgence urgence = URGENCE_INCENDIE;  
            printf("Sommet en urgence : %s\n", s.nom);

            Route *r = g->noeud[sommet_depart].liste_adjacence;
            while (r != NULL) {
                if (r->destination == i && r->etat != DETRUITE && r->capacite_circulation > 0) {
                    float delai = calcul_delai_transport(r, urgence);
                    printf("Envoi de véhicules vers %s (délai estimé : %.2f)\n", s.nom, delai);

                    int nb_envoyes = 0;
                    for (int v = 0; v < nb_vehicules && nb_envoyes < r->capacite_circulation; v++) {
                        if (vs[v].est_en_service) {
                            printf("  → Véhicule %d envoyé\n", v);
                            vs[v].est_en_service = false;
                            nb_envoyes++;
                        }
                    }

                    if (nb_envoyes == 0)
                        printf("  Aucun véhicule disponible\n");
                }
                r = r->frere;
            }
        }
    }
}

     
         
    }
float calculdelaistranport (Route r , Typeurgence tr)
{
    float delais = r.distance //je considere 1 unite de temps = 1 untite de distance 
    if(r.etat==ENDOMMAGE)
    {
        delais += 10; // si la route est endommage alors elle augmente le temps 
            }    
        if (tr == URENCE_INCENDIE){
            delais -= 10; //je diminue si on est incendie 
                
    }
    return delais ;
}


// Partie 2 de la mission 5
void Tri_vehicules(Vehicule_Secours *vehicules, int nombre_vehicules) // Trie les vehicules de secours en fonction de leur capacite de chargement
{
    // Tri a bulles
    for(int i = 0; i < nombre_vehicules - 1; i ++)
    {
        for(int j = nombre_vehicules - 1; j > i; j--)
        {
            if(vehicules[j].charge_max > vehicules[i].charge_max)
            {
                Vehicule_Secours Vehicule_temporaire = vehicules[i];
                vehicules[i] = vehicules[j];
                vehicules[j] = Vehicule_temporaire;
            }
        }
    }
}

int Priorite_vehicules_secours(Vehicule_Secours* vehicule, int nombre_vehicules, int *indices)
{
    int k = 0;

    for(int i = 0; i < nombre_vehicules; i ++)
    {
        if(vehicule[i].est_en_service == true && vehicule[i].charge_actuelle < vehicule[i].charge_max) // Si le vehicule est disponible et qu'il peut encore porter des charges
        {
            indices[k] = i;
            k ++; // Le vehicule est envoye
        }
    } 
    return k;
}
