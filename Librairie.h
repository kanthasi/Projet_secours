typedef enum {
        URGENCE INCENDIE 
        URGENCE EVACUATION 
        AUCUNE_URGENCE 
}typeURGENCE;
typedef struct {
    typeUrgence type 
    int niveau;
    int personne en danger;
    bool besoin de ressource;
}Urgence;
typedef struct {
    char nom[50];
    int nb_habitants;
} Ville;

typedef struct {
    char nom[50];
    int nb_malades;
    int places_disponibles;
    Ressource stock[10];
    int nb_ressources;
} Hopital;


typedef enum {VILLE_TYPE, HOPITAL_TYPE} TypeSommet;

typedef struct {
    int id;
    float distance_epicentre;
    bool est_endommage;
    TypeSommet type;
    union {
        Ville ville;
        Hopital hopital;
    };
} Sommet;


// ressources 
typedef enum {MEDICAMENT, NOURRITURE} TypeRessource;
typedef struct {
  int medicamment;
  int nourritures;
  int eau; 
  int equipement; 
}Ressources; 

typedef struct {
    TypeRessource type;
    int poids;
    int valeur_nutritive;
    int priorite; // Médicament = 1, Nourriture = 2
} Ressource;

typedef struct {
  float charge_max;
  float charge_actuelle;
  bool est_en_service; 
}Vehicule_Secours;
