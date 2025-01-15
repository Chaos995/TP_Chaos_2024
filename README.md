# TP_Chaos_2024

This file contain a C project:

The subject is: "Gestion de bibliothèque"

The participants are:
	-Marouane Jakni
	-Ait Dra Nabil
	-El Merraji Sara
	-Hamzaoui Fatima
	-Hakim Mohamed Akram
	-El Airaj Houssam

File consist of three files:

main.c:
Has the main function, works only to take the users choice, whether they are admins or normal users

bibliotheque.h:
The declaration of the used functions, it is the main header file.
also contain the structs used in this project.

bibliotheque.c:
Where all the functions are defined.
it has the main used functions, and follower functions like "clear_input()" which is not a main function.

The main functions are:
user_choice; //it is used to take users choice, are they admin (require password "admin0000") or normal users, 
its follower functions are admin() and user()

number(); //takes the number of books users wanna add, works with filling struct and file creation. (admin)

filling_struct(); //takes the books info and stores them in an array of structs. (admin)

file_creation(); //create a .txt file based on the info from the previous array of struct. (admin)

mofify(); //allow only admins to modify a certain info in the .txt file, where books info are. (admin)

delete_book(); //also only allow the admins to delete a certain book from the .txt file. (admin)

rechercher(); //allow all users to search for a certain book. (both)

Trie(); //sort the books based on category or alphabetical order (alphabetical order is work in progress), 
it branch into two fuctions, by_order, and by_categorie. (both)

		#wrote by Marouane.

