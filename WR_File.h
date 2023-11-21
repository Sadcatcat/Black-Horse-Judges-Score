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
	//写文件
	void Write_File();
	//读文件
	void Read_File();
	//显示比赛记录
	void Show_race_record();
	//清空文件记录
	void Del_File();
private:
	map<int, vector<string>>M_record;
	int is_file=0;
	vector<Player>Win;
};

