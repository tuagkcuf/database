#include "models.h"

struct Dish {
	int code;
	string name;
	string ingredients;
	int time;
	int numberOfTable;
	int calories;
	Dish *next, *prev;
};

struct Table {
	int code;
	string name;
	Table *next, *prev;
};

struct Worker {
	string secondName, name, phoneNumber, _login, _password;
	int id, _accessLevel;
	Worker *next, *prev;
};

