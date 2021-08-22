#ifndef SALES_VOLUME
#define SALES_VOLUME
#include "Base_table.h"
class sales_volume : public Base_table
{
private:
	string name;
	vector<pair<string, unsigned int>> data;
public:
	virtual void horisontal_input() override;
	virtual void vertical_input() override;
	virtual void horisontal_column_input() override;
	virtual void vertical_column_input() override;
	void push_back(const string &str, unsigned int sitemp);
	void pop_back();
	void insert(int n, const string& str, unsigned int sitemp);
	void erase(int n);
	void one_to_many(Base_table* baseTemp) override;
	pair<string, unsigned int> operator [](int n) override
	{
		if (n >= 0 && n < data.size())
			return data[n];
		else
			return make_pair("", 0);
	};
	void operator = (const sales_volume & sltemp)
	{
		name = sltemp.name;
		data = sltemp.data;
	};
	int size() override { return data.size(); };
	string get_name() override { return name; }
	sales_volume();
	sales_volume(const sales_volume & sltemp);
	sales_volume(const string& str);
	virtual ~sales_volume();
};
#endif
