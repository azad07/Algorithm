#include "CommonHeader.h"


#ifdef DP_39_uva_10271_Chopsticks
READ_INPUT(DP_39_uva_10271_Chopsticks)


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

int DP[1010][5001];
int L[5001];

int minBadness(int k, int n)
{
	if (DP[k][n] != -1)
		return DP[k][n];
	if (n < 3 * k)
		DP[k][n] = INT_MAX;
	else if (k == 0)
		DP[k][n] = 0;
	else
		DP[k][n] = min(minBadness(k, n - 1), minBadness(k - 1, n - 2) + ((L[n] - L[n - 1])*(L[n] - L[n - 1])));
	return DP[k][n];
}

int main() {
	int t, n, k, i, j;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &k, &n);
		for (i = 1; i <= n; i++)
			scanf("%d", &L[n - i + 1]);
		k += 8;
		memset(DP, -1, sizeof(DP));
		int ans = minBadness(k, n);
		printf("%d\n", ans);
	}
	return 0;
}

#endif
