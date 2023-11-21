#include<iostream>
#include"Player.h"
using namespace std;

Player::Player() {}

Player::Player(int id, int score) 
{
	this->id = id;
	this->score = score;
}

Player::~Player()
{

}

int Player::Get_id()
{
	return this->id;
}

int Player::Get_score()
{
	return this->score;
}

void Player::Set_score(int s)
{
	this->score = s;
}