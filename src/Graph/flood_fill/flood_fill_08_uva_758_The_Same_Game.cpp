#include "CommonHeader.h"


#ifdef flood_fill_08_uva_758_The_Same_Game 
READ_INPUT(flood_fill_08_uva_758_The_Same_Game)


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
#define DEBUG 1

int dr8[] = {0, 1, 1, 0, -1, -1, -1,  0,  1 };
int dc8[] = {0, 0, 1, 1,  1,  0, -1, -1, -1 };

int dr4[] = {  1, 0, -1, 0 };
int dc4[] = {  0, 1, 0, -1 };

char board[11][16];
bool V[11][16];
int row, col;
char MARKER = '*';

void printB()
{
#ifdef DEBUG
	FORI(i, 0, row - 1)
	{
		FORI(j, 0, col - 1)
		{
			if (board[i][j] == MARKER)
				cout << red;
			else
				cout << white;
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
#endif
}

int floodFill(int r, int c, char clr)
{
	if (r < 0 || r >= row || c < 0 || c >= col)
		return 0;
	if (V[r][c] == true)
		return 0;
	if (board[r][c] != clr)
		return 0;

	int ans = 1;
	V[r][c] = true;
	FORI(i, 0, 3)
		ans += floodFill(r + dr4[i], c + dc4[i], clr);

	return ans;
}

void fillCluster(int r, int c, char clr1, char clr2)
{
	if (r < 0 || r >= row || c < 0 || c >= col)
		return;
	if (board[r][c] != clr1)
		return;
	board[r][c] = clr2;
	FORI(i, 0, 3)
		fillCluster(r + dr4[i], c + dc4[i], clr1, clr2);
}

void shiftDown()
{
	FORI(j, 0, col - 1) RFORI(i, row - 2, 0)
	{
		int r = i;
		while (r < row - 1 && board[r + 1][j] == MARKER)
		{
			board[r + 1][j] = board[r][j];
			board[r][j] = MARKER;
			r++;
		}
	}
}

void shiftLeft()
{
	FORI(i, 0, row - 1) FORI(j, 1, col - 1)
	{
		int c = j;
		while (c > 0 && board[i][c - 1] == MARKER)
		{
			board[i][c - 1] = board[i][c];
			board[i][c] = MARKER;
			c--;
		}
	}
}

void solveCase()
{
	int max_cluster, cluster_r, cluster_c, move;
	char filling_color;
	move = 0;
	while (1)
	{
		memset(V, false, sizeof(V));
		max_cluster = 0;
		// bottom->up, left->right.
		RFORI(i, 9, 0) FORI(j, 0, 14)
		{
			if (V[i][j] == false && board[i][j] != MARKER)
			{
				int cluster = floodFill(i, j, board[i][j]);
				if (cluster == max_cluster)
					cout << "ashish" << endl;
				if (cluster > max_cluster)
				{
					max_cluster = cluster;
					cluster_r = i;
					cluster_c = j;
				}
			}
		}

		if (max_cluster < 2)
			break;

		filling_color = board[cluster_r][cluster_c];

		// fill the biggest cluster with *.
		fillCluster(cluster_r, cluster_c, filling_color, MARKER);

		printB();
		//do shifting operation.
		shiftDown();
		printB();

		shiftLeft();
		printB();
		// print move
		//Move 1 at (4,1): removed 32 balls of color B, got 900 points.
		printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n", ++move, (10 - cluster_r), cluster_c + 1, max_cluster, filling_color, (max_cluster - 2)*(max_cluster - 2));
	}
}

void printCase()
{

}

void initCase()
{
	memset(V, false, sizeof(V));
}

void readCase()
{
	FORI(i, 0, 14)
	{
		scanf("%s", board[i]);
	}
	col = strlen(board[0]);
	row = 10;
}

int main()
{
	int t;
	scanf("%d\n", &t);
	FORI(test_case, 1, t)
	{
		initCase();
		readCase();
		printf("Game: %d\n", test_case);
		solveCase();
		
	}

	return 0;
}
#endif
