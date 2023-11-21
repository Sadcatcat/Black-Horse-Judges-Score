
#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include"Player.h"
using namespace std;


class My_sort
{
public:
	bool operator()(Player p1, Player p2)
	{
		return p1.Get_score() > p2.Get_score() ? true : false;
	}
};

class Start_race
{
public:
	Start_race();
	~Start_race();

	//设置选手
	void Set_Player();
	//对选手进行分组
	void Random_shuffle_Player(vector<Player>&Vs);
	//对选手进行打分
	void Rating_Player();
	//打印选手
	void Show_Player(int flag);
	//开始比赛
	void Win_race();
	//返回前三名
	const vector<Player>& Get_Win();
private:
	vector<Player>V;
	vector<Player>V1;
	vector<Player>V2;
	vector<Player>Win_V;
};