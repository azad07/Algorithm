#include "CommonHeader.h"


#ifdef DP_29_uva_00437_The_Tower_of_Babylon
READ_INPUT(DP_29_uva_00437_The_Tower_of_Babylon)


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

typedef struct _Blk
{
	int w, b, h;
}Blk;

Blk blk[30 * 6 + 1];

void sort(int n)
{
	FORI(i, 1, n)
	{
		int tmp = i;
		FORI(j, i + 1, n)
		{
			if(blk[tmp].b*blk[tmp].w < blk[j].b*blk[j].w)
				tmp = j;
		}
		if (tmp != i)
		{
			Blk swp = blk[i];
			blk[i] = blk[tmp];
			blk[tmp] = swp;			
		}
	}
}

int main()
{
	int blocks, a, b, c, total, test_case = 0;
	while (scanf("%d", &blocks) == 1 && blocks)
	{
		total = 0;
		FORI(i, 1, blocks)
		{
			scanf("%d %d %d", &a, &b, &c);
			blk[++total] = { a, b, c };
			blk[++total] = { b, c, a };
			blk[++total] = { c, a, b };
			blk[++total] = { b, a, c };
			blk[++total] = { c, b, a };
			blk[++total] = { a, c, b };
		}

		sort(total);
		
		int dp[30 * 6 + 1] = {};

		// apply LIS
		// LIS(i) = Max { LIS(j) +1} ∀ j∈( j<i)
		
		FORI(i, 1, total)
		{
			dp[i] = blk[i].h;
			FORI(j, 1, i-1)
			{
				if(blk[i].w < blk[j].w && blk[i].b < blk[j].b)
				{ 
					dp[i] = max(dp[i], (dp[j] + blk[i].h));
				}
			}
		}

		int max_height = 0;
		FORI(i, 1, total) max_height = max(max_height, dp[i]);

		printf("Case %d: maximum height = %d\n", ++test_case, max_height);
	}

	return 0;
}


#endif
