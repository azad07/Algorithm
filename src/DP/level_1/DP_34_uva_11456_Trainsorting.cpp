#include "CommonHeader.h"


#ifdef DP_34_uva_11456_Trainsorting
READ_INPUT(DP_34_uva_11456_Trainsorting)


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

int arr[2001], LIS[2001], LDS[2001];


int main()
{
	int t, n;
	cin >> t;
	FORI(test_case, 1, t)
	{
		cin >> n;

		// get the array in reverse order.
		FORI(i, 1, n) cin >> arr[n-i+1], LIS[i] = LDS[i] = 1;
		
		//Max { LIS(i) + LDS(i) -1} ∀ i ∈ [1..n]
		FORI(i, 1, n) FORI(j, i + 1, n)
		{
			if (arr[i] <= arr[j])
				LIS[j] = max(LIS[j], LIS[i] + 1);
			if (arr[i] >= arr[j])
				LDS[j] = max(LDS[j], LDS[i] + 1);
		}
		int ans = 0;
		FORI(i, 1, n)
			ans = max(ans, LIS[i] + LDS[i] - 1);
		cout << ans << endl;

	}
	return 0;
}


#endif
