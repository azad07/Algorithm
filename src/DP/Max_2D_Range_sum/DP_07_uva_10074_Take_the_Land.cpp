#include "CommonHeader.h"


#ifdef DP_07_uva_10074_Take_the_Land
READ_INPUT(DP_07_uva_10074_Take_the_Land)


#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <math.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<float, float> ff;
typedef vector<int> vi;
typedef vector<float> vf;
typedef vector<ii> vii;
typedef vector<ff> vff;
typedef vi::iterator vi_itr;
typedef vf::iterator vf_itr;
typedef vii::iterator vii_itr;
typedef vff::iterator vff_itr;
typedef set<int>   si;
typedef map<string, int> msi;

#define FORI(i,a,b) for(int i=(int)a; i<=(int)b; i++)
#define RFORI(i,a,b) for(int i=(int)a; i>=(int)b; i--)
#define TRvii(c, it) for(vii::iterator it = (c).begin(); it != (c).end(); ++it) 
#define INT_MIN     (-2147483647 - 1) 
#define INT_MAX       2147483647
#define WHITE	-1
#define BLACK	2
#define GREEN	3
#define RED		4
#define DEBUG	0

int sum[105][105];

int main()
{
	int r, c;
	while (scanf("%d %d", &r, &c) >= 0 && r>0 && c>0)
	{
		FORI(i, 1, r) FORI(j, 1, c)
		{
			cin >> sum[i][j], sum[i][j] = !sum[i][j];
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}

		int max_land = 0;
		FORI(i, 1, r) FORI(j, 1, c)
			FORI(l, i, r) FORI(m, j, c)
				{
					int tmp = sum[l][m] - sum[i - 1][m] - sum[l][j - 1] + sum[i - 1][j - 1];
					if (tmp == (l - i + 1)*(m - j + 1))
						max_land = max(max_land, tmp);
				}
		cout << max_land << endl;
	}
	
	return 0;
}



#endif
