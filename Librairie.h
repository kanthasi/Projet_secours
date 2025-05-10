// structure.h
#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdbool.h> 
#define MAX_RESSOURCES 10
#define MAX_NOM 30
#define N_SOMMETS 50

typedef struct {
    char nom[20];
    int poids;
    int valeur_nutritive;
    int priorite;  // 1 = médicament prioritaire
} Ressource;

typedef struct {
    char nom[MAX_NOM];
    bool est_hopital;

    int nb_habitants;       // si ville
    int nb_malade;          // si hôpital
    int place_disponible;

    Ressource stock[MAX_RESSOURCES];
    int nb_ressources;
    int nombre;
} Sommet;

typedef enum 
{ 
    FLUIDE, 
    BOUCHE 
} 
TypeTrafic; 

typedef struct 
{ 
    TypeTrafic type; 
    bool priorite; 
} 
Trafic; 

typedef enum 
{ 
    DETRUITE, 
    ENDOMMAGEE, 
    NON_ENDOMMAGEE 
} 
EtatRoute; 

typedef struct 
{
    int distance;
    EtatRoute etat;
    int capacite_circulation;
    bool fluide;
    bool priorite;
    bool est_endommage;
    bool securise;
    int vehicules_routes;
    int destination;
    Route * frere ;
} 
Route;

// ressources 
typedef enum {MEDICAMENT, NOURRITURE} TypeRessource;
typedef struct {
  int medicamment;
  int nourritures;
  int eau; 
  int equipement; 
}Ressources; 



typedef struct {
  float charge_max;
  float charge_actuelle;
  bool est_en_service; 
}Vehicule_Secours;

typedef struct {
Sommet sommet; 
Route * liste_adjacence; 
}NoeudGraphe 

typedef struct {
NoeudGraphe noeud [Max_Sommet];
int Ordre; 
}Graphe 

typedef struct {
    int depart;
    int arrivee;
    int distance;
} RouteCandidate;

void identifier_routes_a_securiser(Graphe *graphe);

void generer_sommets();
void afficher_voisins(int i);
Route* creer_route();
void connecter_sommets();
void Creation_graphe(Route *graphe[N_SOMMETS][N_SOMMETS]);

void afficherRoutes(Graphe* g);
void afficher_etat_route(EtatRoute etat);
void Afficher_chemin_accessible(int num_sommet, Route *graphe[N_SOMMETS][N_SOMMETS], bool parcouru[N_SOMMETS], Sommet sommet[N_SOMMETS]);
void afficher_sommets_inaccessibles(bool parcouru[N_SOMMETS], Sommet sommet[N_SOMMETS]);

void identifier_groupes_connexes(Sommet sommets[N_SOMMETS], Route *graphe[N_SOMMETS][N_SOMMETS]);

void determiner_plus_court_chemin(int sommet_depart, Route *graphe[N_SOMMETS][N_SOMMETS], Sommet sommets[N_SOMMETS]);

int extraire_routes_valides(Route *graphe[N_SOMMETS][N_SOMMETS], Arete aretes[]);
void kruskal(Route *graphe[N_SOMMETS][N_SOMMETS], Sommet sommets[N_SOMMETS]);
void afficher_routes_a_securiser(Arete aretes[], int nb_aretes);

void planifier_secours(Sommet sommets[N_SOMMETS], Route *graphe[N_SOMMETS][N_SOMMETS], Vehicule_Secours vehicules[], int nb_vehicules, int sommet_depart);
void trier_vehicules_prioritaires(Vehicule_Secours vehicules[], int nb_vehicules, Sommet sommets[N_SOMMETS]);
int calculer_delai_transport(Route *r);
char* determiner_type_urgence(Sommet s);
void afficher_mission_secours(Sommet sommets[N_SOMMETS], Vehicule_Secours vehicules[], int nb_vehicules, Route *graphe[N_SOMMETS][N_SOMMETS]);


#endif
