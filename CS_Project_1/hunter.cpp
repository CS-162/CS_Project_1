/**
**	Program: Hunter class
**	Author: Austin Chayka
**	Date: 10.13.2019
**	Description: Class for a monster
**/
#include "hunter.h"

/**
**	Function: create hunters
**	Description: allocates memory form an array of hunter structs
**	Parameters: the size of the array
**/
hunter * create_hunters(int amt) {

	return new hunter[amt];

}

/**
**	Function: get hunter data
**	Description: gets hunter data from a file and fills an array of structs
**		with that data
**	Parameters: array of hunter structs, size of array, input file
**/
void get_hunter_data(hunter *hunters, int amt, ifstream &f) {

	string name, password, experience;
	int id;
	float encounters;

	for(int i = 0; i < amt; i++) {

		f >> name >> id >> password >> experience >> encounters;
		hunters[i].name = name;
		hunters[i].id = id;
		hunters[i].password = password;
		hunters[i].experience = experience;
		hunters[i].encounters = encounters;
		
	}

}

/**
**	Function: delete hunter info
**	Description: removes an array of structs from memory
**	Parameters: array of hunter structs
**/
void delete_hunter_info(hunter *hunters) {

	delete[] hunters;
	cout << "Hunter data cleared" << endl;

}

/**
**	Function: id found
**	Description: checks an array of hunter structs to see if a hunter
**		with a specified id exists
**	Parameters: array of hunter structs, size of array, id to search for
**/
bool id_found(hunter *hunters, int amt, int id) {

	for(int i = 0; i < amt; i++) {

		if(hunters[i].id == id) return true;

	}

	return false;

}

/**
**	Function: (console) print hunter data
**	Description: prints the data in an array of hunter structs to 
**		the command console
**	Parameters: array of hunter struct, size of array
**/
void console_print_hunter_info(hunter *hunters, int amt) {

	for(int i = 0; i < amt; i++) {

		cout << hunters[i].name << " " << hunters[i].id << " " << hunters[i].password
			<< " " << hunters[i].experience << " " << hunters[i].encounters << endl;

	}

}
