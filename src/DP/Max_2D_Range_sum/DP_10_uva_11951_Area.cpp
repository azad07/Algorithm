#include "CommonHeader.h"


#ifdef DP_10_uva_11951_Area
READ_INPUT(DP_10_uva_11951_Area)


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

long long mat[110][110];

int main()
{
	int t, N, M, K;
	cin >> t;
	FORI(test_case, 1, t)
	{
		cin >> N >> M >> K;
		memset(mat, 0, sizeof(mat));

		// get the input and make cumulative sum matrix.
		FORI(i, 1, N) FORI(j, 1, M) cin >> mat[i][j], mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];

		long long max_cost = 0 ;
		int max_area = 0;
		// apply max 2D sum algo..
		FORI(i, 1, N) FORI(j, 1, M)
			FORI(x, i, N) FORI(y, j, M)
				{
					long long tmp = mat[x][y] - mat[i - 1][y] - mat[x][j - 1] + mat[i - 1][j - 1];
					int area = ((x - i + 1)*(y - j + 1));
					if (area >= max_area && tmp <= K)
					{
						if (area == max_area)
							max_cost = min(max_cost, tmp);
						else
							max_cost = tmp;
						max_area = area;
					}
				}
		cout << "Case #" << test_case << ": " << max_area << " " << max_cost << endl;
	}

	return 0;
}


#endif
