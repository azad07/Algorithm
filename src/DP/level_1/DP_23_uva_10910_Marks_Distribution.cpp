#include "CommonHeader.h"


#ifdef DP_23_uva_10910_Marks_Distribution
READ_INPUT(DP_23_uva_10910_Marks_Distribution)


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

int ways(int t, int n, int p)
{
	if ( n == 0 && t >0)
		return 1;
	if (t < p || n < 0)
		return 0;

	return ways(t - p, n - 1, p) + ways(t - 1, n, p);
}

int main()
{
	int n, t, p, test_case;
	scanf("%d", &test_case);
	while (test_case--)
	{
		scanf("%d %d %d", &n, &t, &p);
		int ans = ways(t, n, p);
		printf("%d\n", ans);
	}

	return 0;
}


#endif
