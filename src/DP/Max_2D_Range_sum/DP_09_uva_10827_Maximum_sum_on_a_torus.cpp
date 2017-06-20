#include "CommonHeader.h"


#ifdef DP_09_uva_10827_Maximum_sum_on_a_torus
READ_INPUT(DP_09_uva_10827_Maximum_sum_on_a_torus)


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

int mat[160][160];

int main()
{
	int t, N;
	cin >> t;
	while (t--)
	{
		cin >> N;
		memset(mat, 0, sizeof(mat));
		
		// expand N*N matrix to (2N)*(2N) matrix to simulate torous surface.
		// and do normal max 2D submatrix sum algorithm.
		FORI(i, 1, N) FORI(j, 1, N) cin >> mat[i][j], mat[i][j+N] = mat[i+N][j] = mat[i+N][j+N] = mat[i][j];

		FORI(i, 1, 2*N) FORI(j, 1, (2 * N)) mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];

		int max_sum = -100*150*150;

		/*FORI(i, 1, 2*N) FORI(j, 1, (2*N))
			FORI(l, i, 2*N) FORI(m, j, (2*N))*/
		FORI(i, 1, 2 * N) FORI(j, 1, (2 * N))
			for(int l=i; l < N+i && l<2*N; l++) for(int m=j; m<N+j && m<2*N; m++)
				{
					if ((m - j >= N) || (l-i >= N)) 
						continue;
					int tmp = mat[l][m] - mat[i - 1][m] - mat[l][j - 1] + mat[i - 1][j - 1];
					max_sum = max(max_sum, tmp);
				}

		cout << max_sum << endl;
	}

	return 0;
}


#endif
