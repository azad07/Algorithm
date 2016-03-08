#include "CommonHeader.h"


#ifdef flood_fill_01_uva_260_Gioco_dell
READ_INPUT(flood_fill_01_uva_260_Gioco_dell)


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
#define WHITE	1
#define BLACK	2
#define GREEN	3
#define RED		4

int mat[201][201];
int N;

void readCase()
{
	char ch;
	FORI(i, 1, N) FORI(j, 1, N)
	{
		cin >> ch;
		if (ch == 'b')
			mat[i][j] = BLACK;
		if (ch == 'w')
			mat[i][j] = WHITE;
	}
}

void floodFill(int x, int y,  int color, int color_to_paint)
{
	if (x<1 || x>N || y<1 || y>N)
		return;
	if (mat[x][y] == color_to_paint)
		return;

	if (mat[x][y] == color)
		mat[x][y] = color_to_paint;

	if (mat[x - 1][y - 1] == color) floodFill(x - 1, y - 1, color, color_to_paint);
	if (mat[x - 1][y] == color) floodFill(x - 1, y, color, color_to_paint);
	if (mat[x][y - 1] == color) floodFill(x, y - 1, color, color_to_paint);
	if (mat[x][y + 1] == color) floodFill(x, y + 1, color, color_to_paint);
	if (mat[x + 1][y] == color) floodFill(x + 1, y, color, color_to_paint);
	if (mat[x + 1][y + 1] == color) floodFill(x + 1, y + 1, color, color_to_paint);
}

void  solveCase()
{
	// check for black
	FORI(i, 1, N)
	{
		if (mat[N][i] == BLACK)
			floodFill(N, i, BLACK, RED);
		if (mat[i][N] == WHITE)
			floodFill(i, N, WHITE, GREEN);
	}
}

void printCase(int tc)
{
	cout <<tc  << " ";
	FORI(i,1,N) 
	if (mat[1][i] == RED)
	{
		cout << "B" << endl;
		return;
	}

	FORI(i, 1, N)
	{
		if (mat[i][1] == GREEN)
		{
			cout << "W" << endl;
			return;
		}
	}
}

int main()
{
	int testCaseCounter = 0;
	while (1)
	{
		testCaseCounter++;
		cin >> N;
		if (N == 0)
			break;
		readCase();
		solveCase();
		printCase(testCaseCounter);
	}
	return 0;
}

#endif
