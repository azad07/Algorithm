#include "CommonHeader.h"


#ifdef DP_21_uva_00116_Unidirectional_TSP
READ_INPUT(DP_21_uva_00116_Unidirectional_TSP)


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

typedef struct _Grid
{
	int cost;
	int minCost;
	int px;
}Grid;

Grid grid[11][101];
int dr[] = {0, -1,  0,  1};
int dc[] = {0, -1, -1, -1};

void printMat(int r, int c)
{
#if DEBUG
	cout << endl;
	FORI(i, 1, r)
	{
		FORI(j, 1, c)
		{
			if (grid[i][j].minCost == 0xffff)
				cout << yellow << "0\t";
			else
				cout << red<< grid[i][j].minCost << "\t";
		}
		cout << endl;
	}
#endif
}

int main()
{
	int r, c;
	while (scanf("%d %d", &r, &c) == 2)
	{
		FORI(i, 1, r) FORI(j, 1, c) scanf("%d", &grid[i][j].cost), grid[i][j].minCost = 0xffff;

		//initialize base case.
		FORI(i, 1, r) grid[i][c].minCost = grid[i][c].cost;
		/*	just apply DP with DAG....
		*
		*	F(i, j) = MIN { F(k, j+1) } + cost, ∀ k ∈ (i-1, i, i+1)   
		*/

		RFORI(j, c, 2) FORI(i, 1, r)
		{
			FORI(k, 1, 3)
			{
				int nr = i + dr[k];
				int nc = j + dc[k];
				if (nr < 1) nr = r;
				if (nr > r) nr = 1;

				if (grid[nr][nc].minCost > (grid[nr][nc].cost + grid[i][j].minCost))
				{
					grid[nr][nc].minCost = grid[nr][nc].cost + grid[i][j].minCost;
					grid[nr][nc].px = i;
				}
			}
			printMat(r, c);
		}

		// find minimum.
		int minVal = 0xffff, start_row;
		FORI(i, 1, r)
		{
			if (minVal > grid[i][1].minCost)
			{
				minVal = grid[i][1].minCost;
				start_row = i;
			}
		}

		printf("%d", start_row);
		// print path.
		FORI(i, 1, c-1)
		{
			start_row = grid[start_row][i].px;
			printf(" %d", start_row);
		}
		printf("\n%d\n", minVal);
	}

	return 0;
}


#endif
