struct Dish {
	int code;
	string name;
	string ingredients;
	int time;
	int numberOfTable;
	int calories;
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
	printf("������ ����:\n���    ��������     ����e������    ����� �������������     ����� �����     �������\n");
	for (int i = 0; i < (int)Dishes.size(); i++) {
		printf("%d\t%s\t%s\t%d\t%d\t%d\t\n", Dishes[i].code, Dishes[i].name.c_str(), Dishes[i].ingredients.c_str(), Dishes[i].time, Dishes[i].numberOfTable, Dishes[i].calories);
	}
	printf("---------------------------------------\n");
	return(Dishes);
}

vector<Dish> ChangeDishesDatabase(vector<Dish>& Dishes) {
	int func = 0;;
	printf("������� ����� �������� ������� 1 - ������� ������, 2 - �������� ������\n");
	scanf("%d", &func);
	switch (func) {
	case 1: {
		int searchId = 0;
		ShowDishesDatabase(Dishes);
		printf("�������� code ������ ������� ������ �������\n");
		scanf("%d", &searchId);
		int counter = 0;
		for (int i = 0; i < (int)Dishes.size(); i++) {
			if (searchId == Dishes[i].code) {
				counter += 1;
				printf("�� ������������� ������ ������� ������ �����? 1 - ��. 0 - ���\n");
				int confirm = 0;
				scanf("%d", &confirm);
				if (confirm == 1) {
					Dishes.erase(Dishes.begin() + i);
					printf("�� ������� ������� �������.\n� ������ ������ ���� ������ ������� �������� ���:\n");
					ShowDishesDatabase(Dishes);
				}
				else {
					printf("�� ��������� �������� ��������\n");
				}
				break;
			}
		}
		if (counter == 0) printf("����� � ����� Id �� ��� ������\n");
		break;
	}
	case 2: {
		Dish temp;
		int lastId;
		lastId = Dishes[Dishes.size() - 1].code;
		printf("������� ������ ����� � ������� ��� ����������� �����_������������� �����_����� �������\n");
		cin >> temp.name;
		cin >> temp.ingredients;
		cin >> temp.time;
		cin >> temp.numberOfTable;
		cin >> temp.calories;
		temp.code = lastId + 1;
		Dishes.push_back(temp);
		printf("�� ������� �������� ����� � ���� ������. Id ������������ ���� ������ - %d\n", Dishes[Dishes.size() - 1].code);
		printf("---------------------------------------\n");
		ShowDishesDatabase(Dishes);
		break;
	}
	default: "�� ����� �������� ��������, ������������� ��� � ������� ����."; return Dishes;
	}
	return Dishes;
}

vector <Dish> ShowSerialDish(vector <Dish>& Dishes) {
	int searchId = 0;
	printf("������� code �������� �����\n");
	scanf("%d", &searchId);
	for (int i = 0; i < (int)Dishes.size(); i++) {
		if (searchId == Dishes[i].code) {
			printf("������� ���� �����:\n��� �������� - %d, �������� - %s, ����e������ - %s, ����� ������������� - %d, ����� ����� - %d, ������� - %d\n",
				Dishes[i].code, Dishes[i].name.c_str(), Dishes[i].ingredients.c_str(), Dishes[i].time, Dishes[i].numberOfTable, Dishes[i].calories);
			return(Dishes);
		}
	}
	printf("������� ����  ����� �� ������");
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