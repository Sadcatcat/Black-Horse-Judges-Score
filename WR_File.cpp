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
	//׷�ӷ�ʽд�ļ�
	ofstream w_file("speech.csv", ios::out | ios::app);
	for (vector<Player>::iterator it = Win.begin(); it != Win.end(); it++)
	{
		w_file << it->Get_id() << ',' << it->Get_score() << ',';
	}
	w_file << endl;
	w_file.close();
	cout << "ǰ�����ɼ�д�뵽�ļ��ɹ�!" << endl;
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

	//�ļ���Ϊ��
	//�������ȡ�ĵ����ַ��Ż�ȥ
	r_file.putback(ch);
	string data;
	int index = 1;
	while (r_file >> data)
	{
		//cout << data << endl;
		//Ϊ�˴��6��string���ַ���
		int pos = -1;
		int start = 0;
		vector<string>V;
		while (true)
		{
			pos = data.find(',', start);
			//û�ҵ�
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
		cout << "�ļ�������!" << endl;
	}
	else if (this->is_file == 2)
	{
		cout << "�ļ�Ϊ��!" << endl;
	}
	for (map<int, vector<string>>::iterator it = M_record.begin(); it != M_record.end(); it++)
	{
		cout << "��" << it->first << "�����:" << endl;
		cout << "�ھ����:" << it->second[0] << "\t" << "�ھ��ɼ�:" << it->second[1] << endl;
		cout << "�Ǿ����:" << it->second[2] << "\t" << "�Ǿ��ɼ�:" << it->second[3] << endl;
		cout << "�������:" << it->second[4] << "\t" << "�����ɼ�:" << it->second[5] << endl;

	}
	
}




void WR_File::Del_File()
{
	//����ļ����ڣ���ɾ�����ļ����������ļ�
	char select;
	cout << "�Ƿ��������ļ���" << endl;
	cout << "Y or N:";
	cin >> select;
	if (select == 'Y' or select == 'y')
	{
		ofstream file("speech.csv", ios::trunc);
		cout << "��ճɹ�!" << endl;
	}
	
}