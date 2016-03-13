#include "CommonHeader.h"


#ifdef flood_fill_05_uva_572_ Oil_Deposits 
READ_INPUT(flood_fill_05_uva_572_ Oil_Deposits )


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

int dr[] = {  1, 1, 0, -1, -1, -1, 0, 1 };
int dc[] = {  0, 1, 1, 1, 0, -1, -1, -1 };
int row, col;
char grid[101][101];

void floodFill(int r, int c, char cl1, char cl2)
{
	if (r < 0 || r >= row || c < 0 || c >= col)
		return;
	if (grid[r][c] != cl1)
		return ;

	grid[r][c] = cl2;
	FORI(i, 0, 7)
	{
		floodFill(r + dr[i], c + dc[i], cl1, cl2);
	}
}
int solveCase()
{
	int numCC = 0;
	FORI(i, 0, row - 1) FORI(j, 0, col - 1)
	{
		if (grid[i][j] == '@')
		{
			floodFill(i, j, '@', '*');
			numCC++;
		}
	}

	return numCC;
}

void readCase()
{
	FORI(i, 0, row - 1)
		scanf("%s", grid[i]);
}

int main()
{
	int num_oil_fields = 0;
	while (scanf("%d %d", &row, &col), row)
	{
		readCase();
		num_oil_fields = solveCase();
		printf("%d\n", num_oil_fields);
	}

	return 0;
}

#endif
