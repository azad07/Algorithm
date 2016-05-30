#include "CommonHeader.h"


#ifdef DP_06_uva_836_Largest_Submatrix
READ_INPUT(DP_06_uva_836_Largest_Submatrix)


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

char mat[26][26];
int sum[26][26];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(mat, NULL, sizeof(mat));
		memset(sum, 0, sizeof(sum));

		cin >> mat[0];
		int len = strlen(mat[0]);
		FORI(i, 1, len - 1)
			cin >> mat[i];

		FORI(i, 1, len) FORI(j, 1, len)
		{
			sum[i][j] = mat[i - 1][j - 1] - '0';
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}

		int max_sum = 0;
		FORI(i, 1, len) FORI(j, 1, len)
			FORI(m, i, len) FORI(n, j, len)
				{
					int tmp = sum[m][n] - sum[i - 1][n] - sum[m][j - 1] + sum[i - 1][j - 1];
					if (tmp == (m - i + 1)*(n - j + 1))
					{
						max_sum = max(max_sum, tmp);
					}
				}

		cout << max_sum << endl;
		if (t > 0)
			cout << endl;

	}



	return 0;
}



#endif
