#include "CommonHeader.h"


#ifdef DP_28_uva_10400_Game_Show_Math
READ_INPUT(DP_28_uva_10400_Game_Show_Math)


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

int seq[101];
char sign[101];

bool possible(int idx, int sum, int p, int q)
{
	if (sum == q && idx == p)
		return true;
	if (idx >= p)
		return false;


	if (possible(idx + 1, sum + seq[idx + 1], p, q))
	{
		sign[idx] = '+';
		return true;
	}
	if (possible(idx + 1, sum - seq[idx + 1], p, q))
	{
		sign[idx] = '-';
		return true;
	}
	if (sum*seq[idx + 1] <= 32000 && possible(idx + 1, sum * seq[idx + 1], p, q))
	{
		sign[idx] = '*';
		return true;
	}
	if (sum % seq[idx + 1] == 0 && possible(idx + 1, sum / seq[idx + 1], p, q))
	{
		sign[idx] = '/';
		return true;
	}
	return false;
}

int main()
{
	int t, p, q;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &p);
		FORI(i, 1, p) scanf("%d", &seq[i]);
		scanf("%d", &q);
		
		if (possible(1, seq[1], p, q))
		{
			printf("%d", seq[1]);
			FORI(i, 1, p - 1)
				cout << sign[i] << seq[i + 1];
			cout << "=" << q << endl;
		}
		else
		{
			printf("NO EXPRESSION\n");
		}

	}

	return 0;
}


#endif
