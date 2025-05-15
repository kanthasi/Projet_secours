
void Creation_circuit(int circuit[N_CIRCUITS][N_SOMMETS], int nombre_circuits)
{
    if(nombre_circuits < 1)
    {
        return; // aucun circuit cree
    }

    for(int i=0; i < nombre_circuits; i ++)
    {
        int sommets_utilises[N_SOMMETS]={0};

        int j = 0;
        while(j < N_SOMMETS)
        {
            // Choix aleatoire de villes contenue dans le circuit
            int ville = rand() % N_SOMMETS;

            if(sommets_utilises[ville] == 0) // Si la ville ne fait pas encore parti du circuit
            {
                circuit[i][j] = ville; // Ajout de cette ville au circuit
                sommets_utilises[ville] = 1; // Cette ville a desormais ete utilisee
                j ++;
            }
        }
    }
}

void Afficher_circuits(int circuit[], int taille)
{
    for(int i = 0; i < taille; i ++)
    {
            printf("%s", sommet[circuit[i]].nom);
            if(i < taille-1)
            {
                printf("->");
            }
    }
}


// Main 
// Ajout de #define N_CIRCUITS 4
int main()
{
    int circuits[N_CIRCUITS][N_SOMMETS];

    Creation_circuit(circuits, N_CIRCUITS);

    printf("\nLes circuits sont : \n");
    for(int i = 0; i < N_CIRCUITS; i ++)
    {
        Afficher_circuits(circuits[i], 4);

        printf("->%s \n", sommet[circuits[i][0]].nom);
    }
}
