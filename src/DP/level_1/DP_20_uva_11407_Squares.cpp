#include "CommonHeader.h"


#ifdef DP_20_uva_11407_Squares
READ_INPUT(DP_20_uva_11407_Squares)


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
	int dp[10001] = {}, N, num;
	
	FORI(i, 1, 10000) dp[i] = 0xffff;
	dp[0] = 0;
	
	/* just apply coin change approach here....
	*
	*		F(i) = 1 + MIN { F(i - j²) , ? j² <= i }
	*
	*/

	FORI(i, 1, 100) FORI(j, (i*i), 10000)
		dp[j] = min(dp[j], dp[j-(i*i)] + 1);

	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &num);
		printf("%d\n", dp[num]);
	}

	return 0;
}


#endif
