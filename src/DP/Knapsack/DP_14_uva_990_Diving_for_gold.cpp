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
int dive[31];

int getMaxGold(int id, int rem_time)
{
	if (id > N)
		return 0;
	if (memo[id][rem_time] > -1)
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
	
	while (scanf("%d %d\n", &t, &w) >= 0)
	{
		scanf("%d\n", &N);
		FORI(i, 1, N) scanf("%d %d\n", &depth[i], &gold[i]);

		memset(memo, -1, sizeof(memo));
		memset(dive, -1, sizeof(dive));

		int total_gold = getMaxGold(1, t);

		printf("%d", total_gold);

	}
	return 0;
}

#endif
