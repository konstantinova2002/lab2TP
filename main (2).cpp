#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "List.h" 
using std::cout, std::cin, std::endl;

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	List TheList;

	int choice1, choice2;

	do {
		system("cls");

		cout << "����" << endl
			<< "1) ����������� ������ (������� 1)" << endl
			<< "2) �������� � ��������� ������ (������� 2)" << endl
			<< "3) ����� �� ���������" << endl
			<< "��������� �����: ";
		cin >> choice1;

		switch (choice1) {
		case 1:
			do {
				system("cls");
				cout << "�������" << endl
					<< "1) �������� �������" << endl
					<< "2) ������� ��� �������� �� �����" << endl
					<< "3) ������� ���� ����������� ������� �� �����" << endl
					<< "4) �������� ������ � ��������" << endl
					<< "5) ������� �������" << endl
					<< "6) ����� �� ���������" << endl
					<< "��������� �����: ";
				cin >> choice2;
				switch (choice2) {
				case 1:
					TheList.Insert();
					break;
				case 2:
					TheList.Show();
					break;
				case 3:
					TheList.ShowOnlyOne();
					break;
				case 4:
					TheList.Change();
					break;
				case 5:

					break;
				case 6:
					break;
				default:

					break;
				}
			} while (choice2 != 6);
			break;
		case 2:

			break;
		case 3:
			break;
		default:

			break;
		}
	} while (choice1 != 3);

	return 0;
}