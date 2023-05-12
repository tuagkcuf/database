#include "models.h"
#include "auth.h"

int Auth(struct Worker** head) {
    string password = "";
	string login = "";

	printf("������� �����\n");
	cin >> login;
	printf("������� ������\n");
	cin >> password;

	transform(login.begin(), login.end(), login.begin(), tolower);

    while (head != NULL) {
        if (head->_login == login) {
			if (head->_password == password) {
				printf("success\n");
				return(head->_accessLevel);
			}
			else {
				break;
			}
		}
        head = head->next;
    }
}