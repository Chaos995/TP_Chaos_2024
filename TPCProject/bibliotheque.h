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

int user_choice();
void admin();
void user();
int number();
void filling_struct(books book[], int n);
void file_creation(books book[], int n);
void modify();
void delete_book();
void rechercher();
void Trie();

#endif
