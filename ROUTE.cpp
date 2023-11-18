#include "ROUTE.h"

char* ROUTE::GetNameStart() { return NameStart; };

void ROUTE::SetNameStart(char* NameStart) { this->NameStart = NameStart; };

char* ROUTE::GetNameFinish() { return NameFinish; };

void ROUTE::SetNameFinish(char* NameFinish) { this->NameFinish = NameFinish; };

int ROUTE::GetNumberRoute() { return NumberRoute; };

void ROUTE::SetNumberRoute(int NumberRoute) { this->NumberRoute = NumberRoute; };

ROUTE::ROUTE() {
	std::cout << "\n------|Вызван конструктор класса ROUTE (без параметров)|------\n";
	NameStart = nullptr;
	NameFinish = nullptr;
	NumberRoute = 0;
}

ROUTE::ROUTE(int NumberRoute) {
	std::cout << "\n------|Вызван конструктор класса ROUTE (с параметром)|------\n";
	NameStart = nullptr;
	NameFinish = nullptr;
	this->NumberRoute = NumberRoute;
}

ROUTE::ROUTE(const ROUTE& other) {
	std::cout << "\n------|Вызван конструктор класса ROUTE (копирования)|------\n";
	this->NameStart = other.NameStart;
	this->NameFinish = other.NameFinish;
	this->NumberRoute = other.NumberRoute;
}

ROUTE::~ROUTE() {
	std::cout << "\n------|Вызван деструктор класса ROUTE|------\n";
	delete[] NameStart;
	NameStart = nullptr;
	delete[] NameFinish;
	NameFinish = nullptr;
	NumberRoute = 0;
}