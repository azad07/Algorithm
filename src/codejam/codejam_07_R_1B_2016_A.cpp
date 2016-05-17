#include "CommonHeader.h"


#ifdef codejam_07_R_1B_2016_A
READ_INPUT(codejam_07_R_1B_2016_A)


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

int alphabet[27];
char str[2048];

char digit[10][15] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int getDigit()
{
	FORI(i, 0, 9)
	{
		bool possible = true;
		FORI(j, 0, strlen(digit[i]) - 1)
		{
			if (alphabet[digit[i][j] - 'A' + 1] == 0)
			{
				possible = false;
				FORI(k, 0, j - 1)
				{
					alphabet[digit[i][k] - 'A' + 1]++;
				}
				break;
			}
			alphabet[digit[i][j] - 'A' + 1]--;
		}
		if (possible)
		{
			return i;
		}
	}

	return -1;
}


int main()
{
	freopen("D:\\algorithm\\Algorithm\\output\\out_test_1B_A_small.txt", "w", stdout);
	int t;
	cin >> t;
	
	FORI(test_case, 1, t)
	{
		cin >> str;
		memset(alphabet, 0, sizeof(alphabet));
		FORI(i, 0, strlen(str) - 1)
		{
			alphabet[str[i] - 'A' + 1]++;
		}

		cout << "Case #" << test_case << ": ";
		int num = getDigit();
		while (num >= 0)
		{
			cout << num;
			num = getDigit();
		}
		cout << endl;
	}
	
	return 0;
}

#endif
