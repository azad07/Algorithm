#include "CommonHeader.h"


#ifdef DP_32_uva_10534_Wavio_Sequence
READ_INPUT(DP_32_uva_10534_Wavio_Sequence)


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

int arr[10001], LIS[10001];
int l2r[10001], r2l[10001];
int N, lis_size = 0;

int find_in_lis(int val, int st, int end)
{
	int mid = (st + end) / 2;
	if (LIS[mid] == val)
		return mid;
	if (end - st <= 1)
	{
		if (LIS[st] >= val)
			return st;
		else
			return end;
	}
	if (LIS[mid] >= val)
		return find_in_lis(val, st, mid);
	return find_in_lis(val, mid, end);
}

// apply Klog(n) LIS solution.
int main()
{
	while (scanf("%d", &N) == 1)
	{
		FORI(i, 1, N) scanf("%d", &arr[i]);

		// increasing.
		memset(LIS, 0, sizeof(LIS));
		lis_size = 0;
		LIS[++lis_size] = arr[1];
		l2r[1] = 1;
		FORI(i, 2, N)
		{
			if (LIS[lis_size] < arr[i])
			{
				LIS[++lis_size] = arr[i];
				l2r[i] = lis_size;
			}
			else
			{
				int get_ind = find_in_lis(arr[i], 1, lis_size);
				LIS[get_ind] = arr[i];
				l2r[i] = get_ind;
			}
		}

		// decreasing.
		memset(LIS, 0, sizeof(LIS));
		lis_size = 0;
		LIS[++lis_size] = arr[N];
		r2l[N] = 1;
		RFORI(i, N-1, 1)
		{
			if (LIS[lis_size] < arr[i])
			{
				LIS[++lis_size] = arr[i];
				r2l[i] = lis_size;
			}
			else
			{
				int get_ind = find_in_lis(arr[i], 1, lis_size);
				LIS[get_ind] = arr[i];
				r2l[i] = get_ind;
			}
		}

		int ans = 0;
		FORI(i, 1, N)
		{
			ans = max(ans, (2 * min(l2r[i], r2l[i]) - 1));
		}

		printf("%d\n", ans);
	}
	return 0;
}


#endif
