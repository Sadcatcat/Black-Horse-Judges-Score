#include"Start_race.h"
using namespace std;


//打印数组里Player的id
void Show_vector_id(vector<Player>V)
{
	for (vector<Player>::iterator it = V.begin(); it != V.end(); it++)
	{
		cout << it->Get_id() << '\t';
	}
}

//打印数组里Player的id和score
void Show_vector_id_score(vector<Player>V)
{
	for (vector<Player>::iterator it = V.begin(); it != V.end(); it++)
	{
		cout <<"选手编号:" << it->Get_id() << '\t'<<"选手成绩:"<< it->Get_score() << endl;;
	}
}

//设置数组里Player的score
void Set_vector_Scroe(vector<Player>&V)
{
	for (vector<Player>::iterator it = V.begin(); it != V.end(); it++)
	{
		it->Set_score(75 + rand() % (100 - 75 + 1));
	}
}


Start_race::Start_race() {}


Start_race::~Start_race()
{
}


void Start_race::Set_Player()
{
	V.reserve(13);
	for (int i = 1; i <= 12; i++)
	{
		Player p(10000 + i, 0);
		
		V.push_back(p);
	}
}



void Start_race::Show_Player(int flag)
{
	if (flag == 1)
	{
		cout << "抽签后演讲顺序如下:" << endl;
		Random_shuffle_Player(V);
		Show_vector_id(V);
		V1.resize(V.size() / 2);
		V2.resize(V.size() / 2);
		copy(V.begin(), V.end() - V.size() / 2, V1.begin());
		copy(V.begin() + V.size() / 2, V.end(), V2.begin());
		Rating_Player();
		cout << endl;
	}
	
	if (flag == 2)
	{
		cout << "一组成员:" << endl;
		Show_vector_id(V1);
		cout << endl;
		cout << "二组成员:" << endl;
		Show_vector_id(V2);
		cout << endl;
	}
	if (flag == 3)
	{
		cout << "打分后:" << endl;
		cout << "一组成员成绩:" << endl;
		Show_vector_id_score(V1);
		cout << endl;
		cout << "二组成员成绩:" << endl;
		Show_vector_id_score(V2);
		cout << endl;

	}
	if (flag == 4)
	{
		cout << "决赛成员成绩:"<<endl;
		Random_shuffle_Player(V);
		Show_vector_id_score(V);
	}
	if (flag == 5)
	{
		Show_vector_id_score(Win_V);
	}
}


void Start_race::Random_shuffle_Player(vector<Player>&Vs)
{
	srand(time(0));
	random_shuffle(Vs.begin(), Vs.end());
}


void Start_race::Rating_Player()
{
	Random_shuffle_Player(V1);
	Random_shuffle_Player(V2);
	Set_vector_Scroe(V1);
	Set_vector_Scroe(V2);
}


void Start_race::Win_race()
{
	sort(V1.begin(), V1.end(), My_sort());
	sort(V2.begin(), V2.end(), My_sort());
	V.clear();
	V.resize(V1.size());
	copy(V1.begin(), V1.end() - V1.size() / 2, V.begin());
	copy(V2.begin(), V2.end()- V2.size() / 2, V.begin()+V1.size()/2);
	Set_vector_Scroe(V);
	sort(V.begin(), V.end(), My_sort());
	Win_V.resize(V.size() / 2);
	copy(V.begin(), V.end() - V.size() / 2, Win_V.begin());
}


const vector<Player>& Start_race::Get_Win()
{
	return this->Win_V;
}