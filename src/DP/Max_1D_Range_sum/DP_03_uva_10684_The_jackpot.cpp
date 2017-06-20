#include "CommonHeader.h"


#ifdef DP_03_uva_10684_The_jackpot 
READ_INPUT(DP_03_uva_10684_The_jackpot)


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

int main()
{
	int N, val, ans, sum;
	while (1)
	{
		cin >> N;
		if (N == 0)
			break;
		sum = ans = 0;
		FORI(i, 1, N)
		{
			cin >> val;
			sum += val;
			if (sum < 0)
				sum = 0;
			ans = max(sum, ans);
		}
		if (ans > 0)
			cout << "The maximum winning streak is " << ans << "." << endl;
		else
			cout << "Losing streak." << endl;
	}

	return 0;
}


#endif
