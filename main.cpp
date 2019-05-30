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
bool isPalindrome(char szStr[]);//���������, �������� �� ������ ������ �����������.
bool isNumber(char szStr[]);	//���������, �������� ������ ������. ������ �������� ������, ���� �������� ������ �����.
bool isBinNumber(char szStr[]);
bool isHexNumber(char szStr[]);	//���������, �������� ������ ����������������� ������. ������ �������� Hex-������, ���� �������� ������ ����� � ����� ABCDEF ���� abcdef.
int Bin2Dec(char szStr[]);
int Hex2Dec(char szStr[]);

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
	Shrink(szStr);
	cout << "������� ������ �������: " << szStr << endl;
	cout << "������ �������� �����������: " << isPalindrome(szStr) << endl;
	RemoveSpaces(szStr);
	cout << "������� ��� �������: " << szStr << endl;
	cout << "������ �������� ������: " << isNumber(szStr) << endl;
#endif
	cout << "������ �������� Hex-������: " << isHexNumber(szStr) << endl;
	cout << "������ �������� �������� ������: " << isBinNumber(szStr) << endl;
	cout << Bin2Dec(szStr) << endl;
	cout << Hex2Dec(szStr) << endl;
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
	if ((szStr[0] < '0' || szStr[0] > '9') && szStr[0] != '-' && szStr[0] != '+')return false;
	for (int i = 1; szStr[i]; i++)
	{
		if (szStr[i] < '0' || szStr[i] > '9')return false;
		return true;
	}
}

bool isBinNumber(char szStr[])
{
	int n = StrLen(szStr);
	char* buffer = new char[n + 1]{};
	for (int i = 0; szStr[i]; i++)buffer[i] = szStr[i];
	RemoveSpaces(buffer);
	for (int i = 0; buffer[i]; i++)
	{
		if (buffer[i] != '0' && buffer[i] != '1')
		{
			delete[]buffer;
			return false;
		}
	}
	return true;
}

bool isHexNumber(char szStr[])
{
	for (int i = 0; i < szStr[i]; i++)
	{
		/*if (
			!(szStr[i] >= '0' && szStr[i] <= '9') &&
			!(szStr[i] >= 'A' && szStr[i] <= 'F') &&
			!(szStr[i] >= 'a' && szStr[i] <= 'f')
			)return false;*/
		if (szStr[i] < '0' || (szStr[i] > '9' && szStr[i] < 'A') || (szStr[i] > 'F' && szStr[i] < 'a') || szStr[i] > 'f')return false;
	}
	return true;
}

int Bin2Dec(char szStr[])
{
	if (!isBinNumber(szStr))
	{
		cout << "Error: not binary" << endl;
		return 0;
	}
	int capacity = StrLen(szStr);
	int decimal = 0; //���������� �����
	int weight = 1; //������� �����������
	for (int i = capacity - 1; i >= 0; i--)
	{
		if (szStr[i] == ' ')continue;
		decimal += (szStr[i] - 48)*weight;
		weight *= 2;
	}
	return decimal;
}

int Hex2Dec(char szStr[])
{
	if (!isHexNumber(szStr))
	{
		cout << "Error: not hexadecimal" << endl;
		return 0;
	}
	int decimal = 0; //���������� �����
	int weight = 1; //������� �����������
	UpperCase(szStr);
	for (int i = StrLen(szStr) - 1; i >= 0; i--)
	{
		if (szStr[i] == ' ')continue;
		/*int digit;
		if (szStr[i] >= 'a') digit = szStr[i] - 87;
		else if (szStr[i] >= 'A') digit = szStr[i] - 55;
		else digit = szStr[i] - 48;
		decimal += digit*weight;*/
		//decimal += (szStr[i] >= 'a' ? szStr[i] - 87 : szStr[i] >= 'A' ? szStr[i] - 55 : szStr[i] - 48)*weight;
		decimal += (szStr[i] >= 'A' ? szStr[i] - 55 : szStr[i] - 48)*weight;
		weight *= 16;
	}
	return decimal;
}