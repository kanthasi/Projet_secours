
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
    TypeRessource type;
    int poids;
    int valeur_nutritive;
    int priorite; // Médicament = 1, Nourriture = 2
} Ressource;
