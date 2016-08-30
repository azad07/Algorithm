#include "CommonHeader.h"


#ifdef DP_27_uva_10036_Divisibility
READ_INPUT(DP_27_uva_10036_Divisibility)


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

int arr[10001];
int dp[10001][201][3]; //[numbers][sum][sign]

bool isDivisible(int len, int sign, int sum, int divisibleWith)
{

}


int main()
{
	int t, n, d;
	scanf("%d", &t);
	FORI(i, 1, t)
	{
		scanf("%d %d", &n, &d);
		FORI(i, 1, n) scanf("%d", &arr[i]);

		if(isDivisible(n, ))

	}

	return 0;
}


#endif
