#include "CommonHeader.h"


#ifdef flood_fill_07_uva_722_Lakes 
READ_INPUT(flood_fill_07_uva_722_Lakes)


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

int dr4[] = {  1, 0, -1, 0 };
int dc4[] = {  0, 1, 0, -1 };

char grid[101][101];
int row, col;
int r, c;

int dfs(int r, int c)
{
	if (r < 0 || r >= row || c < 0 || c >= col)
		return 0;
	if (grid[r][c] == '1')
		return 0;

	grid[r][c] = '1';

	int ans = 1;
	FORI(i, 0, 3)
		ans += dfs(r + dr4[i], c + dc4[i]);

	return ans;
}

void readCase()
{
	scanf("%d %d\n", &r, &c);
	int counter = 0;
	char inp[105];
	
	while (gets(grid[counter]) &&strlen(grid[counter]) > 0)
	{
		counter++;
	}
	
	r--;
	c--;
	row = counter;
	col = strlen(grid[0]);
}


int main()
{
	int t;
	scanf("%d\n\n", &t);
	while (t--)
	{
		readCase();

		cout << dfs(r, c) << endl;
		if (t > 0)
			cout << endl;
	}

	return 0;
}

#endif
