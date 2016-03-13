#include "CommonHeader.h"


#ifdef flood_fill_04_uva_469_Wetlands_of_Florida 
READ_INPUT(flood_fill_04_uva_469_Wetlands_of_Florida )


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

vector<string> grid;
int dfs_num[101][101];
int row, col;
int color = 0;

int dr[] = {  1, 1, 0, -1, -1, -1, 0, 1 };
int dc[] = {  0, 1, 1, 1, 0, -1, -1, -1 };


int floodFill(int r, int c, int clr)
{
	if (r < 0 || r >= row || c < 0 || c >= col)
		return 0;
	if (grid[r][c] != 'W')
		return 0;
	if (dfs_num[r][c] == clr)
		return 0;
	int ans = 1;

	dfs_num[r][c] = clr;
	FORI(i, 0, 7)
	{
		ans += floodFill(r + dr[i], c + dc[i], clr);
	}
	return ans;
}

void readAndSolveCase()
{
	string line;
//	getline(cin, line);

	grid.clear();
	while (1)
	{
		getline(cin, line);
		if (line[0] != 'W' && line[0] != 'L')
			break;
		grid.push_back(line);
	}

	row = grid.size();
	col = grid[0].size();
	
	int r, c;
	istringstream iss(line);
	iss >> r >> c;

	int lake_size = floodFill(r-1, c-1, ++color);
	cout << lake_size << endl;

	while (getline(cin, line))
	{
		if (line.size() == 0)
			break;
		istringstream is(line);
		is >> r >> c;
		lake_size = floodFill(r-1, c-1, ++color);
		cout << lake_size << endl;
	}
	
}

void initCase()
{
	memset(dfs_num, WHITE, sizeof(dfs_num));
}
int main()
{
	int t;
	string ll;
	scanf("%d", &t);
	getline(cin, ll);
	getline(cin, ll);
	while (t--)
	{
		initCase();
		readAndSolveCase();
		if (t >= 1)
			cout << endl;
	}

	return 0;
}


#endif
