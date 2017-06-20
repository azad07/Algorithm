#include "CommonHeader.h"


#ifdef flood_fill_02_uva_352_The_Seasonal_War 
READ_INPUT(flood_fill_02_uva_352_The_Seasonal_War )


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

char grid[26][26];
int N, numCC;
int dfs_num[26][26];

int dr[] = {  1, 1, 0, -1, -1, -1, 0, 1 };
int dc[] = {  0, 1, 1, 1, 0, -1, -1, -1 };

void dfs(int r, int c)
{
	if (r < 0 || r >= N || c < 0 || c >= N)
		return;
	if (dfs_num[r][c] == BLACK)
		return;
	if (grid[r][c] != '1')
		return;

	dfs_num[r][c] = BLACK;

	FORI(i, 0, 7)
	{
		dfs(r + dr[i], c + dc[i]);
	}
}

void solveCase()
{
	FORI(i, 0, N - 1) FORI(j, 0, N - 1)
	{
		if (grid[i][j] == '1' && dfs_num[i][j] == WHITE)
		{
			dfs(i, j);
			numCC++;
		}
	}
}

void printCase(int n)
{
	printf("Image number %d contains %d war eagles.\n", n, numCC);
}

void initCase()
{
	FORI(i, 0, N - 1) FORI(j, 0, N - 1)
		dfs_num[i][j] = WHITE;
	numCC = 0;
}

void readCase()
{
	char aa[26];
	FORI(i, 0, N-1)
		scanf("%s\n", grid[i]);
}

int main()
{
	int test_counter = 0;
	while (scanf("%d\n", &N) >= 0)
	{
		test_counter++;
		initCase();
		readCase();
		solveCase();
		printCase(test_counter);
	}
	return 0;
}

#endif
