struct Worker {
	string secondName, name, phoneNumber, _login, _password;
	int id, _accessLevel;
};

int CreateDefaultWorkers() {
	ofstream fout;
	fout.open("UsersData.dat");
	if (!fout.is_open()) {
		printf("Default Workers initialization failed.\n");
		return EXIT_FAILURE;
	}
	fout << "0 Ivanov Ivan 81231231212 ivivan vanek 0\n1 Vladov Vlad 89567562354 vlvlad vladosik 1\n2 Lana Lana 81251251212 admin admin 2\n";
	fout.close();
	printf("Default Workers settings upload success.\n");
	return EXIT_SUCCESS;
}

vector <Worker> ShowWorkersDataBase(vector <Worker>& Workers) {
	printf("������ ����������:\nId    SecondName     Name    Numberphone\n");
	for (int i = 0; i < (int)Workers.size(); i++) {
		printf("%d\t%s\t%s\t%s\n", Workers[i].id, Workers[i].secondName.c_str(), Workers[i].name.c_str(), Workers[i].phoneNumber.c_str());
	}
	printf("---------------------------------------\n");
	return Workers;
}

vector <Worker> AddWorker(vector <Worker>& Workers) {
	ofstream fout;
	Worker temp;
	int Int;
	string str;
	printf("������� ������ � ��������� �������: �������, ���, ����� ��������, �����, ������, ������� �������\n");

	temp.id = Workers.size();
	cin >> temp.secondName;
	cin >> temp.name;
	cin >> temp.phoneNumber;
	cin >> temp._login;
	cin >> temp._password;
	cin >> temp._accessLevel;
	Workers.push_back(temp);
	fout.open("UsersData.dat", ofstream::app);
	Int = temp.id; fout << Int << " ";
	str = temp.secondName; fout << str << " ";
	str = temp.secondName; fout << str << " ";
	str = temp.phoneNumber; fout << str << " ";
	str = temp._login; fout << str << " ";
	Int = temp._accessLevel; fout << Int << "\n";
	printf("�� ������� �������� ��������� %s %s\n", temp.secondName.c_str(), temp.name.c_str());

	return Workers;
}

vector <Worker> RemoveWorker(vector <Worker>& Workers) {
	int searchId = 0;
	int counter = 0;

	ShowWorkersDataBase(Workers);

	printf("������� Id ��������� �������� ������ ������� �� �������\n");
	scanf("%d", &searchId);

	for (int i = 0; i < (int)Workers.size(); i++) {
		if (searchId == Workers[i].id) {
			int confirm = 0;
			counter += 1;
			printf("�� ������������� ������ ������� ��������� %d �� �������? 1 - ��. 0 - ���\n", Workers[i].id);
			scanf("%d", &confirm);
			if (confirm == 1) {
				Workers.erase(Workers.begin() + i);
				printf("�� ������� ������� �������. ������ ���� ������ �������� ���:\n");
				ShowWorkersDataBase(Workers);
			}
			else {
				printf("�� ��������� �������� ��������\n");
			}
			break;
		}

	}
	if (counter == 0) printf("�������� � ��������� Id �� ������");

	return Workers;
}

vector <Worker> GetWorkerInfo(vector <Worker>& Workers) {
	int searchId = 0;
	int counter = 0;
	printf("������� Id �������� ���������\n");
	scanf("%d", &searchId);
	for (int i = 0; i < (int)Workers.size(); i++) {
		if (searchId == Workers[i].id) {
			printf("������� ���� ��������:\nId - %d, ������� - %s, ��� - %s, ����� �������� - %s, ������� ������� - %d\n", Workers[i].id, Workers[i].secondName.c_str(), Workers[i].name.c_str(), Workers[i].phoneNumber.c_str(), Workers[i]._accessLevel);
			counter += 1;
			break;
		}
	}
	if (counter == 0) printf("�������� � ��������� Id �� ������. �� ������ ���� �� ������������ � ���� ������.");
	return(Workers);
}