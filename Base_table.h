#ifndef BASE_TABLE
#define BASE_TABLE
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Base_table
{

protected:
	Base_table();
public:

	virtual ~Base_table();
	virtual void horisontal_input() = 0;
	virtual void vertical_input() = 0;
	virtual void horisontal_column_input() = 0;
	virtual void vertical_column_input() = 0;
	virtual pair<string, unsigned int> operator [] (int n) = 0;
	virtual void one_to_many(Base_table* baseTemp) = 0;
	virtual int size() = 0;
	virtual string get_name() = 0;
};

int lengt_unsint(unsigned int n);
#endif
