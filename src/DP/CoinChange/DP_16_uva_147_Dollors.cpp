#include "CommonHeader.h"


#ifdef DP_16_uva_147_Dollors
READ_INPUT(DP_16_uva_147_Dollors)


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
	unsigned long long  dp[30000 + 1] = {};
	// order doesn't matter.
	int coins[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
	float amount;

	dp[0] = 1;

	// coin change approach to count number of ways.
	FORI(i, 0, 10) FORI(j, coins[i], 30000)
		dp[j] += dp[j - coins[i]];

	while (scanf("%f", &amount)  == 1 && amount != 0.00)
	{
		int ind = (int)(amount * 10000)/100;
		printf("%6.2f %16llu\n", amount,  dp[ind]);
	}

	return 0;
}

#endif
