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
#define FLOOD_FILL 0
#define GRAPH_CHECK 1

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
#if GRAPH_CHECK

#endif	// GRAPH_CHECK
	return 0;
}

#endif
