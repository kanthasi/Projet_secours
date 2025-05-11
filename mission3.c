// Mission 3 
#define Infini 200

// Prendre sommet tel que non-traité + avec la distance minimale
int Sommet_DistanceMinimale(int distance[], bool distance_trouvee[]) // ici distance : Tableau avec distances depuis le départ vers les autres sommets*
{
    // Initialisation :
    int min = Infini;
    int indice = 0;

    for(int i=0; i < N_SOMMETS; i++)
    {
        if(distance_trouvee[i] == false && distance[i] < min)
        {
            min = distance[i]; // Le minimum devient alors la distance depuis le départ vers le sommet concerne
            indice = i;
        }
    }
    
    return indice; // retourner l'indice du sommet avec la distance minimale 
}

# define AUCUN_Predecesseur -1

void Djikstra(Route *graphe[N_SOMMETS][N_SOMMETS], int Distance[], int SommetDepart, int Predecesseur[])
{
    // Ici les longueurs sont positives ou nulles, l'algorithme de Djikstra est donc applicable pour determiner les plus courts chemins a partir du sommet de depart

    // Initialisation
    for(int i = 0; i < N_SOMMETS; i ++)
    {
        Distance[i] = Infini;
        Predecesseur[i] = AUCUN_Predecesseur; // Pas de predecesseur au debut de la recherche
    }
    Distance[SommetDepart] = 0; // Distance Depart-Depart = 0

    bool visite[N_SOMMETS] = {false}; // Aucun sommet visite pour l'instant

    for(int passage = 0; passage < N_SOMMETS; passage ++)
    {
        // Obtenir sommet non-visite avec la plus courte distance 
        int LeSommet = Sommet_DistanceMinimale(Distance, visite);

        visite[LeSommet] = true; // Ce sommet devient visite
        
        // Explorer les voisins du sommet actuel
        for(int voisin = 0; voisin < N_SOMMETS; voisin ++)
        {
            if(graphe[LeSommet][voisin] != NULL && visite[voisin] == false) // S'il existe une route et que le voisin n'a pas encore ete visite
            {
                if(graphe[LeSommet][voisin]->etat != DETRUITE)
                {
                    int nouvelle_distance = graphe[LeSommet][voisin]->distance + Distance[LeSommet];
                    if(nouvelle_distance < Distance[voisin])
                    {
                        Distance[voisin] = nouvelle_distance; // Actualisation de la distance
                        Predecesseur[voisin] = LeSommet;
                    } 
                }
            }
        }
    }
}

int Chemin_Djikstra(int SommetArrivee, int Predecesseur[], int chemin[])
{
    int longueur = 0;
    int Sommet_courant = SommetArrivee;

    while(Sommet_courant != AUCUN_Predecesseur)
    {
        chemin[longueur] = Sommet_courant;
        
        longueur ++;

        Sommet_courant = Predecesseur[Sommet_courant];
    }

    for(int i = 0; i < longueur/2; i ++)
    {
        int sommet = chemin[i];
        chemin[i] = chemin[longueur - 1 - i];
        chemin[longueur - 1 - i] = sommet;
    }

    return longueur;
}

void Endommager(Route *graphe[N_SOMMETS][N_SOMMETS]) // endommage des villes de maniere aleatoire
{
    int sommet1 = rand()% N_SOMMETS;
    int sommet2 = rand()% N_SOMMETS;

    if(sommet1 != sommet2 && graphe[sommet1][sommet2] != NULL && graphe[sommet1][sommet2]->etat == NON_ENDOMMAGEE) // Il n'y a pas de boucles dans ce graphe, si la route entre les 2 sommets existe, pour qu'elle soit endommagee il faut qu'elle soit intacte
    {
        graphe[sommet1][sommet2]->etat = ENDOMMAGEE;
        graphe[sommet1][sommet2]->est_endommagee = true;
    }
}

void Djikstra_endommagement(Route *graphe[N_SOMMETS][N_SOMMETS], int Distance[], int SommetDepart, int Predecesseur[])
{
    // Ici les longueurs sont positives ou nulles, l'algorithme de Djikstra est donc applicable pour determiner les plus courts chemins a partir du sommet de depart
    // Dans cette version : nouvelles villes endommagees non-accessibles et villes endommagees a la base egalement
    // Initialisation
    for(int i = 0; i < N_SOMMETS; i ++)
    {
        Distance[i] = Infini;
        Predecesseur[i] = AUCUN_Predecesseur; // Pas de predecesseur au debut de la recherche
    }
    Distance[SommetDepart] = 0; // Distance Depart-Depart = 0

    bool visite[N_SOMMETS] = {false}; // Aucun sommet visite pour l'instant

    for(int passage = 0; passage < N_SOMMETS; passage ++)
    {
        // Obtenir sommet non-visite avec la plus courte distance 
        int LeSommet = Sommet_DistanceMinimale(Distance, visite);

        visite[LeSommet] = true; // Ce sommet devient visite
        
        // Explorer les voisins du sommet actuel
        for(int voisin = 0; voisin < N_SOMMETS; voisin ++)
        {
            if(graphe[LeSommet][voisin] != NULL && visite[voisin] == false) // S'il existe une route et que le voisin n'a pas encore ete visite
            {
                if(graphe[LeSommet][voisin]->etat == NON_ENDOMMAGEE)
                {
                    int nouvelle_distance = graphe[LeSommet][voisin]->distance + Distance[LeSommet];
                    if(nouvelle_distance < Distance[voisin])
                    {
                        Distance[voisin] = nouvelle_distance; // Actualisation de la distance
                        Predecesseur[voisin] = LeSommet;
                    } 
                }
            }
        }
    }
}
