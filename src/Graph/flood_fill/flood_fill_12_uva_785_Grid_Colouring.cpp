#include "CommonHeader.h"


#ifdef flood_fill_12_uva_785_Grid_Colouring 
READ_INPUT(flood_fill_12_uva_785_Grid_Colouring)


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

int dr8[] = {  1, 1, 0, -1, -1, -1,  0,  1 };
int dc8[] = {  0, 1, 1,  1,  0, -1, -1, -1 };

int dr4[] = { 1, 0, -1, 0 };
int dc4[] = { 0, 1, 0, -1 };

char board[31][81];
int row;

bool readCase()
{
	row = 0;
	while (1)
	{
		if (gets(board[row]) == NULL)
			return true;
		if (board[row][0] == '_')
			return false;
		row++;
	}
}

void initCase()
{
	memset(board, NULL, sizeof(board));
}

void printCase()
{
	FORI(i, 0, row)
		printf("%s\n", board[i]);
}

void floodFill(int r, int c, char clr)
{
	if (r < 0 || c<0 || r>row || c >= strlen(board[r]))
		return;
	if (board[r][c] == ' ')
	{
		board[r][c] = clr;
		FORI(i, 0, 3)
			floodFill(r + dr4[i], c + dc4[i], clr);
	}
}

void solveCase()
{
	char ch = ' ';
	FORI(i, 0, row) FORI(j, 0, strlen(board[i]) - 1)
	{
		if (board[i][j] != ' ')
		{
			if (board[i][j] == '_')
				continue;
			if (ch == ' ')
				ch = board[i][j];
			if (board[i][j] != ch)
			{
				char clr = board[i][j];
				board[i][j] = ' ';
				floodFill(i, j, clr);
			}
		}
	}
}

int main()
{
	while (1)
	{
		initCase();
		if (readCase())
			return 0;
		solveCase();
		printCase();
	}
	return 0;
}


#endif
