/*
**	Program: Monster Encyclopedia
**	Author: Austin Chayka
**	Date: 10.13.2019
**	Description: A program for sorting and printing out information on 
**		monsters based on the user's experiece level
**	Input: The hunter info file and the monster info file passes as
**		command line arguments
**	Output: The monster's information followed by the information on
**		each of that monster's attacks printed to a file or the command
**		window
*/
#include <iostream>
#include <fstream>
#include "monster.h"
#include "hunter.h"

using namespace std;

/**
**  Function: swap monsters
** 	Description: swaps two monster structs
**	Parameters: monster 1, monster 2
**/
void swap_monsters(monster &m1, monster &m2) {

	monster temp = m1;
	m1 = m2;
	m2 = temp;

}

/**
**	Function: swap attacks
**	Description: swaps two attack structs
**	Parameters: attack 1, attack 2
*/
void swap_attacks(attack &a1, attack &a2) {

	attack temp = a1;
	a1 = a2;
	a2 = temp;

}

/**
**	Function: sort monsters by level
**	Description: sorts all the monsters in an array by level, ascending
**	Parameters: array of monsters, number of monsters in array
**/
void sort_monsters_by_level(monster *monsters, int amt) {

	int n = amt - 1;
	bool swap;

	do {
		swap = false;
		for(int i = 0; i < n; i++) {
			if(monsters[i].level > monsters[i + 1].level) {
				swap_monsters(monsters[i], monsters[i + 1]);
				swap = true;
			}
		}
		n--;
	} while(swap);

}

/**
**	Function: sort attacks by element
**	Description: sorts all the attacks in an array by element, alphabetically
**	Parameters: array of attacks, number of attacks in array
**/
void sort_attacks_by_element(attack *attacks, int amt) {

	int n = amt - 1;
	bool swap;

	do {
		swap = false;
		for(int i = 0; i < n; i++) {
			if(attacks[i].element > attacks[i + 1].element) {
				swap_attacks(attacks[i], attacks[i + 1]);
				swap = true;
			}
		}
		n--;
	} while(swap);

}

/**
**	Function: sort monsters by effectiveness
**	Description: sorts all the monsters in an array average
**		effectiveness, ascending
**	Parameters: array of monsters, number of monsters in array
**/
void sort_monsters_by_effectiveness(monster *monsters, int amt) {

	int n = amt - 1;
	bool swap;

	do {
		swap = false;
		for(int i = 0; i < n; i++) {
			if(monsters[i].avg_effectiveness > monsters[i + 1].avg_effectiveness) {
				swap_monsters(monsters[i], monsters[i + 1]);
				swap = true;
			}
		}
		n--;
	} while(swap);

}

/**
**	Function: is digit
**	Description: checks if a string is all numbers and returns
**		true or false
**	Parameters: string to test
**/
bool is_digit(const string &str) {

	for(int i = 0; str[i] != '\0'; i++) if(str[i] < '0' || str[i] > '9') return false;

	return true;

}

/**
**	Function: main
**	Description: driver function
**	Parameters: number of command arguments, command arguments
**/
int main(int argc, char *argv[]) {

	if(argc < 3) {

		cout << "Error: not enough arguments passed";
		return 1;

	}

	ifstream monster_file, hunter_file;

	hunter_file.open(argv[1]);
	monster_file.open(argv[2]);

	if(!hunter_file.is_open()) {

		cout << "Error: hunter file could not be opened";
		return 2;

	}
	if(!monster_file.is_open()) {

		cout << "Error: monster file could not be opened";
		return 3;

	}

	int num_monsters = 0, num_hunters = 0;
	hunter_file >> num_hunters;
	monster_file >> num_monsters;

	hunter *hunters = create_hunters(num_hunters);
	monster *monsters = create_monsters(num_monsters);

	get_hunter_data(hunters, num_hunters, hunter_file);
	get_monster_data(monsters, num_monsters, monster_file);

	string id_string;
	cout << "Enter ID: ";
	cin >> id_string;
	bool valid = false;
	while(!valid) {

		if(!is_digit(id_string)) {

			cout << "Error: input was not a number. Enter again:";
			cin >> id_string;

		} else if(!id_found(hunters, num_hunters, stoi(id_string))) {

			cout << "Error: ID not found. Enter again:";
			cin >> id_string;

		} else valid = true;

	}
	int id_digits = stoi(id_string);
	int target_hunter;
	for(int i = 0; i < num_hunters; i++) {

		if(hunters[i].id == id_digits) target_hunter = i;

	}
	
	int tries = 0;
	string password;
	do {

		cout << "(" << 3 - tries << " tries left) Enter password for " << hunters[target_hunter].name << ": ";
		cin >> password;
		tries++;

	} while(password != hunters[target_hunter].password && tries < 3);

	if(tries >= 3) {

		cout << "Incorrect password, exiting program";
		delete_hunter_info(hunters);
		delete_monster_info(monsters, num_monsters);
		return 0;

	}

	int hunter_access = (hunters[target_hunter].experience == "Apprentice" ? 0 : 1);

	string sort_option, print_option, file_name;
	cout << "\nEnter \"Quit\" to quit" << endl;
	while(true) {

		cout << "\nSort options:\n(1) Sort monsters by level"
			<< "\n(2) Sort attacks by element"
			<< "\n(3) Sort monsters by average attack effectiveness"
			<< endl;

		valid = false;
		cout << "Enter option number:";
		cin >> sort_option;
		if(file_name == "Quit" || file_name == "quit") break;
		while(!valid) {

			if(!is_digit(sort_option)) {

				cout << "Error: option was not a number. Enter again:";
				cin >> sort_option;

			} else if(stoi(sort_option) < 1 || stoi(sort_option) > 3) {
				
				cout << "Error: option not found. Enter again:";
				cin >> sort_option;
		
			} else valid = true;

		}

		cout << "\nPrint options:\n(1) Print to console\n(2) Print to file" << endl;

		valid = false;
		cout << "Enter option number:";
		cin >> print_option;
		if(file_name == "Quit" || file_name == "quit") break;
		while(!valid) {

			if(!is_digit(print_option)) {

				cout << "Error: option was not a number. Enter again:";
				cin >> print_option;

			} else if(stoi(print_option) < 1 || stoi(print_option) > 2) {

				cout << "Error: option not found. Enter again:";
				cin >> print_option;

			} else valid = true;

		}

		if(stoi(print_option) == 2) {
			cout << "Enter name of output file:";
			cin >> file_name;
			if(file_name == "Quit" || file_name == "quit") break;
			file_name += ".txt";
		}

		cout << "\n";
		switch(stoi(sort_option)) {

			case 1:
				sort_monsters_by_level(monsters, num_monsters);
				if(stoi(print_option) == 1)
					console_print_monster_data(monsters, num_monsters, hunter_access);
				else {
					ofstream f;
					f.open(file_name);
					file_print_monster_data(monsters, num_monsters, f, hunter_access);
					f.close();
					cout << "Data printed to: " << file_name << endl;
				}
				break;

			case 2: 
				{
					int num_attacks = 0;
					for(int i = 0; i < num_monsters; i++) num_attacks += monsters[i].num_attacks;
					attack* attacks = create_attacks(num_attacks);
					int k = 0;
					for(int i = 0; i < num_monsters; i++) for(int j = 0; j < monsters[i].num_attacks; j++)
						attacks[k++] = monsters[i].attacks[j];
					sort_attacks_by_element(attacks, num_attacks);
					if(stoi(print_option) == 1)
						console_print_attack_data(attacks, num_attacks, hunter_access);
					else {
						ofstream f;
						f.open(file_name);
						file_print_attack_data(attacks, num_attacks, f, hunter_access);
						f.close();
						cout << "Data printed to: " << file_name << endl;
					}
					cout << "\n";
					delete_attack_info(attacks);
				}
				break;

			case 3:
				sort_monsters_by_effectiveness(monsters, num_monsters);
				if(stoi(print_option) == 1)
					console_print_monster_data(monsters, num_monsters, hunter_access);
				else {
					ofstream f;
					f.open(file_name);
					file_print_monster_data(monsters, num_monsters, f, hunter_access);
					f.close();
					cout << "Data printed to: " << file_name << endl;
				}
				break;

		}

	}

	cout << "\n";
	delete_hunter_info(hunters);
	delete_monster_info(monsters, num_monsters);
	hunter_file.close();
	monster_file.close();
	cout << "Program closed.";
	return 0;

}