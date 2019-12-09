#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <fstream>
#include "attack.h"

using namespace std;

struct monster {

	string name;
	string type;
	int level;
	int num_attacks;
	float avg_effectiveness;
	attack *attacks;

};

monster * create_monsters(int);
void get_monster_data(monster *, int, ifstream &);

void delete_monster_info(monster *, int);

void console_print_monster_data(monster *, int, int = 1);
void console_print_monsters(monster *, int, int = 1);
void file_print_monster_data(monster *, int, ofstream &, int = 1);
void file_print_monsters(monster *, int, ofstream &, int = 1);

#endif