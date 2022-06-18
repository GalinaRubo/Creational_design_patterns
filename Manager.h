
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <io.h>  //���������� ��� ������ � ������� � ����� ������� 
#include <windows.h>

using namespace std;
class ActDoc
{
public:
	string Path;

	ActDoc()//����������� � ��������������
	{
		Path = SetPath();
	}

	//������� ����� ���� � ����������
	string SetPath()
	{
		cout << "������� ���� � ���������: ";
		getline(cin, Path);// ���� ���� � ����� ����� � ����������
		while (CheckPath())
		{
			cout << "������� ����  � ��������� ���������: " << endl;
			SetPath();
		}
		return Path;
	}

	//������� �������� �� ������������ ����� ���� � �����
	bool CheckPath()
	{
		WIN32_FILE_ATTRIBUTE_DATA;
		const char* P = Path.data();
		_finddata_t* InfoFile = new _finddata_t;
		intptr_t Done = _findfirst(P, InfoFile);
		if (InfoFile->attrib & _A_SUBDIR) //�������� �� ���������� ��
		{
			Path.append("\\");
			Path = AddName();
			return 0;
		}
		if (Done == -1)
		{
			while (int pos = PosSimbol("\\"))
			{
				Path.erase(pos);
				if (!CheckPath()) return 0;
			};
			printf("���� ����� �������!\n");
			return 1;
		}
		return 0;
	}
	//������� ����������� �������  ��������� �������� ���������  � ������
	int PosSimbol(string str)
	{
		int i = 0;
		int pos = 0;
		//����������� ������� ���������� ��������� �������  � ������
		for (i = Path.find(str, i++); i != -1; i = Path.find(str, i + 1))
		{
			pos = i;
			continue;
		}
		return pos;//����������� ������� ���������� �������
	}
	//������� ������� ����� ����� � ����
	string AddName()
	{
		string NewName;// ����� ��� �����
		cout << "������� ��� ���������: ";
		getline(cin, NewName);// ����� ����� � ����������		
		string NewPath = Path;
		//���������� ���� �� ������� �����
		int pos = 0;
		pos = PosSimbol("\\");
		NewPath.erase(pos + 1);
		//���������� � ���� ������ ����� � �������� ��� � ������� rename
		NewPath.append(NewName);
		return NewPath;
	}
};


class FunDoc : virtual  ActDoc
{
public:
	//������� �������� ���������
	void Open()
	{
		ifstream Doc(Path);
		if (Doc.is_open()) // ����� ������ is_open()
		{
			cout << "�������� ������!" << endl;
		}
		else
		{
			cout << "������ ��� �������� ���������!" << endl;
		}
	}
	//������� �������� �����
	void Close()
	{
		ifstream Doc(Path);
		if (Doc.is_open())
		{
			Doc.close();
			cout << "�������� ������!" << endl;
		}
		else
		{
			cout << "�������� ��� ������!" << endl;
		}
	}
	//������� ������ ��������
	void Print()
	{
		ifstream Doc(Path);
		cout << "�������� " << Path << " ����������!" << endl;

	}
	//������� �������� ��������� 
	void Create()
	{
		ifstream Doc(Path);
		if (Doc.is_open())
		{
			cout << "�������� ����������!";
		}
		else
		{
			ofstream Doc(Path);
			cout << "�������� ������!\n\n";
		}
	}
	//������� ���������� �����
	void Save()
	{
		ifstream Doc(Path);
		if (Doc.is_open())
		{
			Doc.close();
			cout << "�������� ��������!\n\n";
		}
		else
		{
			cout << "�������� ��� ��������!\n\n";
		}
	}
	//������� ���������� ����� � ����� ������
	void Save_n()
	{
		ifstream Doc(Path);
		if (Doc.is_open())
		{
			Doc.close();
		}
		Rename();
	}

	//�������������� �����
	void Rename()
	{
		string NewPath;
		NewPath = AddName();
		rename(Path.data(), NewPath.data());
		cout << "�������� ������� �������� � ����� ������!" << endl;
	}
};






