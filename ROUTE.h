#pragma once
#include <iostream>

class ROUTE{
private:
	char* NameStart;	// �������� ���������� ������ ��������
	char* NameFinish;	// �������� ��������� ������ ��������
	int NumberRoute;	// ����� ��������
public:
	ROUTE();
	ROUTE(int NumberRoute);
	ROUTE(const ROUTE& other);
	~ROUTE();

	char* GetNameStart();
	void SetNameStart(char* NameStart);
	char* GetNameFinish();
	void SetNameFinish(char* NameFinish);
	int GetNumberRoute();
	void SetNumberRoute(int NumberRoute);
};