/*
 * https://www.codechef.com/APRIL16/problems/COLOR
 *	
 */

#include "CommonHeader.h"

#ifdef codechef_01_apr_Chef_And_Coloring 
READ_INPUT(codechef_01_apr_Chef_And_Coloring)


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


int main()
{
	int t, N, r, g, b, m;
	char room_color;
	cin >> t;
	while (t--)
	{
		cin >> N;
		r = g = b = 0;
		FORI(i, 0, N - 1)
		{
			cin >> room_color;
			switch (room_color)
			{
			case 'R':
				r++;
				break;
			case 'G':
				g++;
				break;
			case 'B':
				b++;
				break;
			default:
				break;
			}
		}
		m = max(r, g);
		m = max(m, b);
		cout << (N - m) << endl;
	}

	return 0;
}



#endif
