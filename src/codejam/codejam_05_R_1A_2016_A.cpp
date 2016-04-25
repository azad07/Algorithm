#include "CommonHeader.h"


#ifdef codejam_05_R_1A_2016_A
READ_INPUT(codejam_05_R_1A_2016_A)


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

char str[1024];
char res[2048];

int main()
{
	freopen("D:\\algorithm\\Algorithm\\output\\out_test_big.txt", "w", stdout);
	int t, i, j;
	cin >> t;
	FORI(test_case, 1, t)
	{
		//memset(str, '\n', sizeof(str));
		memset(res, NULL, sizeof(str));
		cin >> str;
		i = j = 1024;
		res[i] = str[0];
		
		FORI(k, 1, strlen(str)-1)
		{
			if (res[i] <= str[k])
				res[--i] = str[k];
			else
				res[++j] = str[k];
		}

		cout << "Case #" << test_case << ": ";
		FORI(k, i, j) 
			cout << res[k];
		cout << endl;
	}
	return 0;
}

#endif
