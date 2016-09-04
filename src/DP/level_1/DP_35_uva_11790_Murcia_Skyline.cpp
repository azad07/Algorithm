#include "CommonHeader.h"


#ifdef DP_35_uva_11790_Murcia_Skyline
READ_INPUT(DP_35_uva_11790_Murcia_Skyline)


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

int h[10001], w[10001], LIS[10001], LDS[10001];


int main()
{
	int t, n;
	cin >> t;
	FORI(test_case, 1, t)
	{
		cin >> n;
		FORI(i, 1, n) cin >> h[i];
		FORI(i, 1, n) cin >> w[i], LIS[i] = LDS[i] = w[i];

		FORI(i, 1, n) FORI(j, i + 1, n)
		{
			if (h[i] < h[j])
				LIS[j] = max(LIS[j], LIS[i] + w[j]);
			if (h[i] > h[j])
				LDS[j] = max(LDS[j], LDS[i] + w[j]);
		}

		int lis_m = 0, lds_m = 0;
		FORI(i, 1, n)
		{
			lis_m = max(lis_m, LIS[i]);
			lds_m = max(lds_m, LDS[i]);
		}
		//Case 1. Increasing (85). Decreasing (50). 
		if (lis_m >= lds_m)
			cout << "Case " << test_case << ". Increasing (" << lis_m << "). Decreasing (" << lds_m << ")." << endl;
		else
			cout << "Case " << test_case << ". Decreasing (" << lds_m << "). Increasing (" << lis_m << ")." << endl;
	}
	return 0;
}


#endif
