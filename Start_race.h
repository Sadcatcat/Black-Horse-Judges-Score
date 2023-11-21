
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

	//����ѡ��
	void Set_Player();
	//��ѡ�ֽ��з���
	void Random_shuffle_Player(vector<Player>&Vs);
	//��ѡ�ֽ��д��
	void Rating_Player();
	//��ӡѡ��
	void Show_Player(int flag);
	//��ʼ����
	void Win_race();
	//����ǰ����
	const vector<Player>& Get_Win();
private:
	vector<Player>V;
	vector<Player>V1;
	vector<Player>V2;
	vector<Player>Win_V;
};