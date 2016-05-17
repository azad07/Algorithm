#include "CommonHeader.h"


#ifdef codejam_06_R_1A_2016_B
READ_INPUT(codejam_06_R_1A_2016_B)


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

int q[51 * 2][51];
int sq[51 * 2][51];
int board[51][51];



int main()
{
//	freopen("D:\\algorithm\\Algorithm\\output\\out_test_big.txt", "w", stdout);
	int t, N;
	cin >> t;
	FORI(test_case, 1, t)
	{
		cin >> N;
		FORI(i, 1, 2 * N - 1)
		{
			q[i][0] = 1;
			FORI(j, 1, N)
				cin >> q[i][j];
		}

		// sort.
		int k = 1;
		FORI(i, 1, 2 * N - 1)
		{
			int shortest = INT_MAX;
			int ind = 0;
			FORI(j, 1, 2 * N - 1)
			{
				if (q[j][0] == 1 && q[j][1] < shortest)
				{
					shortest = q[j][1];
					ind = j;
				}
			}

			FORI(m, 1, N)
				sq[k][m] = q[ind][m];
			k++;
			q[ind][0] = 0;
		}
	}

	
	return 0;
}

#endif
