#include "balance.h"
balance::balance() :Base_table()
{
	name = "Баланс";
}
balance::~balance()
{
}
balance::balance(const balance & sltemp) :Base_table(), name(sltemp.name), data(sltemp.data)
{

}
balance::balance(string str) : Base_table(), name(str)
{
}
void balance::horisontal_input()
{
	cout << name << endl;
	vector<int> vec_size;
	for (auto &temp : data)
	{
		cout << temp.first << " ";
		int temp_second_length = lengt_unsint(temp.second), temp_first_length = temp.first.length();
		if (temp_second_length > temp_first_length)
		{
			cout << string(temp_second_length - temp_first_length, ' ');

		}
		vec_size.push_back(temp_first_length - temp_second_length);
	}
	cout << endl;
	auto it_vec_size = vec_size.begin();
	for (auto &temp : data)
	{
		cout << temp.second << " ";
		if (*it_vec_size > 0)
			cout << string(*it_vec_size, ' ');
		it_vec_size++;
	}
	cout << endl;
}
void balance::vertical_input()
{
	cout << name << endl;
	for (auto &temp : data)
	{
		cout << temp.first << " " << temp.second << endl;
	}
	cout << endl;
}
void balance::vertical_column_input()
{
	unsigned int max = 0;
	for (auto &temp : data)
	{
		if (max < temp.second)
			max = temp.second;
	}
	double del = max / 50.0;
	cout << name << endl;
	for (int i = 50; i != 0; i--)
	{
		for (auto &in : data)
		{

			if ((i - in.second / del) <= 0)
			{
				cout << "X";
			}
			else
			{
				cout << " ";
			}
			cout << string(in.first.length(), ' ');
		}
		cout << endl;
	}
	for (auto &in : data)
	{
		cout << in.first << " ";
	}
	cout << endl;
}
void balance::horisontal_column_input()
{
	unsigned int max = 0;
	for (auto &temp : data)
	{
		if (max < temp.second)
			max = temp.second;
	}
	double del = max / 50.0;
	cout << name << endl;
	for (auto &temp : data)
	{
		cout << temp.first << " ";
		for (int i = temp.second / del; i != 0; i--)
		{
			cout << "X ";
		}
		cout << endl;
	}
}
void balance::push_back(string str, unsigned int unsitemp)
{
	data.push_back(make_pair(str, unsitemp));
}
void balance::one_to_many(Base_table* baseTemp)
{
	bool flag_first_table = false, flag_second_table = false;
	int test = 0;
	for (int i = 0; i < baseTemp->size(); i++)
	{
		for (auto &temp : data)
		{
			if (temp.first == baseTemp->operator[](i).first)
			{
				test++;
			}
		}
		if (test > 1)
		{
			flag_first_table = true;
			break;
		}
		test = 0;
	}
	test = 0;
	for (auto &temp : data)
	{
		for (int i = 0; i < baseTemp->size(); i++)
		{
			if (temp.first == baseTemp->operator[](i).first)
			{
				test++;
			}
		}
		if (test > 1)
		{
			flag_second_table = true;
			break;
		}
		test = 0;
	}
	if (flag_first_table == true && flag_second_table == false)
	{
		string temp_str;
		temp_str = "таблица один ( ";
		temp_str += baseTemp->get_name();
		temp_str += " ) ко многим ( ";
		temp_str += name;
		temp_str += " )\n";
		cout << temp_str;
		for (int i = 0; i < baseTemp->size(); i++)
		{
			for (auto &temp : data)
			{
				if (temp.first == baseTemp->operator[](i).first)
				{
					temp_str = temp.first;
					temp_str += " ";
					unsigned int untemp1 = baseTemp->operator[](i).second, untemp2 = temp.second;
					cout << temp_str << " " << untemp1 << " " << untemp2;
					cout << endl;

				}
			}
		}

	}
	if (flag_first_table == false && flag_second_table == true)
	{
		string temp_str;
		temp_str = "таблица один ( ";
		temp_str += name;
		temp_str += " ) ко многим ( ";
		temp_str += baseTemp->get_name();
		temp_str += " )\n";
		cout << temp_str;
		for (auto &temp : data)
		{
			for (int i = 0; i < baseTemp->size(); i++)
			{
				if (temp.first == baseTemp->operator[](i).first)
				{
					temp_str = temp.first;
					temp_str += " ";
					unsigned int untemp1 = baseTemp->operator[](i).second, untemp2 = temp.second;
					cout << temp_str << " " << untemp2 << " " << untemp1;
					cout << endl;

				}
			}
		}
	}
}
void balance::pop_back()
{
	if (!data.empty())
	{
		data.pop_back();
	}
}
void balance::insert(int n, string str, unsigned int unsitemp)
{
	if (n >= 0 && n < data.size())
	{
		auto beg = data.begin();
		for (int i = 0; i != n; i++)
			beg++;
		data.insert(beg, make_pair(str, unsitemp));
	}
}
void balance::erase(int n)
{
	if (n >= 0 && n < data.size())
	{
		auto beg = data.begin();
		for (int i = 0; i != n; i++)
			beg++;
		data.erase(beg);
	}
}