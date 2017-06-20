#include "CommonHeader.h"


#ifdef DP_11_uva_111_History_Grading
READ_INPUT(DP_11_uva_111_History_Grading)


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

int main() {
	int n, c[20], r[20], lcs[21][21], x;

	scanf("%d\n", &n);

	for (int i = 0; i<n; i++) {
		scanf("%d", &x);
		c[x - 1] = i;
	}

	while (scanf("%d", &x) == 1) {
		r[x - 1] = 0;
		for (int i = 1; i<n; i++) {
			scanf("%d", &x);
			r[x - 1] = i;
		}

		for (int i = n; i >= 0; i--)
			for (int j = n; j >= 0; j--) {
				if (i == n || j == n) {
					lcs[i][j] = 0;
					continue;
				}

				if (c[i] == r[j]) lcs[i][j] = 1 + lcs[i + 1][j + 1];
				else lcs[i][j] = max(lcs[i][j + 1], lcs[i + 1][j]);
			}

		printf("%d\n", lcs[0][0]);
	}

	return 0;
}

#endif
