/*
 * https://www.codechef.com/APRIL16/problems/COLOR
 *	
 */

#include "CommonHeader.h"

#ifdef codechef_02_apr_Chef_and_Ballons 
READ_INPUT(codechef_02_apr_Chef_and_Ballons)


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
#define DEBUG 1

int dr8[] = {0, 1, 1, 0, -1, -1, -1,  0,  1 };
int dc8[] = {0, 0, 1, 1,  1,  0, -1, -1, -1 };

int dr4[] = {  0, 1, 0, -1, 0 };
int dc4[] = {  0, 0, 1, 0, -1 };

int getMin(int a, int b, int c)
{
	int ret = INT_MAX;
	
	if (a > 0) ret = min(ret, a);
	if (b > 0) ret = min(ret, b);
	if (c > 0) ret = min(ret, c);

	return ret;
}

int main()
{
	int t, r, g, b, k, ans;
	cin >> t;
	while (t--)
	{
		cin >> r >> g >> b;
		cin>>k;
		ans = 0;
		k--;
		RFORI(i, 3, 1)
		{
			int mn = getMin(r, g, b);
			if (mn >= k)
			{
				ans += i*k;
				break;
			}
			else
			{
				ans += i*mn;
				k -= mn;
			}
			if (r > 0) r -= mn;
			if (g > 0) g -= mn;
			if (b > 0) b -= mn;
		}
		ans++;

		cout << ans << endl;
	}

	return 0;
}



#endif
