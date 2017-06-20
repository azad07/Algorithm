#include "CommonHeader.h"


#ifdef DP_33_uva_00481_What_goes_up
READ_INPUT(DP_33_uva_00481_What_goes_up)


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

long long arr[100001], LIS[100001];
long long arr_p[100001], LIS_p[100001], l2r[100001];
long long N, lis_size = 0;

long long find_in_lis(long long val, long long st, long long end)
{
	long long mid = (st + end) / 2;
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
	N = 0;
	while (scanf("%d", &arr[++N]) == 1) {}
	N--;

	// increasing.
	memset(LIS, 0, sizeof(LIS));
	lis_size = 0;
	LIS[++lis_size] = arr[1];
	LIS_p[1] = 1;
	l2r[1] = 1;
	FORI(i, 2, N)
	{
		if (LIS[lis_size] < arr[i])
		{
			arr_p[i] = LIS_p[lis_size];
			LIS[++lis_size] = arr[i];
			l2r[i] = lis_size;
			LIS_p[lis_size] = i;
		}
		else
		{
			int get_ind = find_in_lis(arr[i], 1, lis_size);
			arr_p[i] = LIS_p[get_ind-1];
			LIS[get_ind] = arr[i];
			LIS_p[get_ind] = i;
			l2r[i] = get_ind;
		}
	}

	printf("%d\n", lis_size);
	printf("-\n");

	long long ind = 0, max_num = INT_MIN;
	FORI(i, 1, N)
	{
		if (l2r[i] == lis_size)
		{
			if (arr[i] >= max_num)
			{
				max_num = arr[i];
				ind = i;
			}
		}
	}


	long long  i = lis_size;
	long long ll[100001];
	while (ind > 0)
	{
		///printf("%d\n", arr[ind]);
		ll[i--] = arr[ind];
		ind = arr_p[ind];
	}

	FORI(i, 1, lis_size)
	{
		printf("%d\n", ll[i]);
	}
	return 0;
}


#endif
