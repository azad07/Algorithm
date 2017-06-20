#include "CommonHeader.h"


#ifdef DP_24_uva_11026_A_Grouping_Problem
READ_INPUT(DP_24_uva_11026_A_Grouping_Problem)


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

long long dp[1001][1001];

int main()
{
	int n, m, arr[1001] = {};
	while (scanf("%d %d", &n, &m) == 2)
	{
		if (n + m == 0) break;

		FORI(i, 1, n) scanf("%d", &arr[i]);

		/* apply pascal triangles approach to compute all combination.
		 *		
		 *						1
		 *					1		1
		 *				1		2		1
		 *		   1		3		3		1
		 *		1		4		6		4		
		 *
		 *	 F(n, r) = F(n-1, r-1) +  F(n-1, r)
		 *  it's same take and don't-take approach.
		 *
		 */

		FORI(i, 0, n) dp[i][0] = 1;

		FORI(i, 1, n) FORI(j, 1, i)
			dp[i][j] = (dp[i - 1][j] + dp[i-1][j-1] * arr[i]) % m;

		int ans = 0;
		FORI(i, 1, n)
			ans = max(ans, dp[n][i]);

		printf("%d\n", ans);

	}

	return 0;
}


#endif
