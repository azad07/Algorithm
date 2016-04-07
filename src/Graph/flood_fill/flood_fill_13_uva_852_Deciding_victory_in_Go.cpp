#include "CommonHeader.h"


#ifdef flood_fill_13_uva_852_Deciding_victory_in_Go 
READ_INPUT(flood_fill_13_uva_852_Deciding_victory_in_Go)


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

char board[10][10];
int Xcount, Ocount;

void readCase()
{
	FORI(i, 0, 8)
		gets(board[i]);
}

void floodFill(int r, int c, char clr, int &count, bool &touchX, bool &touchO)
{
	if (r<0 || c<0 || r>8 || c>8)
		return;
	if (board[r][c] == 'X')
		touchX = true;
	if (board[r][c] == 'O')
		touchO = true;

	if (board[r][c] == '.')
	{
		board[r][c] = clr;
		count++;
		FORI(i, 0, 3)
			floodFill(r + dr4[i], c + dc4[i], clr, count, touchX, touchO);
	}
}

void solveCase()
{
	Xcount = Ocount = 0;

	FORI(i, 0, 8) FORI(j, 0, 8)
	{
		if (board[i][j] == 'X')
			Xcount++;
		if (board[i][j] == 'O')
			Ocount++;
	
		if (board[i][j] == '.')
		{
			bool touchX, touchO;
			int count = 0;
			touchX = touchO = false;
			floodFill(i, j, '*', count, touchX, touchO);
			if (touchX && touchO)
				continue;
			if (touchX)
				Xcount += count;
			if (touchO)
				Ocount += count;
		}
	}

}

int main()
{
	int t;
	scanf("%d", &t);
	getchar();
	while (t--)
	{
		readCase();
		solveCase();
		printf("Black %d White %d\n", Xcount, Ocount);
	}

	return 0;
}

#endif
