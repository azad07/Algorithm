#include "CommonHeader.h"


#ifdef DP_38_uva_01231_acorn
READ_INPUT(DP_38_uva_01231_acorn)


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

int forest[2001][2001], memo[2001][2001];
int level[2001];

void printmat(int t, int h)
{
#if DEBUG
	cout << endl;
	FORI(i, 0, h)
	{
		FORI(j, 1, t) cout << memo[i][j] << "  ";
		cout << endl;
	}
#endif
}

int main()
{
	int n, t, h, f, acorn, pos;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d %d %d", &t, &h, &f);
		memset(forest, 0, sizeof(forest));
		memset(memo, 0, sizeof(memo));
		memset(level, 0, sizeof(level));
		FORI(i, 1, t)
		{
			scanf("%d", &acorn);
			FORI(j, 1, acorn) scanf("%d", &pos), forest[pos][i]++;
		}
		printmat(t, h);
		FORI(i, 1, t) memo[h][i] = forest[h][i];
		RFORI(i, h, 1)
		{
			int max_acorn = 0, ind = 0, count = 0;
			FORI(j, 1, t) max_acorn = max(max_acorn, memo[i][j]);
			FORI(j, 1, t) if (memo[i][j] == max_acorn) ind = j, count++;

			FORI(j, 1, t)
			{
				if (memo[i][j] != 0)
					memo[i - 1][j] = max(memo[i - 1][j], forest[i - 1][j] + memo[i][j]);
				else
					memo[i-1][j] = forest[i-1][j];

				if (i - f >= 0)
				{
					if (j == ind && count == 1)
						continue;
					else
						memo[i - f][j] = max(memo[i - f][j], forest[i - f][j] + max_acorn);
				}
			}

			printmat(t, h);
		}

		int ans = 0;
		FORI(i, 1, t) ans = max(ans, memo[0][i]);
		
		printf("%d\n", ans);

	}

	return 0;
}


#endif
