#pragma once



class Player
{
public:
	Player();
	Player(int id,int score);
	~Player();

	int Get_id();
	int Get_score();
	void Set_score(int s);

private:
	int id;
	int score;
};


