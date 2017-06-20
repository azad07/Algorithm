#include "CommonHeader.h"


#ifdef DP_01_uva_507_Jill_Rides_Again 
READ_INPUT(DP_01_uva_507_Jill_Rides_Again)


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
	int t, n, num;
	int i, j, best;
	cin >> t;
	FORI(test_case, 1, t)
	{
		cin >> n;
		int ans = 0, sum = 0, tmp = 1, st = 0xffff, end;
		
		FORI(i, 2, n )
		{
			cin >> num;
			sum += num;
			if (sum < 0) sum = 0, tmp = i;
			if (sum >= 0)
			{
				if (sum > ans)
				{
					st = tmp; 
					end = i;
				}
				ans = sum;
			}
		}

		if (sum <= 0)
			cout << "Route " << test_case << " has no nice parts" << endl;
		else
			cout << "The nicest part of route "<<test_case<<" is between stops "<<st<<" and "<<end << endl;

	}
	return 0;
}

#endif
