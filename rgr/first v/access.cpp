int AccessLevel0Tools(vector <Dish>& Dishes, vector <Worker>& Workers, vector<Table>& Tables) {
	int function = -1;
	while (function != 0) {
		printf("Список функций:\n 1 - Показать список блюд, 2 - Отсортировать список блюд. 3 - Изменить список блюд, 4 - Показать данные блюда по code, 0 - Выход из системы\n");
		scanf("%d", &function);
		switch (function) {
		case 1: ShowDishesDatabase(Dishes); break;
		case 2: SortDishesDataBaseByCalory(Dishes); break;
		case 3: ChangeDishesDatabase(Dishes); break;
		case 4: ShowSerialDish(Dishes); break;
		case 0: break;
		}
	}
	printf("Вы успешно вышли из системы\n");
	return EXIT_SUCCESS;
}

int AccessLevel1Tools(vector <Dish>& Dishes, vector <Worker>& Workers, vector<Table>& Tables) {
	int function = -1;
	while (function != 0) {
		printf("Список функций:\n 1 - Показать список заказов, 2 - Отсортировать список заказов. 3 - Изменить список заказов, 4 - Показать данные заказа по Id, 5 - Взамодействия с работниками, 0 - Выход из системы\n");
		scanf("%d", &function);
		switch (function) {
		case 1: ShowDishesDatabase(Dishes); break;
		case 2: SortDishesDataBaseByCalory(Dishes); break;
		case 3: ChangeDishesDatabase(Dishes); break;
		case 4: ShowSerialDish(Dishes); break;
		case 5: {
			int workChoose = 0;
			printf("Список функций с работниками:\n1 - Получить список работников, 2 - Получить информацию о работнике по Id, 0 - Выход\n");
			scanf("%d", &workChoose);
			switch (workChoose) {
			case 1: ShowWorkersDataBase(Workers); break;
			case 2: GetWorkerInfo(Workers); break;
			case 0: break;
			}
		}
		}
	}
	printf("Вы успешно вышли из системы\n");
	return EXIT_SUCCESS;
}

int AccessLevel2Tools(vector <Dish>& Dishes, vector <Worker>& Workers, vector<Table>& Tables) {
	int Function = -1;
	while (Function != 0) {
		printf("Список функций:\n 1 - Показать список заказов, 2 - Отсортировать список заказов. 3 - Изменить список заказов, 4 - Показать данные заказа по Id, 5 - Взамодействия с работниками, 0 - Выход из системы\n");
		scanf("%d", &Function);
		switch (Function) {
		case 0: break;
		case 1: ShowDishesDatabase(Dishes); break;
		case 2: SortDishesDataBaseByCalory(Dishes); break;
		case 3: ChangeDishesDatabase(Dishes); break;
		case 4: ShowSerialDish(Dishes); break;
		case 5: {
			int WorkChoose = 0;
			printf("Список функций с работниками:\n1 - Получить список работников, 2 - Получить информацию о работнике по Id, 3 - Добавить работника, 4 - Удалить работника, 0 - Выход\n");
			scanf("%d", &WorkChoose);
			switch (WorkChoose) {
			case 1: ShowWorkersDataBase(Workers); break;
			case 2: GetWorkerInfo(Workers); break;
			case 3: AddWorker(Workers); break;
			case 4: RemoveWorker(Workers); break;
			case 0: break;
			}
		}
		}
	}
	printf("Вы успешно вышли из системы\n");
	return EXIT_SUCCESS;
}