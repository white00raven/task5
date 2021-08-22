#ifndef BALANCE
#define BALANCE
#include "Base_table.h"
class balance :
	public Base_table
{
private:
	string name;
	vector<pair<string, unsigned int>> data;
public:
	virtual void horisontal_input() override;
	virtual void vertical_input() override;
	virtual void horisontal_column_input() override;
	virtual void vertical_column_input() override;
	void push_back(string str, unsigned int sitemp);
	void pop_back();
	void insert(int n, string str, unsigned int sitemp);
	void erase(int n);
	void one_to_many(Base_table* baseTemp) override;
	pair<string, unsigned int> operator [](int n) override
	{
		if (n >= 0 && n < data.size())
			return data[n];
		else
			return make_pair("", 0);
	};
	void operator = (const balance & sltemp)
	{
		name = sltemp.name;
		data = sltemp.data;
	};
	int size() override { return data.size(); };
	string get_name() override { return name; }
	balance();
	balance(const balance& sltemp);
	balance(string str);
	virtual ~balance();
};
#endif

