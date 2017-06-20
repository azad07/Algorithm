#include "CommonHeader.h"


#ifdef ad_hoc_07_uva_10082_WERTYU
READ_INPUT(ad_hoc_07_uva_10082_WERTYU)





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

string line;
char keyboard[256];

int main() {
	for (int i = 0; i < 256; i++)
		keyboard[i] = i;
	// remap
	keyboard['1'] = '`';
	keyboard['2'] = '1';
	keyboard['3'] = '2';
	keyboard['4'] = '3';
	keyboard['5'] = '4';
	keyboard['6'] = '5';
	keyboard['7'] = '6';
	keyboard['8'] = '7';
	keyboard['9'] = '8';
	keyboard['0'] = '9';
	keyboard['-'] = '0';
	keyboard['='] = '-';
	keyboard['W'] = 'Q';
	keyboard['E'] = 'W';
	keyboard['R'] = 'E';
	keyboard['T'] = 'R';
	keyboard['Y'] = 'T';
	keyboard['U'] = 'Y';
	keyboard['I'] = 'U';
	keyboard['O'] = 'I';
	keyboard['P'] = 'O';
	keyboard['['] = 'P';
	keyboard[']'] = '[';
	keyboard['\\'] = ']';
	keyboard['S'] = 'A';
	keyboard['D'] = 'S';
	keyboard['F'] = 'D';
	keyboard['G'] = 'F';
	keyboard['H'] = 'G';
	keyboard['J'] = 'H';
	keyboard['K'] = 'J';
	keyboard['L'] = 'K';
	keyboard[';'] = 'L';
	keyboard['\''] = ';';
	keyboard['X'] = 'Z';
	keyboard['C'] = 'X';
	keyboard['V'] = 'C';
	keyboard['B'] = 'V';
	keyboard['N'] = 'B';
	keyboard['M'] = 'N';
	keyboard[','] = 'M';
	keyboard['.'] = ',';
	keyboard['/'] = '.';

	while (getline(cin, line)) {
		for (int i = 0; i < line.length(); i++) {
			line[i] = keyboard[line[i]];
		}
		cout << line << endl;
	}

	return 0;
}


#endif
