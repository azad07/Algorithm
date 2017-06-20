#include "CommonHeader.h"


#ifdef ad_hoc_05_uva_661_Blowing_Fuses
READ_INPUT(ad_hoc_05_uva_661_Blowing_Fuses)

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

#define FORI(i,a,b) for(int i=(int)a; i<=(int)b; i++)
#define RFORI(i,a,b) for(int i=(int)a; i>=(int)b; i--)
using namespace std;

bool state[25];
int ci[25];
int main()
{
	int n, m, c;
	int maxP, maxPP, sw, seq = 0;
	bool fuse;
	while (1)
	{
		cin >> n >> m >> c;
		if (n == 0 && m == 0 && c == 0) 
			return 0;

		FORI(i, 1, n) cin >> ci[i], state[i] = false;

		maxPP = maxP = 0;
		fuse = false;

		FORI(i, 1, m)
		{
			cin >> sw;
			if (fuse) continue;

			if (state[sw])
			{
				if (maxP > 0) maxP -= ci[sw];
				state[sw] = false;
			}
			else
			{
				maxP += ci[sw];
				state[sw] = true;
			}
			maxPP = max(maxPP, maxP);
			if (maxP > c) fuse = true;

		}
		cout << "Sequence " << ++seq << endl;
		if (fuse)
			cout << "Fuse was blown." << endl<< endl;
		else
		{
			cout << "Fuse was not blown." << endl;
			cout << "Maximal power consumption was " << maxPP << " amperes."<<endl << endl;
		}
	}
	return 0;
}

#endif
