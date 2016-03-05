#include "CommonHeader.h"


#ifdef ad_hoc_06_uva_837_Light_and_Transparencies
READ_INPUT(ad_hoc_06_uva_837_Light_and_Transparencies)

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

#define FORI(i,a,b) for(int i=(int)a; i<=(int)b; i++)
#define RFORI(i,a,b) for(int i=(int)a; i>=(int)b; i--)
#define INT_MIN     (-2147483647 - 1) 
#define INT_MAX       2147483647

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



typedef struct _Plate
{
	float x1, y1, x2, y2, coeff;
}Plate;

Plate plates[1024];

bool cmp(ff left, ff right)
{
	return (left.first < right.first) ? true : false;
}

int main()
{
	int t, N;
	cin >> t;
	FORI(test_case, 1, t)
	{
		vff x_axis;
		cin >> N;
		x_axis.push_back(ff(INT_MIN, 1.0));
		FORI(i, 1, N)
		{
			cin >> plates[i].x1 >> plates[i].y1 >> plates[i].x2 >> plates[i].y2 >> plates[i].coeff;
			x_axis.push_back(ff(plates[i].x1, 1.0));
			x_axis.push_back(ff(plates[i].x2, 1.0));
			if (plates[i].x1 > plates[i].x2)
				swap(plates[i].x1, plates[i].x2);
		}
		x_axis.push_back(ff(INT_MAX, 1.0));
		sort(x_axis.begin(), x_axis.end(), cmp);

		FORI(i, 1, N)
		{
			for (vff_itr itr = x_axis.begin(); itr != x_axis.end(); ++itr)
			{
				if (itr->first >= plates[i].x1 && itr->first < plates[i].x2)
					itr->second *= plates[i].coeff;
			}
		}

		cout << x_axis.size()-1 << endl;
		cout << fixed;
		cout << "-inf" << " " << setprecision(3) << x_axis[1].first << " " << setprecision(3) << x_axis[0].second << endl;
		FORI(i, 1, x_axis.size() - 3)
		{
			cout << setprecision(3) << x_axis[i].first << " " << setprecision(3) << x_axis[i + 1].first << " " << setprecision(3) << x_axis[i].second << endl;
		}
		cout << setprecision(3) << x_axis[x_axis.size() - 2].first << " " << "+inf" << " " << setprecision(3) << x_axis[x_axis.size() - 1].second << endl;
		
		// read problem statement carefully, here is the trick, new line seperation between two cases.
		if (test_case < t)
			cout << endl;
	}
	return 0;
}


#endif
