#include "CommonHeader.h"


#ifdef codejam_01_Counting_sheep
READ_INPUT(codejam_01_Counting_sheep)


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

int sheep[11];

ull isPossible(int N)
{
	memset(sheep, 0, sizeof(sheep));
	ull count = 0;
	ull num = 0;
	ull d = 0;

	FORI(i, 1, 10000)
	{
		num = i*N;
		if (num > (ULLONG_MAX-num))
			return -1;
		while (num)
		{
			d = num % 10;
			num /= 10;
			if (sheep[d] == 0)
			{
				count++;
				sheep[d]++;
				if (count >= 10)
					return i*N;
			}
		}
	}
	return -1;
}

int main()
{
	freopen("D:\\algorithm\\Algorithm\\output\\out.txt", "w", stdout);
	int t, N;
	cin >> t;
	FORI(test_case, 1, t)
	{
		cin >> N;
		cout << "Case #" << test_case << ": ";
		ull ans = isPossible(N);
		if (ans == -1)
			cout << "INSOMNIA" << endl;
		else
			cout << ans << endl;
			
	}

	return 0;
}

#endif
