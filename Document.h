#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <io.h>  //���������� ��� ������ � ������� � ����� ������� 
#include <windows.h>

using namespace std;

class Document
{
public:
	string Path;

	Document()//����������� � ��������������
	{
		Path = SetPath();
	}
	//������� ����� ����
	string InputPath()
	{
		while (CheckPath())
		{
			InputPath();
		}
		return Path;
	}
	//������� ����� ����
	string SetPath()
	{
		return (InputPath());
	}
	//������� �������� �� ������������ ����� ���� � �����
	bool CheckPath()
	{
		return 0;
	}
	//������� ������������ ����� ����� � ����
	string AddName()
	{
		string NewPath;
		return NewPath;
	}
	//������� ����������� �������  ��������� �������� ���������  � ������
	int PosSimbol(string str)
	{
		int pos = 0;
		return pos;//����������� ������� ��������� ��������� � ������
	}
};


