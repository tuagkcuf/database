#include "initialization.h"
#include "models.h"
#include "worker.h"
#include "table.h"
#include "dish.h"

void WInit(struct Worker** Workers) {
	struct Worker* current = *workersHead;
	struct Worker* temp = *current;
	string str;
	ifstream fin;
	fin.open("WorkersInfo.dat");
	if (fin.is_open()) {
		while (!fin.eof()) {
			struct Worker* neww = (struct Worker*)malloc(sizeof(struct Worker));
			str = "";
			fin >> str; if (str != "") neww->id = stoi(str.c_str());
			fin >> str; if (str != "") neww->secondName = str.c_str();
			fin >> str; if (str != "") neww->name = str.c_str();
			fin >> str; if (str != "") neww->phoneNumber = str.c_str();
			fin >> str; if (str != "") neww->_login = str.c_str();
			fin >> str; if (str != "") neww->_password = str.c_str();
			fin >> str; if (str != "") neww->_accessLevel = stoi(str.c_str());
			if (str != "") {
				temp->next = neww;
				temp->next->prev = temp;
				temp = temp->next;
				temp->next = NULL;
			}
		}
		fin.close();
		printf("Worker initialization complete.\n");
		*workersHead->next = current;
	}
	else {
		fin.close();
		printf("Worker initialization failed. Loading default settings.\n");
		createDefaultWorkers();
		DInit(workersHead);
	}
}

void TInit(struct Table** Tables) {
	struct Table* current = *tablesHead;
	struct Table* temp = *current;
	string str;
	ifstream fin;
	fin.open("TablesInfo.dat");
	if (fin.is_open()) {
		while (!fin.eof()) {
			struct Table* neww = (struct Table*)malloc(sizeof(struct Table));
			str = "";
			fin >> str; if (str != "") neww->id = stoi(str.c_str());
			fin >> str; if (str != "") neww->secondName = str.c_str();
			fin >> str; if (str != "") neww->name = str.c_str();
			fin >> str; if (str != "") neww->phoneNumber = str.c_str();
			fin >> str; if (str != "") neww->_login = str.c_str();
			fin >> str; if (str != "") neww->_password = str.c_str();
			fin >> str; if (str != "") neww->_accessLevel = stoi(str.c_str());
			if (str != "") {
				temp->next = neww;
				temp->next->prev = temp;
				temp = temp->next;
				temp->next = NULL;
			}
		}
		fin.close();
		printf("Tables initialization complete.\n");
		*tablesHead->next = current;
	}
	else {
		fin.close();
		printf("Tables initialization failed. Loading default settings.\n");
		createDefaultTables();
		DInit(tablesHead);
	}
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