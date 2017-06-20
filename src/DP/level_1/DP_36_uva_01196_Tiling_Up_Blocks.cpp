#include "CommonHeader.h"


#ifdef DP_36_uva_01196_Tiling_Up_Blocks
READ_INPUT(DP_36_uva_01196_Tiling_Up_Blocks)


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
	int n, l, m;
	while (scanf("%d", &n) == 1 && n)
	{
		int dp[101][101] = {}, tiles[101][101] = {};
		
		FORI(i, 1, n) scanf("%d %d", &l, &m), tiles[l][m]++;

		FORI(i, 1, 100) FORI(j, 1, 100)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			dp[i][j] += tiles[i][j];
		}
		printf("%d\n", dp[100][100]);
	}

	// this is critical, don't use printf("*") here, it will give wrong answer.
	puts("*");

	return 0;
}


#endif
