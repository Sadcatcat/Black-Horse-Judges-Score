#include<iostream>
#include"Start_race.h"
#include"WR_File.h"

using namespace std;

bool Start_Select(Start_race S)
{
	int select;
	int Race_num = 1;
	cout << "����������ѡ��: ";
	cin >> select;
	S.Set_Player();
	WR_File F;
	switch (select)
	{
	case 1: {
		cout << "��<<" << Race_num << ">>�ֱ���ѡ�����ڳ�ǩ" << endl;;
		S.Show_Player(1);
		system("pause");
		cout << "������..." << endl;
		Race_num++;
		cout << "��<<" << Race_num << ">>�ֱ���ѡ�����ڳ�ǩ" << endl;;
		S.Show_Player(2);
		cout << "�����..." << endl;
		system("pause");
		S.Show_Player(3);
		S.Win_race();
		system("pause");
		cout << "������..." << endl;
		S.Show_Player(4);
		system("pause");
		cout << "ǰ��ѡ��..." << endl;
		S.Show_Player(5);
		cout << "���ڱ����ļ�..." << endl;
		WR_File F(S);
		F.Write_File();
		break;
	};
	case 2: {F.Show_race_record(); break; }
	case 3: {F.Del_File(); break; }
	case 0: {return 0; break; }
	default: {cout << "�������" << endl; break; }
	}
	return 1;
}


void Show_Interface()
{
	while (true)
	{
	Start_race S;
	cout << "  ѡ�ִ��ϵͳ" << endl;
	cout << "1.��ʼ�ݽ�����" << endl;
	cout << "2.�鿴���������¼" << endl;
	cout << "3.��ձ�����¼" << endl;
	cout << "0.�˳���������" << endl;
	cout << endl;
	if (!Start_Select(S))
	break;
	system("pause");
	system("cls");
	}
}




int main()
{
	Show_Interface();
	cout << endl;
	system("cls");
	cout << "����ɹ��˳���" << endl;
	system("pause");
	return 0;
}