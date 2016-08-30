#include "CommonHeader.h"


#ifdef DP_18_uva_357_Let_Me_Count_The_Ways
READ_INPUT(DP_18_uva_357_Let_Me_Count_The_Ways)


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
	int coins[] = {0, 1, 5, 10, 25, 50};
	unsigned long long dp[30001] = {};
	dp[0] = 1;

	FORI(i, 1, 5) FORI(j, coins[i], 30000)
		dp[j] += dp[j - coins[i]];

	int a;
	while (scanf("%d", &a) == 1)
	{
		if (dp[a] == 1)
			printf("There is only 1 way to produce %d cents change.\n", a);
		else
			cout << "There are " << dp[a] << " ways to produce " << a << " cents change." << endl;
	}

	return 0;
}

#endif
