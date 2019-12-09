/**
**	Program: Attack class
**	Author: Austin Chayka
**	Date: 10.13.2019
**	Description: Class for a monster attack
**/
#include "attack.h"
#include <iostream>

/**
**	Function: create attacks
**	Description: allocates memory form an array of attack structs
**	Parameters: the size of the array
**/
attack * create_attacks(int amt) {

	return new attack[amt];

}

/**
**	Function: get attack data
**	Description: gets attack data from a file and fills an array of structs
**		with that data
**	Parameters: array of attack structs, size of array, input file
**/
void get_attack_data(attack *a, int amt, ifstream &f) {

	string name, element;
	float effectiveness;

	for(int i = 0; i < amt; i++) {

		f >> name >> effectiveness >> element;
		a[i].name = name;
		a[i].effectiveness = effectiveness;
		a[i].element = element;

	}

}

/**
**	Function: delete attack info
**	Description: removes an array of structs from memory
**	Parameters: array of attack structs
**/
void delete_attack_info(attack *attacks) {

	delete[] attacks;
	cout << "Attack data cleared" << endl;

}

/**
**	Function: (console) print attack data
**	Description: prints the data in an array of attack structs to 
**		the command console based on user access
**	Parameters: array of attack struct, size of array, user access level
**/
void console_print_attack_data(attack *attacks, int amt, int access) {

	for(int i = 0; i < amt; i++) {

		if(access == 0 && attacks[i].effectiveness > 70) continue;

		std::cout << attacks[i].name << " " << attacks[i].effectiveness << " " << attacks[i].element << std::endl;
		
	}

}

/**
**	Function: (file) print attack data
**	Description: prints the data in an array of attack structs to 
**		a output file based on user access
**	Parameters: array of attack struct, size of array, output file,
**		user access level
**/
void file_print_attack_data(attack *attacks, int amt, ofstream &f, int access) {

	for(int i = 0; i < amt; i++) {

		if(access == 0 && attacks[i].effectiveness > 70) continue;

		f << attacks[i].name << " " << attacks[i].effectiveness << " " << attacks[i].element << "\n";

	}

}
