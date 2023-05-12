// ������� 11

// ����������� ������������� ���������� ������� ��� ������ � ����� ������. ������� ������:
// ���� ������ ������� �� �������. (��� �����, ������������, �����������, ����� �������������, ����� ������������ �����, �������, � ��������� ����� ���������� ���������� � ����������� ������)
// ����������:
// - �������� ������ � ����������� ������ � ��������������� ������:
// �) �� ���������� �����;
// �) � ����������;
// - �������� ����������� ���� ������;
// - �������������� ���� ������: 
// �) �������� ������; 
// �) ���������� ������;
// - ��������� ������:
// �) � ��������� ����;
// �) �� �����;
// - ����� ������ �� ���� �����; 
// - ���������� ������ �� ������������;
// - ��������� ���������� ���������� � ����������� �����;

// fout.open("test.txt", ofstream::app); ���������� ������ � ����� ����� ��� ������� ��������� �������� � ��������� ��;
// 1. ������ ������ ��� ����� � �������

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <algorithm>
#include <cctype>
#include "dish.h"
#include "access.h"
#include "initialization.h"
#include "auth.h"
#include "table.h"
#include "workers.h"
#include "models.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	struct Dish* Dishes;
	struct Table* Tables;
	struct Worker* Workers;
	WInit(Workers);
	TInit(Tables);
	DInit(Dishes);
	int accessLevel = -1;
	while (accessLevel < 0) {
		accessLevel = Auth(Workers);
	}
	switch (accessLevel) {
		case 0: AccessLevel0Tools(Dishes, Workers, Tables); break;
		case 1: AccessLevel1Tools(Dishes, Workers, Tables); break;
		case 2: AccessLevel2Tools(Dishes, Workers, Tables); break;
	}
	return 0;
}