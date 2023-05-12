
// Вариант 11

// Разработать информационно справочную систему для работы с базой данных. Входные данные:
// База данных состоит из записей. (код блюда, наименование, ингредиенты, время приготовления, номер диетического стола, калории, в отдельном файле справочная информация о диетических столах)
// Обеспечить:
// - введение данных в оперативную память в двунаправленный список:
// а) из текстового файла;
// б) с клавиатуры;
// - просмотр содержимого базы данных;
// - редактирование базы данных: 
// а) удаление записи; 
// б) добавление записи;
// - выведение данных:
// а) в текстовый файл;
// б) на экран;
// - поиск данных по коду блюда; 
// - сортировка данных по калорийности;
// - получение справочной информации о диетическом столе;

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include "dish.h"
#include "models.h"
#include "initialization.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	struct Dish* Dishes;
	struct Table* Tables;
	struct Worker* Workers;
	WInit(Workers);
	TInit(Tables);
	DInit(Dishes);
	int accessLevel = -1;
	while (accessLevel < 0) {
		accessLevel = Auth(Workers);
	}
	switch (accessLevel) {
		case 0: AccessLevel0Tools(Dishes, Workers, Tables); break;
		case 1: AccessLevel1Tools(Dishes, Workers, Tables); break;
		case 2: AccessLevel2Tools(Dishes, Workers, Tables); break;
	}
	return 0;
}