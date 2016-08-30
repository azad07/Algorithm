#include "CommonHeader.h"


#ifdef DP_30_uva_10616_Divisible_Group_Sums
READ_INPUT(DP_30_uva_10616_Divisible_Group_Sums)


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

int dp[201][11][41]; //[n][m][d]
int arr[201];

int solve(int n, int m, int d)
{
	if (n == 0 && m == 0 && d == 0) return 1;
	//if (m == 1 && n%d == 0) return 1;
	if (n <= 0) return 0;
	if (m <= 0) return 0;
	if (dp[n][m][d] > -1) return dp[n][m][d];

	int ways = 0;
	ways = solve(n - 1, m, d);
	FORI(i, 0, d)
	{
		if ((arr[n] + i) % d == 0)
			ways += solve(n - 1, m - 1, i);
	}

	dp[n][m][d] = ways;
	return dp[n][m][d];
}


int main()
{
	int n, m, d, q, test_case = 0;
	while (scanf("%d %d", &n, &q) == 2)
	{
		if (n + q == 0) break;

		FORI(i, 1, n) scanf("%d", &arr[i]);

		printf("SET %d:\n", ++test_case);
		FORI(i, 1, q)
		{
			scanf("%d %d", &d, &m);
			memset(dp, -1, sizeof(dp));
			int ans = solve(n, m, d);
			printf("QUERY %d: %d\n", i, ans);
		}


	}
	return 0;
}


#endif
