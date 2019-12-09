#ifndef HUNTER_H
#define HUNTER_H

#include <iostream>
#include "monster.h"

using namespace std;

struct hunter {

	string name;
	int id;
	string password;
	string experience;
	float encounters;

};

hunter * create_hunters(int);
void get_hunter_data(hunter *, int, ifstream &);

void delete_hunter_info(hunter *);

bool id_found(hunter *, int, int);

void console_print_hunter_info(hunter *, int);

#endif