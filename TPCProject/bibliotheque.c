#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bibliotheque.h"

void clear_input() //clears the user input from any left overs like '\n' after scanf
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int user_choice() //takes the user choice, whether he is an admin or a user
{

    int choice;
    char password[10];

    printf("0. Admin\n");
    printf("1. User\n");

    printf("Your Choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        return choice;
    } else if (choice == 0) {
        printf("Login: Admin\n");
        printf("Enter Password: ");
        scanf("%s", password);

        if (strcmp(password, "admin0000") == 0) {
            return choice;
        } else {
            printf("Password is incorrect!\n");
            return -1;
        }
    } else {
        printf("Invalid choice!\n");
        return -1;
    }
}

void admin() //if the user is an adimn this function is called, it shows the possible function to call by an admin
{
    books book[MAX];
    int n;
    int choice;

    while(1){
        printf("--- Admin Menu ---\n");
        printf("1. Add Book\n");
        printf("2. Modify Book\n");
        printf("3. Delete Book\n");
        printf("4. Search for a Book\n");
        printf("5. Sort the books\n");
        printf("0. Exit\n");

        printf(": ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                n = number();
                filling_struct(book, n);
                file_creation(book, n);
                break;
            case 2:
                modify();
                break;
            case 3:
                delete_book();
                break;
            case 4:
                rechercher();
                break;
            case 5:
                Trie();
                break;
            case 0:
                exit(0);
                break;
        }
    }
}

void user() //if the user is NOT an admin this function is called, it shows the possible function to call/use by normal users
{
    int choice;

    while(1){
        printf("--- User Menu ---\n");
        printf("1. Search for a Book\n");
        printf("2. Sort the books\n");
        printf("0. Exit\n");

        printf(": ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                rechercher();
                break;
            case 2:
                Trie();
                break;
            case 0:
                exit(0);
                break;
        }
    }
}

int number() //takes the number of the books the admin wanna add, not accessible by the normal users
{
    int n;

    printf("enter the number of books you wanna add: ");
    scanf("%d", &n);
    getchar();

    return n;
}

void filling_struct(books *book, int n) //this function fill up the struct with the info of the books, not accessible by the normal users
{
    int i;

    for(i=0; i<n; i++){
        printf("Saisir %d ID: ", i+1);
        scanf("%s", book[i].ID);
        clear_input();
        printf("Saisir Titre: ");
        fgets(book[i].Titre, sizeof(book[i].Titre), stdin);
        printf("Saisir Auteur: ");
        fgets(book[i].Auteur, sizeof(book[i].Auteur), stdin);
        printf("Saisir Description: ");
        fgets(book[i].Description, sizeof(book[i].Description), stdin);
        printf("Saisir Nom_utilisateur: ");
        fgets(book[i].Nom_utilisateur, sizeof(book[i].Nom_utilisateur), stdin);
        printf("Saisir Prix: ");
        scanf("%f", &book[i].Prix);
        clear_input();
        printf("Saisir Categorie: ");
        fgets(book[i].Categorie, sizeof(book[i].Categorie), stdin);
        printf("Saisir Disponibilite: (0:false, 1:true)");
        scanf("%d", &book[i].Disponibilite);
        clear_input();
    }
}

void file_creation(books *book, int n) //this function create the files and fills them with the necessary info, not accessible by the normal user
{
  int i;


  FILE *f = fopen("Books.txt", "w");
  for(i=0; i<n; i++){


    fprintf(f, "ID: %s\n", book[i].ID);
    fprintf(f, "Titre: %s", book[i].Titre);
    fprintf(f, "Auteur: %s", book[i].Auteur);
    fprintf(f, "Description: %s", book[i].Description);
    fprintf(f, "Nom_utilisateur: %s", book[i].Nom_utilisateur);
    fprintf(f, "Prix: %f\n", book[i].Prix);
    fprintf(f, "Categorie: %s", book[i].Categorie);
    fprintf(f, "Disponibilite: %d\n", book[i].Disponibilite);
  }
  fclose(f);

}

void modify() //this function allow the admin to modify the books info, not accessible by normal users
{
    FILE *f = fopen("Books.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    char ID_M[30];
    printf("Enter the ID of the book you wanna modify: ");
    scanf("%s", ID_M);
    clear_input();

    books book;
    while (fscanf(f, "ID: %s\n", book.ID) == 1) {
        fscanf(f, "Titre: %[^\n]\n", book.Titre);
        fscanf(f, "Auteur: %[^\n]\n", book.Auteur);
        fscanf(f, "Description: %[^\n]\n", book.Description);
        fscanf(f, "Nom_utilisateur: %[^\n]\n", book.Nom_utilisateur);
        fscanf(f, "Prix: %f\n", &book.Prix);
        fscanf(f, "Categorie: %[^\n]\n", book.Categorie);
        fscanf(f, "Disponibilite: %d\n", &book.Disponibilite);

        if (strcmp(book.ID, ID_M) == 0) {

            char choice[30];
            printf("What do you wanna change? ");
            scanf("%s", choice);
            clear_input();

            if (strcmp(choice, "Titre") == 0) {
                printf("Enter new Titre: ");
                fgets(book.Titre, sizeof(book.Titre), stdin);
            } else if (strcmp(choice, "Auteur") == 0) {
                printf("Enter new Auteur: ");
                fgets(book.Auteur, sizeof(book.Auteur), stdin);
            } else if (strcmp(choice, "Description") == 0) {
                printf("Enter new Description: ");
                fgets(book.Description, sizeof(book.Description), stdin);
            } else if (strcmp(choice, "Nom_utilisateur") == 0) {
                printf("Enter new Nom_utilisateur: ");
                fgets(book.Nom_utilisateur, sizeof(book.Nom_utilisateur), stdin);
            } else if (strcmp(choice, "Prix") == 0) {
                printf("Enter new Prix: ");
                scanf("%f", &book.Prix);
                clear_input();
            } else if (strcmp(choice, "Categorie") == 0) {
                printf("Enter new Categorie: ");
                fgets(book.Categorie, sizeof(book.Categorie), stdin);
            } else if (strcmp(choice, "Disponibilite") == 0) {
                printf("Enter new Disponibilite (0 or 1): ");
                scanf("%d", &book.Disponibilite);
                clear_input();
            }
        }

        fprintf(temp, "ID: %s\n", book.ID);
        fprintf(temp, "Titre: %s\n", book.Titre);
        fprintf(temp, "Auteur: %s\n", book.Auteur);
        fprintf(temp, "Description: %s\n", book.Description);
        fprintf(temp, "Nom_utilisateur: %s\n", book.Nom_utilisateur);
        fprintf(temp, "Prix: %.2f\n", book.Prix);
        fprintf(temp, "Categorie: %s\n", book.Categorie);
        fprintf(temp, "Disponibilite: %d\n", book.Disponibilite);
    }

    fclose(f);
    fclose(temp);

    remove("Books.txt");
    rename("temp.txt", "Books.txt");
}

void delete_book() //allow admins to remove/delete a book choosen
{
    FILE *f = fopen("Books.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    char ID_M[30];
    printf("Enter the ID of the book you wanna delete: ");
    scanf("%s", ID_M);
    clear_input();
    books book;

    while (fscanf(f, "ID: %s\n", book.ID) == 1){

        fscanf(f, "Titre: %[^\n]\n", book.Titre);
        fscanf(f, "Auteur: %[^\n]\n", book.Auteur);
        fscanf(f, "Description: %[^\n]\n", book.Description);
        fscanf(f, "Nom_utilisateur: %[^\n]\n", book.Nom_utilisateur);
        fscanf(f, "Prix: %f\n", &book.Prix);
        fscanf(f, "Categorie: %[^\n]\n", book.Categorie);
        fscanf(f, "Disponibilite: %d\n", &book.Disponibilite);

        if (strcmp(book.ID, ID_M) != 0) {

            fprintf(temp, "ID: %s\n", book.ID);
            fprintf(temp, "Titre: %s\n", book.Titre);
            fprintf(temp, "Auteur: %s\n", book.Auteur);
            fprintf(temp, "Description: %s\n", book.Description);
            fprintf(temp, "Nom_utilisateur: %s\n", book.Nom_utilisateur);
            fprintf(temp, "Prix: %.2f\n", book.Prix);
            fprintf(temp, "Categorie: %s\n", book.Categorie);
            fprintf(temp, "Disponibilite: %d\n", book.Disponibilite);
        }
    }

    fclose(f);
    fclose(temp);

    remove("Books.txt");
    rename("temp.txt", "Books.txt");
}

void rechercher() //allow to search for a certain book, accessible by admins and normal users
{
  char Auteur_n[30];
  char Titre_n[30];

  printf("Enter the Auteur and Titre: ");
  scanf("%s %s", Auteur_n, Titre_n);
  getchar();

  FILE *f = fopen("Books.txt", "r");

  books book;
  while (fscanf(f, "ID: %s\n", book.ID) == 1) {
    fscanf(f, "Titre: %[^\n]\n", book.Titre);
    fscanf(f, "Auteur: %[^\n]\n", book.Auteur);
    fscanf(f, "Description: %[^\n]\n", book.Description);
    fscanf(f, "Nom_utilisateur: %[^\n]\n", book.Nom_utilisateur);
    fscanf(f, "Prix: %f\n", &book.Prix);
    fscanf(f, "Categorie: %[^\n]\n", book.Categorie);
    fscanf(f, "Disponibilite: %d\n", &book.Disponibilite);

    if(strcmp(book.Titre, Titre_n) == 0 && strcmp(book.Auteur, Auteur_n) == 0){
            printf("ID: %s\n", book.ID);
            printf("Titre: %s\n", book.Titre);
            printf("Auteur: %s\n", book.Auteur);
            printf("Description: %s\n", book.Description);
            printf("Nom_utilisateur: %s\n", book.Nom_utilisateur);
            printf("Prix: %.2f\n", book.Prix);
            printf("Categorie: %s\n", book.Categorie);
            printf("Disponibilite: %d\n", book.Disponibilite);
    }

  }
  fclose(f);
}

void by_categorie() //sorts the books by categorie, can only be accessed by the Trie function
{
    char choice[30];
    books book;

    printf("Enter the categorie: ");
    scanf("%s", choice);
    clear_input();

    FILE *f = fopen("Books.txt", "r");

    while (fscanf(f, "ID: %s\n", book.ID) == 1) {
        fscanf(f, "Titre: %[^\n]\n", book.Titre);
        fscanf(f, "Auteur: %[^\n]\n", book.Auteur);
        fscanf(f, "Description: %[^\n]\n", book.Description);
        fscanf(f, "Nom_utilisateur: %[^\n]\n", book.Nom_utilisateur);
        fscanf(f, "Prix: %f\n", &book.Prix);
        fscanf(f, "Categorie: %[^\n]\n", book.Categorie);
        fscanf(f, "Disponibilite: %d\n", &book.Disponibilite);

        if(strcmp(book.Categorie, choice) == 0){
                printf("Titre: %s\n", book.Titre);
                printf("Auteur: %s\n", book.Auteur);
                printf("Description: %s\n", book.Description);
                printf("Nom_utilisateur: %s\n", book.Nom_utilisateur);
                printf("Prix: %.2f\n", book.Prix);
                printf("Categorie: %s\n", book.Categorie);
                printf("Disponibilite: %d\n", book.Disponibilite);
        }
    }
}

//work in progress...
/*void by_alpha() //sorts the books names alpha. , can only be accessed by the Trie function
{
    books book[MAX];
    int i = 0;

    FILE *f = fopen("Books.txt", "r");

    while (fscanf(f, "ID: %s\n", book[i].ID) == 1) {
        fscanf(f, "Titre: %[^\n]\n", book[i].Titre);
        fscanf(f, "Auteur: %[^\n]\n", book[i].Auteur);
        fscanf(f, "Description: %[^\n]\n", book[i].Description);
        fscanf(f, "Nom_utilisateur: %[^\n]\n", book[i].Nom_utilisateur);
        fscanf(f, "Prix: %f\n", &book[i].Prix);
        fscanf(f, "Categorie: %[^\n]\n", book[i].Categorie);
        fscanf(f, "Disponibilite: %d\n", &book[i].Disponibilite);

        i++;
    }
}*/

void Trie() //give the users and admins the choice to sort by either categorie or alphabetically
{
    char order[30];

    printf("Wanna sort by Categorie: ");
    scanf("%s", order);

    if(strcmp(order, "categorie") == 0){
        by_categorie(); //call the by_categorie function if the user/admin choose to sort by categorie

    }/*else if(strcmp(order, "alpha") == 0){
        by_alpha(); //work in progress...
    }*/
}
