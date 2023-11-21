#include"WR_File.h"

WR_File::WR_File() 
{
	Read_File();
}

WR_File::WR_File(Start_race race)
{
	Win.resize(3);
	Win = race.Get_Win();
}

WR_File::~WR_File() {}


void WR_File::Write_File()
{
	//追加方式写文件
	ofstream w_file("speech.csv", ios::out | ios::app);
	for (vector<Player>::iterator it = Win.begin(); it != Win.end(); it++)
	{
		w_file << it->Get_id() << ',' << it->Get_score() << ',';
	}
	w_file << endl;
	w_file.close();
	cout << "前三名成绩写入到文件成功!" << endl;
}


void WR_File::Read_File()
{
	ifstream r_file("speech.csv", ios::in);

	if (!r_file.is_open())
	{
		this->is_file = 1;
		return;
	}

	char ch;
	r_file >>ch;
	if (r_file.eof())
	{
		this->is_file = 2;
		r_file.close();
		return;
	}

	//文件不为空
	//将上面读取的单个字符放回去
	r_file.putback(ch);
	string data;
	int index = 1;
	while (r_file >> data)
	{
		//cout << data << endl;
		//为了存放6个string的字符串
		int pos = -1;
		int start = 0;
		vector<string>V;
		while (true)
		{
			pos = data.find(',', start);
			//没找到
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos - start);
			V.push_back(temp);
			start = pos + 1;
		}
		this->M_record.insert(make_pair(index, V));
		index++;
	}
	
	r_file.close();
}


void WR_File::Show_race_record()
{
	if (this->is_file == 1)
	{
		cout << "文件不存在!" << endl;
	}
	else if (this->is_file == 2)
	{
		cout << "文件为空!" << endl;
	}
	for (map<int, vector<string>>::iterator it = M_record.begin(); it != M_record.end(); it++)
	{
		cout << "第" << it->first << "届比赛:" << endl;
		cout << "冠军编号:" << it->second[0] << "\t" << "冠军成绩:" << it->second[1] << endl;
		cout << "亚军编号:" << it->second[2] << "\t" << "亚军成绩:" << it->second[3] << endl;
		cout << "季军编号:" << it->second[4] << "\t" << "季军成绩:" << it->second[5] << endl;

	}
	
}




void WR_File::Del_File()
{
	//如果文件存在，会删除旧文件，建立新文件
	char select;
	cout << "是否真的清空文件？" << endl;
	cout << "Y or N:";
	cin >> select;
	if (select == 'Y' or select == 'y')
	{
		ofstream file("speech.csv", ios::trunc);
		cout << "清空成功!" << endl;
	}
	
}