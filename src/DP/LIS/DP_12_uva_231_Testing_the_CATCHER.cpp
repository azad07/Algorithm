#include "CommonHeader.h"


#ifdef DP_12_uva_231_Testing_the_CATCHER
READ_INPUT(DP_12_uva_231_Testing_the_CATCHER)


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

int arr[1024];
int LIS[1024];

int main()
{
	int i = 0, test_case = 0;

	while (1)
	{
		// get the input.
		while (scanf("%d", &arr[++i]) >= 0 && arr[i] != -1) { LIS[i] = 1; } i--;

		int lis_max = 0;
		FORI(m, 1, i) FORI(n, 1, m - 1) if (arr[m] <= arr[n]) LIS[m] = max(LIS[m], LIS[n] + 1);

		FORI(m, 1, i) lis_max = max(lis_max, LIS[m]);
		
		printf("Test #%d:\n", ++test_case);
		printf("  maximum possible interceptions: %d\n", lis_max);

		i = 1;
		scanf("%d", &arr[i]);
		if (arr[1] == -1)
			break;
		printf("\n");
	}

	return 0;
}

#endif
