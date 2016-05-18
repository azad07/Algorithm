#include "CommonHeader.h"


#ifdef DP_02_uva_10755_Garbage_Heap 
READ_INPUT(DP_02_uva_10755_Garbage_Heap)


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

ll mat[21][21][21];

int main()
{
	int t, A, B, C;
	cin >> t;
	while (t--)
	{
		cin >> A >> B >> C;
		FORI(i, 1, A) FORI(j, 1, B) FORI(k, 1, C)
		{
			// apply principle of inclusion-exclusion.
			cin >> mat[i][j][k];
			if (i > 1) mat[i][j][k] += mat[i-1][j][k];
			if (j > 1) mat[i][j][k] += mat[i][j - 1][k];
			if (k > 1) mat[i][j][k] += mat[i][j][k-1];
			if (i > 1 && j > 1) mat[i][j][k] -= mat[i - 1][j - 1][k];
			if (j > 1 && k > 1) mat[i][j][k] -= mat[i][j-1][k-1];
			if (i > 1 && k > 1) mat[i][j][k] -= mat[i-1][j][k-1];
			if (i > 1 && j > 1 && k > 1) mat[i][j][k] += mat[i-1][j-1][k-1];
		}

		// get max sum in cube.
		ll getMaxSum = INT_MIN;
		FORI(i, 1, A) FORI(j, 1, B) FORI(k, 1, C)
			FORI(l, i, A) FORI(m, j, B) FORI(n, k, C)
		{
			ll cube_sum = mat[l][m][n];
			if (i>1) cube_sum -= mat[i-1][m][n];
			if (j > 1) cube_sum -= mat[l][j - 1][n];
			if (k > 1) cube_sum -= mat[l][m][k - 1];
			if (i > 1 && j > 1) cube_sum += mat[i - 1][j - 1][n];
			if (i > 1 && k > 1) cube_sum += mat[i - 1][m][k - 1];
			if (j > 1 && k > 1) cube_sum += mat[l][j - 1][k - 1];
			if (i > 1 && j > 1 && k > 1) cube_sum -= mat[i - 1][j - 1][k - 1];
			getMaxSum = max(getMaxSum, cube_sum);
		}

		cout << getMaxSum <<endl;
		if (t > 0)
			cout << endl;

	}
	return 0;
}


#endif
