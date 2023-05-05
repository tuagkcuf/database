#include "initialization.h"
#include "models.h"
#include <vector>

vector <Worker> WInit(vector <Worker>& Workers) {
	string str;
	ifstream fin;
	Worker temp;
	fin.open("UsersData.dat");
	if (fin.is_open()) {
		while (!fin.eof()) {
			str = "";
			fin >> str; if (str != "") temp.id = stoi(str.c_str());
			fin >> str; if (str != "") temp.secondName = str.c_str();
			fin >> str; if (str != "") temp.name = str.c_str();
			fin >> str; if (str != "") temp.phoneNumber = str.c_str();
			fin >> str; if (str != "") temp._login = str.c_str();
			fin >> str; if (str != "") temp._password = str.c_str();
			fin >> str; if (str != "") temp._accessLevel = stoi(str.c_str());
			if (str != "") Workers.push_back(temp);
		}
		fin.close();
		printf("Workers initialization complete.\n");
	}
	else {
		fin.close();
		printf("Workers initialization failed. Loading Default settings.\n");
		CreateDefaultWorkers();
		WInit(Workers);
	}
	return Workers;
}

vector<Table> TInit(vector <Table>& Tables) {
	string str;
	ifstream fin;
	Table temp;
	fin.open("TablesInfo.dat");
	if (fin.is_open()) {
		while (!fin.eof()) {
			str = "";
			fin >> str; if (str != "") temp.code = stoi(str.c_str());
			fin >> str; if (str != "") temp.name = str.c_str();
			if (str != "") Tables.push_back(temp);
		}
		fin.close();
		printf("Tables Initialization Complete.\n");
	}
	else {
		fin.close();
		printf("Tables initialization failed. Loading Default settings.\n");
		CreateDefaultTables();
		TInit(Tables);
	}
	return Tables;
}

void DInit(struct Dish** DishesHead) {
	struct Dish *current = *DishesHead;
    struct Dish *temp = *current;
	string str;
	ifstream fin;
	fin.open("DishesInfo.dat");
	if (fin.is_open()) {
		while (!fin.eof()) {
            struct Dish* newDish = (struct Dish*)malloc(sizeof(struct Dish));
			str = "";
			fin >> str; if (str != "") newDish->code = stoi(str);
			fin >> str; if (str != "") newDish->name = str.c_str();
			fin >> str; if (str != "") newDish->ingredients = str.c_str();
			fin >> str; if (str != "") newDish->time = stoi(str);
			fin >> str; if (str != "") newDish->numberOfTable = stoi(str);
			fin >> str; if (str != "") newDish->calories = stoi(str);
			if (str != "") {
				temp->next = newDish;
                temp->next->prev = temp;
                temp = temp->next;
                temp->next = NULL;
			}
		}
		fin.close();
		printf("Dishes initialization complete.\n");
        *DishesHead->next = current;
	} else {
		fin.close();
		printf("Dishes initialization failed. Loading default settings.\n");
		createDefaultDishes();
		DInit(DishesHead);
	}
}