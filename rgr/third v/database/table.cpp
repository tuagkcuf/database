#include "table.h"
#include "models.h"

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

void ShowTablesDatabase(struct Table* head, int code) {
    while (head != NULL) {
        if (head->code == code) {
            printf("%d\t%s\t%s\t%d\t%d\t%d\t\n", head->code, head->name.c_str(), head->ingredients.c_str(), head->time, head->numberOfTable, head->calories);
            return;
        }
        head = head->next;
    }
}

void push(struct Table** headRef) {
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

void deletion(struct Table** headRef, int code) {
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
