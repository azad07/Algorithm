#include "CommonHeader.h"


#ifdef DP_04_uva_108_Maximum_Sum
READ_INPUT(DP_04_uva_108_Maximum_Sum)


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

int sumMat[1024][1024];

int main()
{
	int N;
	cin >> N;
	FORI(i, 1, N) FORI(j, 1, N) cin >> sumMat[i][j], sumMat[i][j] += sumMat[i - 1][j] + sumMat[i][j - 1] - sumMat[i - 1][j - 1];

	int maxSum = 0;
	FORI(i, 1, N) FORI(j, 1, N)
	{
		FORI(l, i, N) FORI(m, j, N)
		{
			int sub_mat_sum = sumMat[l][m] - sumMat[i - 1][m] - sumMat[l][j - 1] + sumMat[i - 1][j - 1];
			maxSum = max(maxSum, sub_mat_sum);
		}
	}
	cout << maxSum << endl;
	return 0;
}

#endif
