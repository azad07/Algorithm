#include "CommonHeader.h"


#ifdef flood_fill_09_uva_776_Monkeys_in_a_Regular_Forest 
READ_INPUT(flood_fill_09_uva_776_Monkeys_in_a_Regular_Forest)


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

char board[1024][1024];
bool V[1024][1024];
int ans[1024][1024];
int row, col;

bool readCase()
{
	char str[1024];
	row = 0;
	while (gets(str) && strlen(str))
	{
		if (str[0] == '%')
			return true;
		for (int i = 0; i < strlen(str); i += 2)
			board[row][i / 2] = str[i];
		col = strlen(board[row]);
		row++;
	}

	return false;
}

void floodFill(int r, int c, char clr1, int clr2)
{
	if (r < 0 || r >= row || c < 0 || c >= col)
		return;
	if (board[r][c] != clr1)
		return;
	if (V[r][c] == true)
		return;

	V[r][c] = true;
	ans[r][c] = clr2;

	FORI(i, 0, 7)
		floodFill(r + dr8[i], c + dc8[i], clr1, clr2);
}

void solveCase()
{
	int fill_with = 0;
	FORI(i, 0, row-1) FORI(j, 0, col - 1)
	{
		if (V[i][j] == false)
			floodFill(i, j, board[i][j], ++fill_with);
	}
}


void printCase()
{
	//do your print trick here.
	int space[1024];
	int max_num;
	memset(space, 0, sizeof(space));

	FORI(j, 0, col - 1)
	{
		max_num = 0;
		FORI(i, 0, row - 1)
		{
			max_num = max(max_num, ans[i][j]);
		}

		while (max_num)
		{
			space[j]++;
			max_num /= 10;
		}

	}

	FORI(i, 0, row - 1)
	{
		FORI(j, 0, col - 1)
		{
			printf("%*d", space[j], ans[i][j]);
			if (j < col-1)
				printf(" ");
		}
		printf("\n");
	}
	printf("%%");
}

void initCase()
{
	memset(V, false, sizeof(V));
}

int main()
{
	bool hasTestCase = true;
	while (hasTestCase)
	{
		initCase();
		hasTestCase = readCase();
		solveCase();
		printCase();
		if (hasTestCase)
			printf("\n");
	}

	return 0;
}



#endif
