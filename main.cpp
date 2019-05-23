#include<iostream>
#include<Windows.h>
using namespace std;

//#define CASE_FUNCTIONS

void InputLine(char szStr[], const int n);
int  StrLen(char szStr[]);      //���������� ���������� �������� � ������.
void UpperCase(char szStr[]);	//��������� ������ � ������� �������.
void LowerCase(char szStr[]);	//��������� ������ � ������ �������.
void Capitalize(char szStr[]);  //������ ��������� ������ ����� ������� ����� � �����������.
bool isLowLetter(char symbol);
bool isLowRusLetter(char symbol);

void Shrink(char szStr[]);		//������� ������ ������� ����� ������� � �����������.
void RemoveSpaces(char szStr[]);//������� ��� ������� ����� ������� � �����������.
bool isPalindrome(char szStr[]);	//���������, �������� �� ������ ������ �����������.
bool isNumber(char szStr[]);	//���������, �������� ������ ������. ������ �������� ������, ���� �������� ������ �����.
bool isHexNumber(char szStr[]);	//���������, �������� ������ ����������������� ������. ������ �������� Hex-������, ���� �������� ������ ����� � ����� ABCDEF ���� abcdef.


void main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 256;	//������ ������
	char szStr[n] = {};
	cout << "������� ������: ";
	InputLine(szStr, n);
#if defined CASE_FUNCTIONS
	cout << "������ ������: " << sizeof(szStr) << endl;
	cout << "���������� �������� � ������: " << StrLen(szStr) << endl;
	UpperCase(szStr);
	cout << szStr << endl;
	LowerCase(szStr);
	cout << szStr << endl;
	Capitalize(szStr);
	cout << szStr << endl;
#endif
	Shrink(szStr);
	cout << "������� ������ �������: " << szStr << endl;
	cout << "������ �������� �����������: " << isPalindrome(szStr) << endl;
	RemoveSpaces(szStr);
	cout << "������� ��� �������: " << szStr << endl;
	cout << "������ �������� ������: " << isNumber(szStr) << endl;
	cout << "������ �������� Hex-������: " << isHexNumber(szStr) << endl;
}

void InputLine(char szStr[], const int n)
{
	SetConsoleCP(1251);
	cin.getline(szStr, n);
	SetConsoleCP(866);
}

int  StrLen(char szStr[])
{
	int i = 0;
	for (; szStr[i]; i++);
	return i;
}

void UpperCase(char szStr[])
{
	for (int i = 0; szStr[i]; i++)
		if
			(
				szStr[i] >= 'a' && szStr[i] <= 'z' ||
				szStr[i] >= '�' && szStr[i] <= '�'
				)
			szStr[i] -= 32;
}

void LowerCase(char szStr[])
{
	for (int i = 0; szStr[i]; i++)
		if
			(
				szStr[i] >= 'A' && szStr[i] <= 'Z' ||
				szStr[i] >= '�' && szStr[i] <= '�'
				)
			szStr[i] += 32;
}

void Capitalize(char szStr[])
{
	LowerCase(szStr);
	if (isLowLetter(szStr[0]) || isLowRusLetter(szStr[0]))szStr[0] -= 32;
	for (int i = 0; szStr[i]; i++)
	{
		if (szStr[i - 1] == ' ' || (isLowLetter(szStr[0])) || isLowRusLetter(szStr[0]))
			szStr[i] -= 32;
	}
}

bool isLowLetter(char symbol)
{
	if (symbol >= 'a' && symbol <= 'z')return true;
	else return false;
}

bool isLowRusLetter(char symbol)
{
	if (symbol >= '�' && symbol <= '�')return true;
	else return false;
}

void Shrink(char szStr[])
{
	for (int i = 0; szStr[i]; i++)
	{
		while (szStr[i] == ' ' && szStr[i + 1] == ' ')
			for (int j = i + 1; szStr[j]; j++)
			{
				szStr[j] = szStr[j + 1];
			}
	}
}

bool isPalindrome(char szStr[])
{
	int size = StrLen(szStr);
	char*buffer = new char[size + 1]{};
	for (int i = 0; i < size; i++)	buffer[i] = szStr[i];
	LowerCase(buffer);
	RemoveSpaces(buffer);
	size = StrLen(buffer);
	for (int i = 0; i < size / 2; i++)
	{
		if (buffer[i] != buffer[size - i - 1])
		{
			delete[] buffer;
			return false;
		}
	}
	return true;
}

void RemoveSpaces(char szStr[])
{
	for (int i = 0; szStr[i]; i++)
	{
		while (szStr[i] == ' ')
			for (int j = i; szStr[j]; j++)
			{
				szStr[j] = szStr[j + 1];
			}
	}
}

bool isNumber(char szStr[])
{
	for (int i = 0; i < szStr[i]; i++)
	{
		if (szStr[i] >= '0' && szStr[i] <= '9')return true;
		else return false;
	}
}

bool isHexNumber(char szStr[])
{
	for (int i = 0; i < szStr[i]; i++)
	{
		if (szStr[i] >= '0' && szStr[i] <= '9' && szStr[i] >= 'A' && szStr[i] <= 'F' || szStr[i] >= 'a' && szStr[i] <= 'f')return true;
		else return false;
	}
}