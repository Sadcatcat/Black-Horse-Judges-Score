#include<iostream>
#include"Start_race.h"
#include"WR_File.h"

using namespace std;

bool Start_Select(Start_race S)
{
	int select;
	int Race_num = 1;
	cout << "请输入您的选择: ";
	cin >> select;
	S.Set_Player();
	WR_File F;
	switch (select)
	{
	case 1: {
		cout << "第<<" << Race_num << ">>轮比赛选手正在抽签" << endl;;
		S.Show_Player(1);
		system("pause");
		cout << "分组中..." << endl;
		Race_num++;
		cout << "第<<" << Race_num << ">>轮比赛选手正在抽签" << endl;;
		S.Show_Player(2);
		cout << "打分中..." << endl;
		system("pause");
		S.Show_Player(3);
		S.Win_race();
		system("pause");
		cout << "最终组..." << endl;
		S.Show_Player(4);
		system("pause");
		cout << "前三选手..." << endl;
		S.Show_Player(5);
		cout << "正在保存文件..." << endl;
		WR_File F(S);
		F.Write_File();
		break;
	};
	case 2: {F.Show_race_record(); break; }
	case 3: {F.Del_File(); break; }
	case 0: {return 0; break; }
	default: {cout << "输入错误！" << endl; break; }
	}
	return 1;
}


void Show_Interface()
{
	while (true)
	{
	Start_race S;
	cout << "  选手打分系统" << endl;
	cout << "1.开始演讲比赛" << endl;
	cout << "2.查看往届比赛记录" << endl;
	cout << "3.清空比赛记录" << endl;
	cout << "0.退出比赛程序" << endl;
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
	cout << "程序成功退出！" << endl;
	system("pause");
	return 0;
}