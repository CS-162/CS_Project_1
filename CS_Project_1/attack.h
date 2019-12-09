#ifndef ATTACK_H
#define ATTACK_H

#include <string>
#include <fstream>

using namespace std;

struct attack {

	string name;
	float effectiveness;
	string element;

};

attack * create_attacks(int);
void get_attack_data(attack *, int, ifstream &);

void delete_attack_info(attack *);

void console_print_attack_data(attack *, int, int = 1);
void file_print_attack_data(attack *, int, ofstream &, int = 1);

#endif