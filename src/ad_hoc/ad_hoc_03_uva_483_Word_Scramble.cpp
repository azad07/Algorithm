#include "CommonHeader.h"


#ifdef AD_HOC_03_UVA_WORD_SCRAMBLE
READ_INPUT(AD_HOC_03_UVA_WORD_SCRAMBLE)

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

#define FORI(i,a,b) for(int i=(int)a; i<=(int)b; i++)
#define RFORI(i,a,b) for(int i=(int)a; i>=(int)b; i--)
using namespace std;

int main()
{
	string line;
	while (getline(cin, line))
	{
		int len = line.length();
		int st = 0, end = 0;
		FORI(i, 0, len - 1)
		{
			if (line[i] == ' ')
			{
				end = i-1;
				RFORI(j, end, st)
					cout << line[j];
				cout << " ";
				st = i + 1;
			}
		}
		end = len - 1;
		RFORI(j, end, st)
			cout << line[j];
		cout << endl;
	}
	
	return 0;
}

#endif
