#include "CommonHeader.h"


#ifdef graph_01_basic
READ_INPUT(graph_01_basic)


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
#include <queue>
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
#define DFS_WHITE	-1
#define DFS_BLACK	1
#define DFS_GRAY	2
vector<vii> AdjList(10);
int dfs_num[1024];
int dfs_parent[1024];

// simple depth-first-search
void dfs(int u)
{
	printf("%d ", u);
	dfs_num[u] = DFS_BLACK;

	TRvii(AdjList[u], v)
	{
		if (dfs_num[v->first] == DFS_WHITE)
			dfs(v->first);
	}
}

// simple breadth-first-search
void bfs(int s, int size)
{
	vi d(size, INT_MAX);
	d[s] = 0;		// distance from source s to s -> 0
	queue<int> Q;
	Q.push(s);		// start from source s.
	
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();

		printf("Vertex: %d,  Distance from source: %d\n", u, d[u]);
		for (int j = 0; j < (int)AdjList[u].size(); ++j)
		{
			ii v = AdjList[u][j];		// for each neighbour of u.
			if (d[v.first] == INT_MAX)	// v.first is unvisited and rechable.
			{
				d[v.first] = d[u] + 1;	// assign its distance from source.
				Q.push(v.first);		// enqueue v.first for the next iteration.
			}
		}
	}
}
// flood fill using dfs
void floodFill(int u, int color)
{
	dfs_num[u] = color;
	TRvii(AdjList[u], v)
	{
		if (dfs_num[v->first] == DFS_WHITE)
		{
			floodFill(v->first, color);
		}
	}
}

char grid[1024][1024];
int dr[] = {0, 1, 1, 0, -1, -1, -1,  0,  1};
int dc[] = {0, 0, 1, 1,  1,  0, -1, -1, -1};
int floodFill_2(int r, int c, int R, int C, int clr1, int clr2)
{
	if (r<1 || r>R || c<1 || c>C)		// outside grid
		return 0;				
	if (grid[r][c] != clr1)				// does not have color clr1
		return 0;

	int ans = 1;						// add 1 to clr1 as, grid[r][c] has clr1 color.
	grid[r][c] = clr2;					// recolor vectex(r, c) to clr2, to avoid cycling.

	FORI(i, 1, 8)
	{
		ans += floodFill_2(r + dr[i], c + dc[i], R, C, clr1, clr2);
	}

	return ans;
}

// graph check for tree-edge, back-edge, cross/forward-edge
void graphCheck(int u)
{
	dfs_num[u] = DFS_GRAY;
	TRvii(AdjList[u], v)
	{
		if (dfs_num[v->first] == DFS_WHITE)
		{
			printf("Tree Edge (%d - %d)\n", u, v->first);
			dfs_parent[v->first] = u;
			graphCheck(v->first);
		}
		else if (dfs_num[v->first] == DFS_GRAY)
		{
			if (v->first == dfs_parent[u])
				printf("Bidirectional (%d %d) -- (%d %d)\n", u, v->first, v->first, u);
			else
				printf("Back Edge(%d %d)\n", u, v->first);
		}
		else if (dfs_num[v->first] == DFS_BLACK)
		{
			printf("Forward/cross edge (%d %d)\n", u, v->first);
		}
	}
	dfs_num[u] = DFS_BLACK;
}

int main()
{
#define DFS 0
#define BFS 1
#define FLOOD_FILL 0
#define GRAPH_CHECK 0

#if DFS
	memset(dfs_num, DFS_WHITE, sizeof(dfs_num));
	// make graph.
	AdjList[0].push_back(ii(1, 0));
	AdjList[1].push_back(ii(0, 0));
	AdjList[1].push_back(ii(2, 0));
	AdjList[1].push_back(ii(3, 0));
	AdjList[2].push_back(ii(1, 0));
	AdjList[2].push_back(ii(3, 0));
	AdjList[3].push_back(ii(1, 0));
	AdjList[3].push_back(ii(2, 0));
	AdjList[3].push_back(ii(4, 0));
	AdjList[4].push_back(ii(3, 0));
	AdjList[6].push_back(ii(7, 0));
	AdjList[7].push_back(ii(6, 0));

	int numComponent = 0;

	FORI(i, 0, 7)
	{
		if (dfs_num[i] == DFS_WHITE)
		{
			printf("Component %d visits: ", ++numComponent);
			dfs(i);
			printf("\n");
		}
	}
	printf("Total Connected component:%d\n", numComponent);
#endif // DFS


#if FLOOD_FILL
	memset(dfs_num, DFS_WHITE, sizeof(dfs_num));
	// make graph.
	AdjList[0].push_back(ii(1, 0));
	AdjList[1].push_back(ii(0, 0));
	AdjList[1].push_back(ii(2, 0));
	AdjList[1].push_back(ii(3, 0));
	AdjList[2].push_back(ii(1, 0));
	AdjList[2].push_back(ii(3, 0));
	AdjList[3].push_back(ii(1, 0));
	AdjList[3].push_back(ii(2, 0));
	AdjList[3].push_back(ii(4, 0));
	AdjList[4].push_back(ii(3, 0));
	AdjList[6].push_back(ii(7, 0));
	AdjList[7].push_back(ii(6, 0));
	int numComponent = 0;
	FORI(i, 0, 7) if (dfs_num[i] == DFS_WHITE)
	{
		floodFill(i, ++numComponent);
	}

	FORI(i, 0, 7)
		printf("Vertex %d has color %d\n", i, dfs_num[i]);
#endif // FLOOD_FILL
	
#if GRAPH_CHECK
	memset(dfs_num, DFS_WHITE, sizeof(dfs_num));
	// make graph.
	AdjList[0].push_back(ii(1, 0));
	AdjList[1].push_back(ii(0, 0));
	AdjList[1].push_back(ii(2, 0));
	AdjList[1].push_back(ii(3, 0));
	AdjList[2].push_back(ii(1, 0));
	AdjList[2].push_back(ii(3, 0));
	AdjList[3].push_back(ii(1, 0));
	AdjList[3].push_back(ii(2, 0));
	AdjList[3].push_back(ii(4, 0));
	AdjList[4].push_back(ii(3, 0));
	AdjList[6].push_back(ii(7, 0));
	AdjList[7].push_back(ii(6, 0));

	graphCheck(0);
	graphCheck(5);
	graphCheck(6);
#endif	// GRAPH_CHECK


#if BFS	// make graph.
	AdjList[0].push_back(ii(1, 0));
	AdjList[1].push_back(ii(0, 0));
	AdjList[1].push_back(ii(2, 0));
	AdjList[1].push_back(ii(3, 0));
	AdjList[2].push_back(ii(1, 0));
	AdjList[2].push_back(ii(3, 0));
	AdjList[3].push_back(ii(1, 0));
	AdjList[3].push_back(ii(2, 0));
	AdjList[3].push_back(ii(4, 0));
	AdjList[4].push_back(ii(3, 0));
	AdjList[6].push_back(ii(7, 0));
	AdjList[7].push_back(ii(6, 0));

	bfs(1, 7);

#endif	// BFS
	return 0;
}

#endif
