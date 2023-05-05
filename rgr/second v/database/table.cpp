struct Table {
	int code;
	string name;
};

int CreateDefaultTables() {
	ofstream fout;
	fout.open("TablesInfo.dat");
	if (!fout.is_open()) {
		printf("Default Tables initialization failed.\n");
		return EXIT_FAILURE;
	}
	fout << "0 name\n1 name\n2 name\n";
	fout.close();
	printf("Default Tables settings upload success.\n");
	return EXIT_SUCCESS;
}

vector <Table> ShowTablesDatabase(vector <Table>& Tables) {
	printf("������ ������:\nCode     Name\n");
	for (int i = 0; i < (int)Tables.size(); i++) {
		printf("%d\t%s\n", Tables[i].code, Tables[i].name.c_str());
	}
	printf("---------------------------------------\n");
	return(Tables);
}

vector <Table> addTable(vector <Table>& Tables) {
	ofstream fout;
	Table temp;
	int code;
	string name;
	printf("������� ������ � ��������� �������: ��������\n");

	temp.code = Tables.size();
	cin >> temp.name;
	Tables.push_back(temp);
	fout.open("TablesInfo.dat", ofstream::app);
	code = temp.code; fout << code << " ";
	name = temp.name; fout << name << " " << '\n';
	printf("�� ������� �������� ���� %s\n", temp.name.c_str());

	return Tables;
}

vector <Table> removeTable(vector <Table>& Tables) {
	int searchId = 0;
	int counter = 0;

	ShowTablesDatabase(Tables);

	printf("������� code ����� �������� ������ ������� �� �������\n");
	scanf("%d", &searchId);

	for (int i = 0; i < (int)Tables.size(); i++) {
		if (searchId == Tables[i].code) {
			int confirm = 0;
			counter += 1;
			printf("�� ������������� ������ ������� ���� %d �� �������? 1 - ��. 0 - ���\n", Tables[i].code);
			scanf("%d", &confirm);
			if (confirm == 1) {
				Tables.erase(Tables.begin() + i);
				printf("�� ������� ������� �������. ������ ���� ������ �������� ���:\n");
				ShowTablesDatabase(Tables);
			}
			else {
				printf("�� ��������� �������� ��������\n");
			}
			break;
		}

	}
	if (counter == 0) printf("�������� � ��������� Id �� ������");

	return Tables;
}