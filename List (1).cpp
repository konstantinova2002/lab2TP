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

	this->Head = nullptr;
	this->Tail = nullptr;
	this->Index = nullptr;

	if (other.Tail == nullptr)
		return;

	Element* firstElement = new Element();
	this->Head = firstElement;
	Element* newRear_tmp = firstElement;

	Element* rear_tmp = other.Head->GetNext(); 
	while (rear_tmp != nullptr) {
		Element* element = new Element();
		this->Tail = element;
		element->SetPrev(newRear_tmp);
		newRear_tmp->SetNext(element);
		newRear_tmp = newRear_tmp->GetNext();

		rear_tmp = rear_tmp->GetNext();
	}

	Index = Head;
}

List::~List() {
	std::cout << "\n------|������ ���������� ������ List|------\n";
	system("pause");

	while (Index != nullptr) {
		if (Index == nullptr) {
			return;
		}

		if (Index == Tail) {
			delete Tail;
			Index = nullptr;
			Tail = nullptr;
			Head = nullptr;
			return;
		}

		Element* tmp_element = Index;
		Index = tmp_element->GetNext();
		delete tmp_element;
	}
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

void List::Insert(int NumberRouteForCopy, Element& _element) {
	Element* element = new Element(NumberRouteForCopy, _element);  

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

	Sorting();

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
	Index = Head;
}

void List::Delete() {
	if (Tail == nullptr)
		return;

	int cnt = 1;
	int choiceDelete;
	Show();
	cout << "\n\n\n������� ����� ��������, ������� ������ �������: ";
	cin >> choiceDelete;



	while ((Index->GetInformationROUTE()->GetNumberRoute()) != choiceDelete) {
		Index = Index->GetNext();
	}

	if (Head == Tail) {
		Head = nullptr;
		Tail = nullptr;
		delete Index;
		Index = nullptr;
		return;
	}
	else {
		if (Index == Tail) {
			Tail = Index->GetPrev();
			Tail->SetNext(nullptr);
			delete Index;
			Index = Tail;
		}
		else {
			if (Index == Head) {
				Head = Index->GetNext();
				Head->SetPrev(nullptr);
				delete Index;
				Index = Head;
			}
			else {
				(Index->GetPrev())->SetNext(Index->GetNext());
				(Index->GetNext())->SetPrev(Index->GetPrev());
				delete Index;
				Index = Head;
			}
		}
	}
	Index = Head;
}

void List::Sorting() {
	List CopyList;

	int lenList = 0;
	while (Index != nullptr) {
		lenList++;
		Index = Index->GetNext();
	}
	Index = Head;
	int* arrNumbersRoute = new int[lenList];
	int cnt = 0;
	while (Index != nullptr) {
		arrNumbersRoute[cnt] = (Index->GetInformationROUTE())->GetNumberRoute();
		cnt++;
		Index = Index->GetNext();
	}
	Index = Head;
	qsort(arrNumbersRoute, lenList, sizeof(int), compare);

	cnt = 0;
	while (cnt < lenList) {
		while ((Index->GetInformationROUTE())->GetNumberRoute() != arrNumbersRoute[cnt]) {
			Index = Index->GetNext();
		}
		CopyList.Insert(arrNumbersRoute[cnt], *Index); 
		Index = Head;
		cnt++;
	}
	Clear(&CopyList);
}

void List::Clear(List* _copyList) {
	while (Index != nullptr) {
		delete Index->GetInformationROUTE();
		Index = Index->GetNext();
	}
	Index = Head;
	
	while (Index != nullptr) {
		ROUTE* newInformationRoute = new ROUTE(0); 
		newInformationRoute = (_copyList->Index)->GetInformationROUTE();
		Index->SetInformationROUTE(newInformationRoute);
		_copyList->Index = (_copyList->Index)->GetNext();
		Index = Index->GetNext();
	}
	Index = Head;
}