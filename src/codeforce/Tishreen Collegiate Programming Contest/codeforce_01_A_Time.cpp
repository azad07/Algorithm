/*
 * http://codeforces.com/gym/100935/problem/A
 *	A plane can go from city X to city Y in 1 hour and 20 minutes. However, when it returns from city Y to city X, with the same speed, it spends only 80 minutes! If you don’t know how might that happen, just remember that 1 hour and 20 minutes is the same as 80 minutes ;-) In this problem you will have 2 durations of time and you have to decide if they are equal or not.
 *	
 *	Input
 *	The first line will be the number of test cases T. Each test case has two lines, the first line represents the first duration and contains 3 integers: h, m, s; these are the Hours, Minutes and Seconds. The second line represent the second duration with 3 integers also, in the same way. All integers are positive and below 5000.
 *	
 *	Output
 *	For each test case, print one line which contains the number of the test case. Then print “Yes” if the 2 durations are equal and print “No” otherwise, see the samples and follow the output format.
 *	
 *	Examples
 *	input
 *	3
 *	1 20 0
 *	0 80 0
 *	0 2 10
 *	0 0 130
 *	2 10 5
 *	2 11 0
 *	output
 *	Case 1: Yes
 *	Case 2: Yes
 *	Case 3: No
 *	
 */



#include "CommonHeader.h"


#ifdef codeforce_01_A_Time 
READ_INPUT(codeforce_01_A_Time)


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

int dr4[] = {  0, 1, 0, -1, 0 };
int dc4[] = {  0, 0, 1, 0, -1 };

int main()
{
	int t;
	ull h1, h2, m1, m2, s1, s2;
	cin >> t;
	FORI(test_case, 1, t)
	{
		cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

		cout << "Case " << test_case << ": ";
		if ((h1 * 3600 + m1 * 60 + s1) == (h2 * 3600 + m2 * 60 + s2))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}



#endif
