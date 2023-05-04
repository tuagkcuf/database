#include "dish.h"

struct Dish {
	int code;
	string name;
	string ingredients;
	int time;
	int numberOfTable;
	int calories;
	Dish *next, *prev;
};

int createDefaultDishes() {
	ofstream fout;
	fout.open("DishesInfo.dat");
	if (!fout.is_open()) {
		printf("Default dishes initialization is failed.\n");
		return EXIT_FAILURE;
	}
	fout << "0 name ingredients 0 0 0\n1 name ingredients 0 0 0\n2 name ingredients 0 0 0\n";
	fout.close();
	printf("Default dishes settings upload is successful.\n");
	return EXIT_SUCCESS;
}

vector<Dish> ShowDishesDatabase(vector<Dish>& Dishes) {
	printf("Список блюд:\nКод    Название     Ингрeдиенты    Время приготовления     Номер стола     Калории\n");
	for (int i = 0; i < (int)Dishes.size(); i++) {
		printf("%d\t%s\t%s\t%d\t%d\t%d\t\n", Dishes[i].code, Dishes[i].name.c_str(), Dishes[i].ingredients.c_str(), Dishes[i].time, Dishes[i].numberOfTable, Dishes[i].calories);
	}
	printf("---------------------------------------\n");
	return(Dishes);
}

vector<Dish> ChangeDishesDatabase(vector<Dish>& Dishes) {
	int func = 0;;
	printf("Введите номер желаемой функции 1 - удалить запись, 2 - добавить запись\n");
	scanf("%d", &func);
	switch (func) {
	case 1: {
		int searchId = 0;
		ShowDishesDatabase(Dishes);
		printf("Выберите code заказа который хотите удалить\n");
		scanf("%d", &searchId);
		int counter = 0;
		for (int i = 0; i < (int)Dishes.size(); i++) {
			if (searchId == Dishes[i].code) {
				counter += 1;
				printf("Вы действительно хотите удалить данное блюдо? 1 - Да. 0 - Нет\n");
				int confirm = 0;
				scanf("%d", &confirm);
				if (confirm == 1) {
					Dishes.erase(Dishes.begin() + i);
					printf("Вы успешно удалили элемент.\nВ данный момент база данных заказов выглядит так:\n");
					ShowDishesDatabase(Dishes);
				}
				else {
					printf("Вы отклонили удаление элемента\n");
				}
				break;
			}
		}
		if (counter == 0) printf("Заказ с таким Id не был найден\n");
		break;
	}
	case 2: {
		Dish temp;
		int lastId;
		lastId = Dishes[Dishes.size() - 1].code;
		printf("Введите данные блюда в порядке Имя Ингридиенты Время_приготовления Номер_стола Калории\n");
		cin >> temp.name;
		cin >> temp.ingredients;
		cin >> temp.time;
		cin >> temp.numberOfTable;
		cin >> temp.calories;
		temp.code = lastId + 1;
		Dishes.push_back(temp);
		printf("Вы успешно добавили заказ в базу данных. Id добавленного вами заказа - %d\n", Dishes[Dishes.size() - 1].code);
		printf("---------------------------------------\n");
		ShowDishesDatabase(Dishes);
		break;
	}
	default: "Вы ввели неверное значение, перенаправляю вас в главное меню."; return Dishes;
	}
	return Dishes;
}

vector <Dish> ShowSerialDish(vector <Dish>& Dishes) {
	int searchId = 0;
	printf("Введите code искомого блюда\n");
	scanf("%d", &searchId);
	for (int i = 0; i < (int)Dishes.size(); i++) {
		if (searchId == Dishes[i].code) {
			printf("Искомый вами заказ:\nКод продукта - %d, название - %s, ингрeдиенты - %s, время приготовления - %d, номер стола - %d, калории - %d\n",
				Dishes[i].code, Dishes[i].name.c_str(), Dishes[i].ingredients.c_str(), Dishes[i].time, Dishes[i].numberOfTable, Dishes[i].calories);
			return(Dishes);
		}
	}
	printf("Искомый вами  заказ не найден");
	return Dishes;
}

vector <Dish> SortDishesDataBaseByCalory(vector <Dish>& Dishes) {
	int listLength = Dishes.size();
	while (listLength--) {
		for (int i = 0; i < listLength; i++) {
			if (Dishes[i].calories > Dishes[i + 1].calories) {
				swap(Dishes[i], Dishes[i + 1]);
			}
		}
	}
	ShowDishesDatabase(Dishes);
	return Dishes;
}