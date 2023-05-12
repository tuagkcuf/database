#include "dish.h"
#include "models.h"

void sortedInsert(struct Dish** headRef, struct Dish* newNode) {
    struct Dish* current;

    if (*headRef == NULL) {
        *headRef = newNode;
    } else if ((*headRef)->calories >= newNode->calories) {
        newNode->next = *headRef;
        newNode->next->prev = newNode;
        *headRef = newNode;
    } else {
        current = *headRef;
        while (current->next != NULL && current->next->calories < newNode->calories) {
            current = current->next;
        }

        newNode->next = current->next;

        if (current->next != NULL) {
            newNode->next->prev = newNode;
        }

        current->next = newNode;
        newNode->prev = current;
    }
}

void insertionSort(struct Dish** headRef) {
    struct Dish* sorted = NULL;

    struct Dish* current = *headRef;
    while (current != NULL) {
        struct Dish* next = current->next;
        current->prev = current->next = NULL;
        sortedInsert(&sorted, current);
        current = next;
    }
    *headRef = sorted;
}

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

void showDishesDatabase(struct Dish* head) {
    while (head != NULL) {
        printf("%d\t%s\t%s\t%d\t%d\t%d\t\n", head->code, head->name.c_str(), head->ingredients.c_str(), head->time, head->numberOfTable, head->calories);
        head = head->next;
    }
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

void push(struct Dish** headRef) {
    struct Dish* newNode = (struct Dish*)malloc(sizeof(struct Dish));
    newNode->code = headRef.code + 1;
    cin >> newNode->name;
    cin >> newNode->ingredients;
    cin >> newNode->time;
    cin >> newNode->numberOfTable;
    cin >> newNode->calories;

    newNode->next = (*headRef);
    newNode->prev = NULL;

    if (*headRef != NULL) {
        *headRef->prev = newNode;
    }
    *headRef = newNode;
}

void showSerialDish(struct Dish* head, int code) {
    while (head != NULL) {
        if (head->code == code) {
            printf("%d\t%s\t%s\t%d\t%d\t%d\t\n", head->code, head->name.c_str(), head->ingredients.c_str(), head->time, head->numberOfTable, head->calories);
            return;
        }
        head = head->next;
    }
}

void ChangeDishesDatabase(struct Dish* head) {
	int func = 0;;
	printf("������� ����� �������� ������� 1 - ������� ������, 2 - �������� ������\n");
	scanf("%d", &func);
	switch (func) {
	case 1: {
		int searchId = 0;
		ShowDishesDatabase(head);
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
					deletion(head, i);
					printf("�� ������� ������� �������.\n� ������ ������ ���� ������ ������� �������� ���:\n");
					ShowDishesDatabase(head);
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
		printf("������� ������ ����� � ������� ��� ����������� �����_������������� �����_����� �������\n");
        push(head)
		printf("�� ������� �������� ����� � ���� ������. Id ������������ ���� ������ - %d\n", Dishes[Dishes.size() - 1].code);
		printf("---------------------------------------\n");
		ShowDishesDatabase(head);
		break;
	}
	default: "�� ����� �������� ��������, ������������� ��� � ������� ����."; return Dishes;
	}
}