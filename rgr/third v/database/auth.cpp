int Auth(vector <Worker>& Workers) {
	string password = "";
	string login = "";

	printf("������� �����\n");
	cin >> login;
	printf("������� ������\n");
	cin >> password;

	transform(login.begin(), login.end(), login.begin(), tolower);

	for (int i = 0; i < (int)Workers.size(); i++) {
		if (Workers[i]._login == login) {
			if (Workers[i]._password == password) {
				printf("success\n");
				return(Workers[i]._accessLevel);
			}
			else {
				break;
			}
		}
	}
	printf("�� ����� �������� ������, ���������� �����\n");

	return -1;
}