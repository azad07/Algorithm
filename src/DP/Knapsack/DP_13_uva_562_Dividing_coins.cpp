#include "CommonHeader.h"


#ifdef DP_13_uva_562_Dividing_coins
READ_INPUT(DP_13_uva_562_Dividing_coins)


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

int coins[101];
int dp[50000+10][101];  // [amount][coin];

int main()
{
	int t, N;
	cin >> t;
	FORI(test_case, 1, t)
	{
		cin >> N;
		int sum = 0, target = 0;
		FORI(i, 1, N) cin >> coins[i], sum += coins[i];
		target = sum / 2;
		FORI(i, 1, target) dp[i][0] = 0;

		FORI(coin, 1, N) FORI(amount, 1, target)
		{
			if (coins[coin] <= amount)
			{
				dp[amount][coin] = max(dp[amount][coin - 1], (dp[amount - coins[coin]][coin - 1] + coins[coin]));
			}
			else
				dp[amount][coin] = dp[amount][coin - 1];
		}
		cout << sum - 2 * dp[target][N] << endl;
	}
	return 0;
}

#endif
