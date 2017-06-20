#include "CommonHeader.h"


#ifdef DP_37_uva_10131_Is_Bigger_Smarter
READ_INPUT(DP_37_uva_10131_Is_Bigger_Smarter)


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


typedef struct data
{
	int w, iq, id;
}Data;

Data dd[10001];

int cmp(const void *i, const void *j) {
	Data *a, *b;
	a = (Data *)i, b = (Data *)j;
	if (a->w != b->w)
		return a->w - b->w;
	return a->iq - b->iq;
}

int main()
{
	int w, iq, id = 1;
	int lds[1001] = {}, lds_p[1001] = {};

	while (scanf("%d %d", &dd[id].w, &dd[id].iq) == 2)
		dd[id].id = id, lds[id] = 1, lds_p[id] = -1, id++;

	qsort(dd + 1, id, sizeof(Data), cmp);

	FORI(i, 1, id) RFORI(j, i - 1, 1)
	{
		if (dd[i].w != dd[j].w && dd[i].iq < dd[j].iq)
		{
			if (lds[i] <= lds[j] + 1)
			{
				lds[i] = lds[j] + 1;
				lds_p[i] = j;
			}
		}
	}

	int max_iq = 0, max_id = 0;
	FORI(i, 1, id)
	{
		if (lds[i] > max_iq)
		{
			max_iq = lds[i];
			max_id = i;
		}
	}

	printf("%d\n", max_iq);
	int arr[1001] = {}, ind = 0;
	while (max_id != -1)
	{
		arr[++ind] = dd[max_id].id;
		max_id = lds_p[max_id];
	}
	RFORI(i, ind, 1)
		printf("%d\n", arr[i]);

	return 0;
}


#endif
