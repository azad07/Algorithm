#include "CommonHeader.h"


#ifdef DP_40_uva_10349_Antenna_Placement
READ_INPUT(DP_40_uva_10349_Antenna_Placement)


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

char grid[45][15];
int board[45][15];

void printmat(int r, int c)
{
	cout << endl;
	FORI(i, 1, r)
	{
		FORI(j, 1, c) cout << green << grid[i - 1][j - 1] << red << board[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	int t, r, c;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d\n", &r, &c);
		FORI(i, 0, r-1) scanf("%s\n", &grid[i]);

		FORI(i, 1, r) FORI(j, 1, c)
		{
			board[i][j] = board[i - 2][j] + board[i][j - 2] - board[i - 2][j - 2];
			if (grid[i-1][j-1] == '*')
			{
				board[i][j]++;
				if (grid[i - 2][j - 2] == '*')
					board[i][j]++;
				else if (grid[i - 2][j - 1] == '*' && grid[i - 1][j - 2] == '*')
					board[i][j]++;
			}
			else
			{
				if (grid[i - 2][j - 1] == '*' && grid[i - 1][j - 2] == '*')
					board[i][j] += 2;
				else if (grid[i - 2][j - 2] == '*')
					board[i][j]++;
				else if (grid[i - 2][j - 1] == '*')
					board[i][j]++;
				else if (grid[i - 1][j - 2] == '*')
					board[i][j]++;
			}
		}
		int ans = board[r][c];
printmat(r, c);
		printf("%d\n", ans);
	}

	return 0;
}


#endif
