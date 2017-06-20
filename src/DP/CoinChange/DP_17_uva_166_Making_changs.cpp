#include "CommonHeader.h"


#ifdef DP_17_uva_166_Making_changs
READ_INPUT(DP_17_uva_166_Making_changs)


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
	int get_dp[50001] = {};
	int coins[] = { 0, 5, 10, 20, 50, 100, 200 };

	// calculate min coins to get this amount.
	get_dp[0] = 0;
	
	// check for each amount.
	FORI(i, 1, 20000)
	{
		if (i % 5 != 0)
			continue;
		
		int min_coin_needed = 0xffff;
		// count number of coin for each coin value.
		FORI(j, 1, 6)
		{
			// number of coins available to use.
			FORI(k, 1, (50000 / coins[j] + 1))
			{
				if (i - coins[j] * k < 0)
					break;
				if (get_dp[i - coins[j] * k] + k < min_coin_needed)
					min_coin_needed = get_dp[i - coins[j] * k] + k;

			}
		}
		get_dp[i] = min_coin_needed;
	}

	while (1)
	{
		int changes[7], a, b, sum = 0, to_pay;
		FORI(i, 1, 6) scanf("%d", &changes[i]), sum += changes[i] * coins[i];
		if (sum == 0)
			break;
		scanf("%d.%d", &a, &b);
		to_pay = a * 100 + b;

		int pay_dp[50000 + 1];
		FORI(i, 0, 50000) pay_dp[i] = 0xffff;
		pay_dp[0] = 0;

		// calculate the number of coins to reach that amount.
		FORI(i, 1, 6)
		{
			RFORI(j, sum, 1)
			{
				FORI(k, 1, changes[i])
				{
					if (j - coins[i] * k < 0)
						break;
					if(pay_dp[j] > (pay_dp[j - coins[i] * k] + k))
					pay_dp[j] = pay_dp[j - coins[i]*k] + k;
				}
			}
		}

		unsigned int ans = 0xffff;
		FORI(i, to_pay, sum)
		{
			if (ans <= pay_dp[i]) continue;
			if(ans > (pay_dp[i] + get_dp[i - to_pay]))
			ans = pay_dp[i] + get_dp[i - to_pay];
		}

		printf("%3d\n", ans);

	}

	return 0;
}

#endif
