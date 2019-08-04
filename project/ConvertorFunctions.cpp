#include "ConverterFunctions.h"

int str_to_int(string str){
	int ans = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		ans *= 10;
		ans += (str[i] - '0');
	}
	return ans;
}