#include "models.h"
#include "workers.h"

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

void showDishesDatabase(struct Dish* head) {
	printf("������ ����������:\nId    SecondName     Name    Numberphone\n");
	while (head != NULL) {
		printf("%d\t%s\t%s\t%s\n", Workers[i].id, Workers[i].secondName.c_str(), Workers[i].name.c_str(), Workers[i].phoneNumber.c_str());
		head = head->next;
	}
}

void push(struct Dish** headRef) {
	struct Dish* newNode = (struct Dish*)malloc(sizeof(struct Dish));
	newNode->code = headRef.code + 1;
	cin >> newNode.secondName;
	cin >> newNode.name;
	cin >> newNode.phoneNumber;
	cin >> newNode._login;
	cin >> newNode._password;
	cin >> newNode._accessLevel;

	newNode->next = (*headRef);
	newNode->prev = NULL;

	if (*headRef != NULL) {
		*headRef->prev = newNode;
	}
	*headRef = newNode;

	printf("�� ������� �������� ��������� %s %s\n", newNode.secondName.c_str(), newNode.name.c_str());
}

void deletion(struct Dish** headRef, int code) {
	struct Dish* current = *headRef;
	while (current != NULL) {
		if (code == current->code) {
			if (current->prev != NULL) {
				current->prev = current->next;
				printf("deletion is complete");
				return;
			}
		}
		current = current->next;
	}

	printf("there is no dish with such a code");
}

void showSerialWorker(struct Dish* head, int code) {
	while (head != NULL) {
		if (head->code == code) {
			printf("������� ���� ��������:\nId - %d, ������� - %s, ��� - %s, ����� �������� - %s, ������� ������� - %d\n", head->id, head->secondName.c_str(), head->name.c_str(), head->phoneNumber.c_str(), head->_accessLevel);
			return;
		}
		head = head->next;
	}
}