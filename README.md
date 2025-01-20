# TP_Chaos_2024

The participants are:
	-Marouane Jakni
	-Ait Dra Nabil
	-El Merraji Sara
	-Hamzaoui Fatima
	-Hakim Mohamed Akram
	-El Airaj Houssam

This file contains a C project:

The subject is: "Gestion de bibliothèque"

The file consist of three files:

main.c:
Has the main function, works only to take the users choice, whether they are admins or normal users

bibliotheque.h:
The declaration of the used functions, it is the main header file.
also contain the structures used in this project.

bibliotheque.c:
Where all the functions are defined.
it has the main used functions and follower functions.

The main functions are:
user_choice; //it is used to take users choice, are they admin (require password "admin0000") or normal users, 
its follower functions are admin() and user()

number(); //takes the number of books users wanna add, works with filling struct and file creation. (admin)

filling_struct(); //takes the book's info and stores it in an array of structs. (admin)

file_creation(); //create a .csv file based on the info from the previous array of struct. (admin)

modify(); //allow only admins to modify certain info in the .csv file, where books info is. (admin)

delete_book(); //also only allows the admins to delete a certain book from the .csv file. (admin)

rechercher(); //allows all users to search for a certain book. (both)

Trie(); //sort the books based on category or price, 
it branches into multiple other functions. (both)

--written by Marouane

