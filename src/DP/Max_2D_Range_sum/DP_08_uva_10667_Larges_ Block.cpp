#include "CommonHeader.h"


#ifdef DP_08_uva_10667_Larges_ Block
READ_INPUT(DP_08_uva_10667_Larges_ Block)


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

int sum[105][105];

int main()
{
	int t, N, s, r1, c1, r2, c2;
	cin >> t;
	while (t--)
	{
		memset(sum, 0, sizeof(sum));
		cin >> N >> s;
		FORI(i, 1, N) FORI(j, 1, N) sum[i][j] = 1;

		FORI(i, 1, s)
		{
			cin >> r1 >> c1 >> r2 >> c2;
			if (r1 > r2 || c1 > c2)
			{
				swap(r1, r2);
				swap(c1, c2);
			}

			FORI(m, r1, r2) FORI(n, c1, c2) sum[m][n] = 0;
		}

		FORI(i, 1, N) FORI(j, 1, N) sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];

		int max_area = 0;

		FORI(i, 1, N) FORI(j, 1, N)
			FORI(m, i, N) FORI(n, j, N)
			{
				int tmp = sum[m][n] - sum[i - 1][n] - sum[m][j - 1] + sum[i - 1][j - 1];
				if (tmp == (m - i + 1)*(n - j + 1))
					max_area = max(max_area, tmp);
			}

		cout << max_area << endl;
	}
	return 0;
}

#endif
