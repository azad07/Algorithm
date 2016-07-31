#include "CommonHeader.h"


#ifdef DP_15_uva_10130_SuperSale
READ_INPUT(DP_15_uva_10130_SuperSale)


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

int main()
{
	int t;
	cin >> t;
	FORI(test_case, 1, t)
	{
		int N, p, w;
		int dp[31] = {};
		cin >> N;
		FORI(i, 1, N)
		{
			cin >> p >> w;
			// implement bottom up dp approach for knapsack.
			RFORI(j, 30, w)
			{
				if (dp[j] < dp[j - w] + p)
					dp[j] = dp[j - w] + p;
			}
		}
		int G, Mw, ans = 0;
		cin >> G;
		FORI(i, 1, G) cin >> Mw, ans += dp[Mw];
		cout << ans << endl;
	}
	return 0;
}

#endif
