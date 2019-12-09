/**
**	Program: Monster class
**	Author: Austin Chayka
**	Date: 10.13.2019
**	Description: Class for a monster
**/
#include "monster.h"
#include <iostream>

/**
**	Function: create monsters
**	Description: allocates memory form an array of monster structs
**	Parameters: the size of the array
**/
monster * create_monsters(int amt) {
	
	return new monster[amt];

}


/**
**	Function: get monster data
**	Description: gets monster data from a file and fills an array of structs
**		with that data
**	Parameters: array of attack structs, size of array, input file
**/
void get_monster_data(monster *monsters, int amt, ifstream &f) {

	string name, type;
	int level, num_attacks;
	float total_effectiveness;

	for(int i = 0; i < amt; i++) {

		f >> name >> type >> level >> num_attacks;
		monsters[i].name = name;
		monsters[i].type = type;
		monsters[i].level = level;
		monsters[i].num_attacks = num_attacks;
		monsters[i].attacks = create_attacks(num_attacks);
		get_attack_data(monsters[i].attacks, num_attacks, f);

		total_effectiveness = 0;
		for(int j = 0; j < num_attacks; j++) total_effectiveness += monsters[i].attacks[j].effectiveness;

		monsters[i].avg_effectiveness = total_effectiveness / num_attacks;

	}

}

/**
**	Function: delete monster info
**	Description: removes an array of structs from memory
**	Parameters: array of attack structs
**/
void delete_monster_info(monster *monsters, int amt) {

	for(int i = 0; i < amt; i++) {
		cout << "M" << i << " ";
		delete_attack_info(monsters[i].attacks);
	}
	delete[] monsters;
	cout << "Monster data cleared" << endl;

}

/**
**	Function: (console) print monster data
**	Description: prints the data in an array of monster structs
**		and monster attack structs to the command console based 
**		on user access
**	Parameters: array of monster struct, size of array, user access level
**/
void console_print_monster_data(monster *monsters, int amt, int access) {

	for(int i = 0; i < amt; i++) {

		if(access == 0 && monsters[i].avg_effectiveness > 50 && monsters[i].level >= 20) continue;

		std::cout << monsters[i].name << " " << monsters[i].type << " "
			<< monsters[i].level << " " << monsters[i].avg_effectiveness
			<< " " << monsters[i].num_attacks << std::endl;

		console_print_attack_data(monsters[i].attacks, monsters[i].num_attacks, access);

	}

}

/**
**	Function: (console) print monster data
**	Description: prints the data in an array of monster structs to 
**		the command console based on user access
**	Parameters: array of monster struct, size of array user access level
**/
void console_print_monsters(monster *monsters, int amt, int access) {

	for(int i = 0; i < amt; i++) {

		if(access == 0 && monsters[i].avg_effectiveness > 50 && monsters[i].level >= 20) continue;

		std::cout << monsters[i].name << " " << monsters[i].type << " "
			<< monsters[i].level << " " << monsters[i].avg_effectiveness
			<< " " << monsters[i].num_attacks << std::endl;

	}

}

/**
**	Function: (file) print monster data
**	Description: prints the data in an array of monster structs
**		and monster attack structs to an output file based 
**		on user access
**	Parameters: array of monster struct, size of array, output file,
**		user access level
**/
void file_print_monster_data(monster *monsters, int amt, ofstream &f, int access) {

	for(int i = 0; i < amt; i++) {

		if(access == 0 && monsters[i].avg_effectiveness > 50 && monsters[i].level >= 20) continue;

		f << monsters[i].name << " " << monsters[i].type << " "
			<< monsters[i].level << " " << monsters[i].avg_effectiveness
			<< " " << monsters[i].num_attacks << "\n";

		file_print_attack_data(monsters[i].attacks, monsters[i].num_attacks, f, access);

	}

}

/**
**	Function: (file) print monster data
**	Description: prints the data in an array of monster structs to 
**		an output file based on user access
**	Parameters: array of monster struct, output file, 
**		size of array user access level
**/
void file_print_monsters(monster *monsters, int amt, ofstream &f, int access) {

	for(int i = 0; i < amt; i++) {

		if(access == 0 && monsters[i].avg_effectiveness > 50 && monsters[i].level >= 20) continue;

		f << monsters[i].name << " " << monsters[i].type << " "
			<< monsters[i].level << " " << monsters[i].avg_effectiveness
			<< " " << monsters[i].num_attacks << "\n";

	}

}
