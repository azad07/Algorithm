/*
 * http://codeforces.com/gym/100935/problem/C
 *	
 */



#include "CommonHeader.h"


#ifdef codeforce_03_C_OCR 
READ_INPUT(codeforce_03_C_OCR)


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

int dr4[] = {   1, 0, -1, 0 };
int dc4[] = {   0, 1, 0, -1 };

int row, col;
char board[25][25];

void floodFill(int r, int c, char clr1, char clr2)
{
	if (r < 0 || r >= row || c < 0 || c >= col)
		return;
	if (board[r][c] != clr1)
		return;
	board[r][c] = clr2;
	FORI(i, 0, 3)
	{
		floodFill(r + dr4[i], c + dc4[i], clr1, clr2);
	}
}

int main()
{
	int t;
	cin >> t;
	FORI(test_case, 1, t)
	{
		cin >> row >> col;
		FORI(i, 0, row - 1)
			cin >> board[i];
		int cc = 0;
		FORI(i, 0, row - 1) FORI(j, 0, col - 1)
		{
			if (board[i][j] == '.')
			{
				cc++;
				floodFill(i, j, '.', '*');
			}
		}

		cout << "Case " << test_case << ": ";
		if (cc < 3)
			cout << "Zero" << endl;
		else
			cout << "Eight" << endl;
	}

	return 0;
}


#endif
