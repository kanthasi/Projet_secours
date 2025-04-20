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
} Sommet;

typedef struct {
    int distance;
    char etat[20];
    int capacite_circulation;
    bool fluide;
    bool priorite;
    bool est_endommage;
    bool securise;
} Route;

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

#endif
