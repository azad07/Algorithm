#include "CommonHeader.h"


#ifdef ad_hoc_09_uva_10281_Average_Speed
READ_INPUT(ad_hoc_09_uva_10281_Average_Speed)


#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
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

//#define D_SCL_SECURE_NO_WARNINGS

int main()
{
	string line;
	char s_hr[10], s_min[10], s_sec[10];
	ull  c_time, l_time;
	unsigned long long speed, dist;
	l_time = 0;
	dist = 0;
	speed = 0.0f;
	while (getline(cin, line))
	{

		line.copy(s_hr, 2, 0); s_hr[2] = '\n';
		line.copy(s_min, 2, 3); s_min[2] = '\n';
		line.copy(s_sec, 2, 6); s_sec[2] = '\n';
		int cc_hr = atoi(s_hr);
		int cc_min = atoi(s_min);
		int cc_sec = atoi(s_sec);
		char s_speed[100];

		c_time = cc_hr * 3600 + cc_min * 60 + cc_sec;
		if (l_time == 0)
		{
			l_time = c_time;
			dist = 0;
		}
		if (line.size() > 8)
		{
			float c_dist = (speed / 3600) * (c_time - l_time);
			dist += c_dist;

			line.copy(s_speed, line.size() - 8 , 9);
			int len = line.size() - 8;
			s_speed[len-1] = '\n';
			speed = atoi(s_speed);
			//speed = atoll(s_speed);
		}
		else
		{
			ull c_dist = (speed / 3600) * (c_time - l_time);
			dist += c_dist;
			cout << line << " " << fixed << setprecision(2) << dist << " km" << endl;
		}
		l_time = c_time;
		for (string::iterator itr = line.begin(); itr != line.end(); ++itr)
			*itr = '*';
	}
	return 0;
}

#endif
