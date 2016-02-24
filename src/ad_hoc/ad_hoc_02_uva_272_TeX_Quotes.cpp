#include "CommonHeader.h"


#ifdef AD_HOC_02_UVA_272_TEX_QUOTES
READ_INPUT(AD_HOC_02_UVA_272_TEX_QUOTES)

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	char ch;
	bool quote_first = true;
	while (scanf("%c", &ch) >= 0)
	{
		
		if (ch == '"')
		{
			if (quote_first)
			{
				cout << "``";
				quote_first = false;
			}
			else
			{
				cout << "''";
				quote_first = true;
			}
		}
		else
			cout << ch;
	}
	return 0;
}

#endif
