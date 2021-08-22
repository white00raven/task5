#include "Base_table.h"



Base_table::Base_table()
{
}


Base_table::~Base_table()
{
}
int lengt_unsint(unsigned int n)
{
	int i = 0;
	do
	{
		i++;
		n /= 10;
	} while (n != 0);
	return i;
}