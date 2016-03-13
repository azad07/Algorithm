#include "CommonHeader.h"


#ifdef flood_fill_03_uva_459_Graph_Connectivity 
READ_INPUT(flood_fill_03_uva_459_Graph_Connectivity )


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
#define WHITE	-1
#define BLACK	2
#define GREEN	3
#define RED		4

vector<vii> adjList(27);
int dfs_num[27];
int totalV;
int numCC;

void dfs(int u)
{
	dfs_num[u] = BLACK;

	TRvii(adjList[u], v)
	{
		if (dfs_num[v->first] == WHITE)
			dfs(v->first);
	}
}

void solveCase()
{
	FORI(i, 0, totalV)
	{
		if (dfs_num[i] == WHITE)
		{
			dfs(i);
			numCC++;
		}
	}
}

void printCase()
{
	printf("%d\n", numCC);
}

void readCase()
{
	char ch, ch1, ch2;
	scanf("\n%c", &ch);
	totalV = (int)(ch - 'A');
	char tmp;
	while (scanf("%c%c", &tmp, &ch1) != EOF)
	{
		if ( ch1 == '\n')
			break;
		scanf("%c", &ch2);
		adjList[(int)(ch1 - 'A')].push_back(ii((int)(ch2 - 'A'), 0));
		adjList[(int)(ch2 - 'A')].push_back(ii((int)(ch1 - 'A'), 0));
	}
}

void initCase()
{
	FORI(i, 0, 26)
		adjList[i].clear();
	numCC = 0;
	memset(dfs_num, WHITE, sizeof(dfs_num));
}

int main()
{
	int t;
	char ch;
	cin >> t;
	FORI(test_case, 1, t)
	{
		initCase();
		readCase();
		solveCase();
		printCase();
		if (test_case < t)
			printf("\n");
	}

	return 0;
}



#endif
