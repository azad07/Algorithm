#include "CommonHeader.h"


#ifdef DP_14_uva_990_Diving_for_gold
READ_INPUT(DP_14_uva_990_Diving_for_gold)


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

int depth[31];
int gold[31];
int t, w, N;

int memo[31][1001]; //[id][rem_time];

int getMaxGold(int id, int rem_time)
{
	if (id > N)
		return 0;
	if (memo[id][rem_time] > 0)
		return memo[id][rem_time];

	int take = 0, dont_take = 0;

	if (3 * w*depth[id] > rem_time)
		dont_take =  getMaxGold(id+1, rem_time);
	else
	{
		take = getMaxGold(id + 1, rem_time - (3 * w*depth[id])) + gold[id];
		dont_take = getMaxGold(id + 1, rem_time);
	}

	memo[id][rem_time] = max(take, dont_take);
	
	return memo[id][rem_time];
}

int main()
{
	bool first = true;
	while (scanf("%d %d", &t, &w) == 2)
	{
		scanf("%d", &N);
		FORI(i, 1, N) scanf("%d %d", &depth[i], &gold[i]);

		memset(memo, 0, sizeof(memo));

		int total_gold = getMaxGold(1, t);

		if (!first)
		{	
			printf("\n");
		}
		first = false;

		printf("%d\n", total_gold);

		//just looking at memo table, we can reverse engineering the selection path.
		int dive[31] = {};
		for (int id = 1, time = t; id<=N; id++)
		{
			dive[id] = ((memo[id+1][time-3*w*depth[id]] + gold[id]) == memo[id][time]) ? 1 : -1;
			if (dive[id] == 1)
			{
				time -= 3 * w*depth[id];
			}
		}
	
		int dive_count = 0;
		FORI(i, 1, N)
		{
			if (dive[i] == 1) 
				dive_count++;
		}
		printf("%d\n", dive_count);
		FORI(i, 1, N)
		{
			if (dive[i]  == 1)
			{
				printf("%d %d\n", depth[i], gold[i]);
			}
		}
	}
	return 0;
}

#endif
