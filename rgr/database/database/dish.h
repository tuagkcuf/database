#pragma once

#include <vector>

using namespace std;

struct Dish;

int createDefaultDishes();

vector<int> ShowDishesDatabase(vector<Dish>& Dishes);

vector<Dish> ChangeDishesDatabase(vector<Dish>& Dishes);

vector <Dish> ShowSerialDish(vector <Dish>& Dishes);

vector <Dish> SortDishesDataBaseByCalory(vector <Dish>& Dishes);