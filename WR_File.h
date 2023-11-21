#pragma once
#include"Start_race.h"
#include <fstream>
#include<iostream>
#include<map>
using namespace std;

class WR_File	
{
public:
	WR_File();
	WR_File(Start_race race);
	~WR_File();
	//д�ļ�
	void Write_File();
	//���ļ�
	void Read_File();
	//��ʾ������¼
	void Show_race_record();
	//����ļ���¼
	void Del_File();
private:
	map<int, vector<string>>M_record;
	int is_file=0;
	vector<Player>Win;
};

