#include "sales_volume.h"
#include "balance.h"
#include <fstream>
void main()
{
	sales_volume sal_vol;
	balance bal;
	setlocale(LC_ALL, "Russian");
	fstream file("file.txt");
	if (file.is_open())
	{

		int n = 0;
		string temp;
		file >> n;
		getline(file, temp);
		for (int i = 0; i < n; i++)
		{
			string str;
			unsigned int unsitemp;
			getline(file, str);
			file >> unsitemp;
			sal_vol.push_back(str, unsitemp);
			getline(file, temp);
		}
		file >> n;
		getline(file, temp);
		for (int i = 0; i < n; i++)
		{
			string str;
			unsigned int unsitemp;
			getline(file, str);
			file >> unsitemp;
			bal.push_back(str, unsitemp);
			getline(file, temp);
		}
		sal_vol.horisontal_column_input();
		sal_vol.horisontal_input();
		sal_vol.vertical_column_input();
		sal_vol.vertical_input();
		sal_vol.one_to_many(&bal);
	}
	file.close();
}