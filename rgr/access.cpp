int AccessLevel0Tools(vector <Dish>& Dishes, vector <Worker>& Workers, vector<Table>& Tables) {
	int function = -1;
	while (function != 0) {
		printf("������ �������:\n 1 - �������� ������ ����, 2 - ������������� ������ ����. 3 - �������� ������ ����, 4 - �������� ������ ����� �� code, 0 - ����� �� �������\n");
		scanf("%d", &function);
		switch (function) {
		case 1: ShowDishesDatabase(Dishes); break;
		case 2: SortDishesDataBaseByCalory(Dishes); break;
		case 3: ChangeDishesDatabase(Dishes); break;
		case 4: ShowSerialDish(Dishes); break;
		case 0: break;
		}
	}
	printf("�� ������� ����� �� �������\n");
	return EXIT_SUCCESS;
}

int AccessLevel1Tools(vector <Dish>& Dishes, vector <Worker>& Workers, vector<Table>& Tables) {
	int function = -1;
	while (function != 0) {
		printf("������ �������:\n 1 - �������� ������ �������, 2 - ������������� ������ �������. 3 - �������� ������ �������, 4 - �������� ������ ������ �� Id, 5 - ������������� � �����������, 0 - ����� �� �������\n");
		scanf("%d", &function);
		switch (function) {
		case 1: ShowDishesDatabase(Dishes); break;
		case 2: SortDishesDataBaseByCalory(Dishes); break;
		case 3: ChangeDishesDatabase(Dishes); break;
		case 4: ShowSerialDish(Dishes); break;
		case 5: {
			int workChoose = 0;
			printf("������ ������� � �����������:\n1 - �������� ������ ����������, 2 - �������� ���������� � ��������� �� Id, 0 - �����\n");
			scanf("%d", &workChoose);
			switch (workChoose) {
			case 1: ShowWorkersDataBase(Workers); break;
			case 2: GetWorkerInfo(Workers); break;
			case 0: break;
			}
		}
		}
	}
	printf("�� ������� ����� �� �������\n");
	return EXIT_SUCCESS;
}

int AccessLevel2Tools(vector <Dish>& Dishes, vector <Worker>& Workers, vector<Table>& Tables) {
	int Function = -1;
	while (Function != 0) {
		printf("������ �������:\n 1 - �������� ������ �������, 2 - ������������� ������ �������. 3 - �������� ������ �������, 4 - �������� ������ ������ �� Id, 5 - ������������� � �����������, 0 - ����� �� �������\n");
		scanf("%d", &Function);
		switch (Function) {
		case 0: break;
		case 1: ShowDishesDatabase(Dishes); break;
		case 2: SortDishesDataBaseByCalory(Dishes); break;
		case 3: ChangeDishesDatabase(Dishes); break;
		case 4: ShowSerialDish(Dishes); break;
		case 5: {
			int WorkChoose = 0;
			printf("������ ������� � �����������:\n1 - �������� ������ ����������, 2 - �������� ���������� � ��������� �� Id, 3 - �������� ���������, 4 - ������� ���������, 0 - �����\n");
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
	printf("�� ������� ����� �� �������\n");
	return EXIT_SUCCESS;
}