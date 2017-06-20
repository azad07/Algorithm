#include "CommonHeader.h"


#ifdef DP_26_uva_10465_Homer_Simpson
READ_INPUT(DP_26_uva_10465_Homer_Simpson)


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

int dp[10001];

int main()
{
	int m, n, t;
	while (scanf("%d %d %d", &m, &n, &t) == 3)
	{
		FORI(i, 1, t) dp[i] = -1;

		/*
		 *    apply single DP approach.
		 *	  F(i) = 1 + Max{F(i-m), F(i-n)} ∀ i ∈ i<t
		 */
		FORI(i, 0, t)
		{
			if (dp[i] == -1) continue;
			if(i+m <= t)	dp[i + m] = max(dp[i + m], (dp[i] + 1));
			if(i+n <= t)    dp[i + n] = max(dp[i + n], (dp[i] + 1));
		}

		int burger_eaten = dp[t];
		int beer = 0;

		RFORI(i, t, 1)
		{
			burger_eaten = dp[i];
			if (dp[i] != -1)
				break;
			beer++;
		}
		if (burger_eaten == -1)
			burger_eaten = 0;

		if (beer)
			printf("%d %d\n", burger_eaten, beer);
		else
			printf("%d\n", burger_eaten);

	}

	return 0;
}


#endif
