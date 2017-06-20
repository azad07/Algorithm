#include "CommonHeader.h"


#ifdef DP_31_uva_10364_Square
READ_INPUT(DP_31_uva_10364_Square)


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

int sticks[21];
int n, t, sum;
int dp[1 << 21];

bool possible(int len, int mask)
{
	if (len > sum / 4)
		return false;
	if (dp[mask] != -1)
		return dp[mask];

	if (len == sum / 4)
	{
		if (mask == ((1 << (n + 1)) - 2))
			return true;
		len = 0;
	}

	FORI(i, 1, n)
	{
		if (!(mask & (1 << i)))
		{
			if (possible(len + sticks[i], mask | (1 << i)))
				return true;
		}
	}

	return dp[mask] = false;
}


int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		sum = 0;
		FORI(i, 1, n) scanf("%d", &sticks[i]), sum+=sticks[i];

		if (sum % 4 != 0)
		{
			printf("no\n");
			continue;
		}
		
		memset(dp, -1, sizeof(dp));

		if (possible(0, 0))
			printf("yes\n");
		else
			printf("no\n");

	}
	return 0;
}


#endif
