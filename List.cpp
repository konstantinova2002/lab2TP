#include "List.h"

Element* List::GetHead() { return Head; };

void List::SetHead(Element* Head) { this->Head = Head; };

Element* List::GetTail() { return Tail; };

void List::SetTail(Element* Tail) { this->Tail = Tail; };

Element* List::GetIndex() { return Index; };

void List::SetIndex(Element* Index) { this->Index = Index; };

List::List() {
	system("cls");
	std::cout << "\n------|������ ����������� ������ List (��� ����������)|------\n";
	system("pause");

	Head = nullptr;
	Tail = nullptr;
	Index = nullptr;
}

List::List(Element* Head, Element* Tail, Element* Index) {
	std::cout << "\n------|������ ����������� ������ List (� ����������)|------\n";
	system("pause");

	this->Head = Head;
	this->Tail = Tail;
	this->Index = Index;
}

List::List(const List& other) {
	std::cout << "\n------|������ ����������� ������ List (�����������)|------\n";
	system("pause");

	this->Head = other.Head;
	this->Tail = other.Tail;
	this->Index = other.Index;
}

List::~List() {
	std::cout << "\n------|������ ���������� ������ List|------\n";
	system("pause");

}

void List::Insert() {
	Element* element = new Element();

	element->SetPrev(Tail);
	if (Head == nullptr) { // list empty
		Head = element;
		Index = element;
	}
	if (Tail != nullptr)
		Tail->SetNext(element);
	Tail = element;
}

void List::Show() {
	if (Tail == nullptr)
		return;

	system("cls");
	while (Index != nullptr) {
		cout << "\n\n����� ��������: " << (Index->GetInformationROUTE())->GetNumberRoute();
		cout << "\n��������� �����: " << (Index->GetInformationROUTE())->GetNameStart();
		cout << "\n�������� �����: " << (Index->GetInformationROUTE())->GetNameFinish();
		Index = Index->GetNext();
	}
	Index = Head;
	cout << "\n\n";
	system("pause");
}

void List::ShowOnlyOne() {
	if (Tail == nullptr)
		return;

	int choiceNumRoute;
	system("cls");
	cout << "\n\n\n������� ����� ��������, ������� ������ ������� �� �����...\n";
	cin >> choiceNumRoute;
	while ((Index->GetInformationROUTE())->GetNumberRoute() != choiceNumRoute) {
		Index = Index->GetNext();
	}
	cout << "\n\n����� ��������: " << (Index->GetInformationROUTE())->GetNumberRoute();
	cout << "\n��������� �����: " << (Index->GetInformationROUTE())->GetNameStart();
	cout << "\n�������� �����: " << (Index->GetInformationROUTE())->GetNameFinish();
	Index = Head;
	cout << "\n\n";
	system("pause");
}

void List::Change() {
	if (Tail == nullptr)
		return;

	int len;
	int choiceChange;
	int choicePoint;
	int changeNumberRoute;
	Show();
	cout << "\n\n������� ����� ��������, ������ �������� �� ������ ��������: ";
	cin >> choiceChange;
	system("cls");

	while ((Index->GetInformationROUTE())->GetNumberRoute() != choiceChange) {
		Index = Index->GetNext();
	}
	cout << "\n\n����� ��������: " << (Index->GetInformationROUTE())->GetNumberRoute();
	cout << "\n��������� �����: " << (Index->GetInformationROUTE())->GetNameStart();
	cout << "\n�������� �����: " << (Index->GetInformationROUTE())->GetNameFinish();
	Index = Head;
	cout << "\n\n�������� �����, ������� ������ ��������..." << endl
		<< "1) ����� ��������" << endl
		<< "2) ��������� �����" << endl
		<< "3) �������� �����" << endl
		<< "��������� �����: ";
	cin >> choicePoint;
	switch (choicePoint) {
	case 1:
		cout << "\n������� ����� ��������: ";
		cin >> changeNumberRoute;
		(Index->GetInformationROUTE())->SetNumberRoute(changeNumberRoute);
		break;
	case 2:
		cout << "\n������� ��������� ����� ��������: ";
		(Index->GetInformationROUTE())->SetNameStart(getString(&len));
		break;
	case 3:
		cout << "\n������� �������� ����� ��������: ";
		(Index->GetInformationROUTE())->SetNameFinish(getString(&len));
		break;
	default:
		cout << "\n\n������������ �����!!!\n����������, �������� ����� �� 1 �� 3.\n\n";
		system("pause");
		break;
	}
}