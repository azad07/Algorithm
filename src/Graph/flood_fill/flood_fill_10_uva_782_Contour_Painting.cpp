#include "CommonHeader.h"


#ifdef flood_fill_10_uva_782_Contour_Painting 
READ_INPUT(flood_fill_10_uva_782_Contour_Painting)


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

char board[38][88];
bool visited[38][88];
int row, col;
char contor_color;

void dfs(int r, int c)
{
	visited[r][c] = true;

	FORI(i, 0, 3)
	{
		int nr = r + dr4[i];
		int nc = c + dc4[i];
		if (nr < 0 || nc < 0 || board[nr][nc] == '\0' || nr >= row || visited[nr][nc] == true)
			continue;
		if (board[nr][nc] == 'X')
			board[r][c] = '#';
		else
			dfs(nr, nc);
	}
}

void solveCase()
{
	FORI(i, 0, 34)
	{
		FORI(j, 0, 84)
		{
			if (board[i][j] != 'X' && board[i][j] != '*' &&  board[i][j] != '_')
				board[i][j] = ' ';
		}
		board[i][83] = '\0';
	}

	FORI(i, 0, row) FORI(j, 0, strlen(board[row])-1)
	{
		if (board[i][j] == '*')
		{
			board[i][j] = ' ';
			dfs(i, j);
		}
	}

	RFORI(i, 34, 0)
	{
		bool not_found = true;
		RFORI(j, 84, 0)
		{
			if (board[i][j] == 'X' || board[i][j] == '#' || board[i][j] == '_')
			{
				board[i][j + 1] = '\0';
				not_found = false;
				break;
			}
		}
		if (not_found)
			board[i][0] = '\0';
	}
}

void printCase()
{
	FORI(i, 0, row)
		printf("%s\n", board[i]);
}


void readCase()
{
	while (1)
	{
		gets(board[row]);
		if (board[row][0] == '_')
			break;
		row++;
	}
}

void initCase()
{
	memset(board, '\0', sizeof(board));
	memset(visited, false, sizeof(visited));
	row = col = 0;
}

int main()
{
	int t;
	char tc[10];
	scanf("%d", &t);
	getchar();

	while (t--)
	{
		initCase();
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}


#endif
