#include "CommonHeader.h"


#ifdef flood_fill_06_uva_657_The_die_is_cast 
READ_INPUT(flood_fill_06_uva_657_The_die_is_cast)


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

int dr8[] = {0, 1, 1, 0, -1, -1, -1,  0,  1 };
int dc8[] = {0, 0, 1, 1,  1,  0, -1, -1, -1 };

int dr4[] = { 0, 1, 0, -1, 0 };
int dc4[] = { 0, 0, 1, 0, -1 };

char grid[55][55];
int row, col;

void dfsX(int r, int c)
{
	if (r<1 || r>row || c<1 || c>col)
		return;
	
	if (grid[r][c] != 'X')
		return;

	grid[r][c] = '*';

	FORI(i, 1, 4)
	{
		dfsX(r + dr4[i], c + dc4[i]);
	}
}

void dfsPixel(int r, int c, int &blocks)
{
	if (r<1 || r>row || c<1 || c>col)
		return;
	if (grid[r][c] == 'X')
	{
		blocks++;
		dfsX(r, c);
	}
	if (grid[r][c] == '.')
		return;

	grid[r][c] = '.';

	FORI(i, 1, 4)
		dfsPixel(r + dr4[i], c + dc4[i], blocks);
}

void solveAndPrintCase()
{
	int ans[100] = { 0 }, nOfans = 0;

	FORI(i, 1, row) FORI(j, 1, col)
	{
		if (grid[i][j] == '*')
		{
			dfsPixel(i, j, ans[nOfans]);
			nOfans++;
		}
	}

	sort(ans, ans + nOfans);
	
	FORI(i, 0, nOfans - 1)
	{
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl << endl;
}

void readAndInitCase()
{

	FORI(i, 1, row)
	{
		cin >> grid[i] + 1;
		grid[i][0] = 'a';
	}

}

int main()
{
	int test_case = 0;
	bool first = true;
	while (cin >> col >> row, (row || col))
	{
		readAndInitCase();
		first = false;
		cout << "Throw " << ++test_case << endl;
		solveAndPrintCase();
	}
	cout << endl;
	return 0;
}

#endif
