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
