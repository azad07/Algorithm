#include "CommonHeader.h"


#ifdef DP_05_Localized_Summing_for_Blurring
READ_INPUT(DP_05_Localized_Summing_for_Blurring)


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

int mat[1024][1024];
ull ans[1024][1024];

int main()
{
	int N, M;
	bool fist = true;
	while (scanf("%d %d", &N, &M) >= 0)
	{
		memset(mat, 0, sizeof(mat));
		memset(ans, 0, sizeof(ans));

		if (!fist)
			printf("\n");

		RFORI(i, N, 1) FORI(j, 1, N) scanf("%d", &mat[i][j]);

		FORI(i, 1, N) FORI(j, 1, N) mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];

		ull total_sum = 0;

		FORI(i, 1, (N - M + 1)) FORI(j, 1, (N - M + 1))
		{
			ans[i][j] = mat[i + M - 1][j + M - 1] - mat[i + M - 1][j - 1] - mat[i - 1][j + M - 1] + mat[i - 1][j - 1];
			total_sum += ans[i][j];
		}

		
		RFORI(i, (N - M + 1), 1) FORI(j, 1, (N - M + 1)) printf("%d\n", ans[i][j]);
		printf("%d\n", total_sum);
		fist = false;
		
	}
	return 0;
}
#endif
