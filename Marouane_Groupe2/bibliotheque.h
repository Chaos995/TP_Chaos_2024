#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H
#define MAX 100

typedef struct{
    char ID[30];
    char Titre[30];
    char Auteur[30];
    char Description[MAX];
    char Nom_utilisateur[30];
    float Prix;
    char Categorie[30];
    int Disponibilite;
}books;

int user_choice();//Student 1:
void admin();//Student 1:
void user();//Student 1:

int number();//Student 2:
void filling_struct(books book[], int n);//Student 2:
void file_creation(books book[], int n);//Student 2:

void modify();//Student 3:

void delete_book();//Student 4:

void rechercher();//Student 5:

void trie_admin();//Student 6:
void trie_user();//Studen 6:

#endif
