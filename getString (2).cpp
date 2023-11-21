#include "getString.h"
#include <cstdio>

char* getString(int* len) {
    *len = 0;                             // ��������� ����� ������ ����� 0
    int capacity = 1;                      // ������� ������, ������� � ����� ��� ����-�����������
    char* s = new char[capacity];          // ��������� ������ ��� ������

    int c;                                 // ������ ���� ���� int ��� ��������� EOF
    // ���������� ��� ������� ����� ������, ������� ����� �������� � ������ �����.
    while ((c = getchar()) == '\n');

    // ���� ����� �� ������ ����� �����, ���������� ������
    if (c != EOF) {
        do {
            if (*len + 1 >= capacity) {    // �������� �� ������������ �������
                capacity *= 2;              // ���������� ������� � 2 ����
                char* temp = new char[capacity]; // ��������� ����� ������

                for (int i = 0; i < *len; ++i) {
                    temp[i] = s[i];         // ����������� ������ ������ � ����� �����
                }

                delete[] s;                 // ������� ������� ������
                s = temp;                   // ���������� ������ ������ ������
            }
            s[(*len)++] = c;                // ���������� ������ ������� � ���������� �����
        } while ((c = getchar()) != '\n' && c != EOF); // ������ �� ����� ������ ��� �����
    }

    if (*len + 1 >= capacity) {
        // ��������, ��� ���� ����� ��� ����-�����������.
        char* temp = new char[*len + 1];
        for (int i = 0; i < *len; ++i) {
            temp[i] = s[i];
        }
        delete[] s;
        s = temp;
    }

    s[*len] = '\0';                         // ���������� ������ ������� ��������
    return s;                               // ������� ��������� �� ������
}