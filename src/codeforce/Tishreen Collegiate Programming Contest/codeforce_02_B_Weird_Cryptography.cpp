/*
 * http://codeforces.com/gym/100935/problem/B
 *	
 */



#include "CommonHeader.h"


#ifdef codeforce_02_B_Weird_Cryptography 
READ_INPUT(codeforce_02_B_Weird_Cryptography)


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
#define TRvi(c, it)  for(vi::iterator it = (c).begin(); it != (c).end(); ++it)
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

typedef struct _Data
{
	string str;
	int rep;
}Data;

Data data[10];
int totalstring;
vi code;

void printCase(int tc)
{
	cout << "Case " << tc << ": ";
	TRvi(code, it)
	{
		cout << *it;
	}
	cout << endl;
}

void solveCase()
{
	code.clear();

	int num = 0;
	while (1)
	{
		num = 0;
		FORI(i, 0, 9)
		{
			if (data[i].rep > 0)
			{
				num++;
				data[i].rep--;
			}
		}
		if (num == 0)
			break;
		else
			code.push_back(num);
	}

	sort(code.begin(), code.end());
}

void initCase()
{
	totalstring = 0;
	FORI(i, 0, 9)
	{
		data[i].str.clear();
		data[i].rep = 0;
	}
}

int findString(string str)
{
	FORI(i, 0, 9)
	{
		if (data[i].str == str)
			return i;
	}
	return -1;
}

void readCase(int t)
{
	string str;
	FORI(i, 1, t)
	{
		cin >> str;
		int ind = findString(str);
		if (ind >= 0)
		{
			data[ind].rep++;
		}
		else
		{
			data[totalstring].str = str;
			data[totalstring].rep = 1;
			totalstring++;
		}
	}
}

int main()
{
	int t, tc;
	string str;
	tc = 0;
	while (cin >> t, t)
	{
		initCase();
		readCase(t);
		solveCase();
		printCase(++tc);		
	}

	return 0;
}




#endif
