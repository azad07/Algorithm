#include "CommonHeader.h"


#ifdef DP_25_uva_10003_Cutting_Sticks
READ_INPUT(DP_25_uva_10003_Cutting_Sticks)


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

int dp[51][51];

int main()
{
	int l, n, a[52] = {};
	
	while (scanf("%d", &l) == 1 && l != 0)
	{
		scanf("%d", &n);
		FORI(i, 1, n) scanf("%d", &a[i]);
		a[n + 1] = l;

		// F(left, right) = Min{ F(left, i) + F(i, right) + (cost[j]-cost[i]) } ∀ i ∈ [left+1 ... right-1]
		FORI(i, 1, n) dp[i-1][i] = 0;

		RFORI(i, n+1, 0) FORI(j, i+1, n+1)
		{
			if( j- i > 1) dp[i][j] = 0xffff;
			FORI(k, i+1, j-1)
			{
				dp[i][j] = min(dp[i][j], (dp[i][k] + dp[k][j] + (a[j] - a[i])));
			}
		}

		printf("The minimum cutting is %d.\n", dp[0][n + 1]);
	}

	return 0;
}


#endif
