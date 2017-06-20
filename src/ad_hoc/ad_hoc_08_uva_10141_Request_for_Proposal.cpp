#include "CommonHeader.h"


#ifdef ad_hoc_08_uva_10141_Request_for_Proposal
READ_INPUT(ad_hoc_08_uva_10141_Request_for_Proposal)





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

int main() {
	int r, n;
	string x;
	int count = 0;

	while (cin >> r >> n, r || n) {
		count++;

		double price = 2000000000, p;
		int reqMet = -1, rm;
		string name, nam;

		for (int i = 0; i < r; i++) {
			cin.ignore();
			getline(cin, x);
		}

		while (n--) {
			getline(cin, nam);
			scanf("%lf %d\n", &p, &rm);
			if (rm > reqMet) {
				reqMet = rm;
				name = nam;
				price = p;
			}
			else if (rm == reqMet && p < price) {
				reqMet = rm;
				name = nam;
				price = p;
			}

			for (int i = 0; i < rm; i++) {
				getline(cin, x);
			}
		}

		if (count > 1)
			cout << endl;
		cout << "RFP #" << count << endl;
		cout << name << endl;
	}

	return 0;
}

#endif
