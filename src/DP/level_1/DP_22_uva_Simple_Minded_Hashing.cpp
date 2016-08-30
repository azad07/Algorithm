#include "CommonHeader.h"


#ifdef DP_22_uva_Simple_Minded_Hashing
READ_INPUT(DP_22_uva_Simple_Minded_Hashing)


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

int memo[27][352][27];


//apply take, dont-take approach to count ways.
int ways(int ch, int sum, int len)
{
	if (sum == 0 && len == 0)
		return 1;
	if (sum < 0 | len < 0 | ch <= 0)
		return 0;
	if (memo[ch][sum][len] > -1)
		return memo[ch][sum][len];

	return memo[ch][sum][len] = ways(ch - 1, sum - ch, len - 1) + ways(ch - 1, sum, len);
}

int main()
{
	int l, s, t = 0;
	while (scanf("%d %d", &l, &s) == 2)
	{
		if (l == 0 && s == 0) break;
		memset(memo, -1, sizeof(memo));
		int ans;
		if (l > 26 || s > 351)
			ans = 0;
		else
			ans = ways(26, s,l);
		t++;
		printf("Case %d: %d\n", t, ans);

	}

	return 0;
}


#endif
