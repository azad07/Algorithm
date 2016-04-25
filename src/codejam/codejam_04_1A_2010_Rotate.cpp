#include "CommonHeader.h"


#ifdef codejam_04_1A_2010_Rotate
READ_INPUT(codejam_04_1A_2010_Rotate)


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

char board[51][51];

void rotateBoard(int N)
{
	FORI(i, 0, N - 1) RFORI(j, N - 1, 0)
	{
		int k = j;
		while (k < N - 1 && board[i][k + 1] == '.' && board[i][k] != '.')
		{
			board[i][k + 1] = board[i][k];
			board[i][k] = '.';
			k++;
		}
	}
}

void check(int i, int j, int K,  bool &red_win, bool &blue_win)
{
	char ch = '.';
	int counter = 0;
	if (board[i][j] != '.')
	{
		if (ch == '.')
		{
			ch = board[i][j];
			counter = 1;
		}
		else
		{
			if (ch == board[i][j])
			{
				counter++;
				if (counter >= K)
				{
					if (ch == 'R')
						red_win = true;
					else
						blue_win = true;
				}
			}
			else
			{
				ch = board[i][j];
				counter = 1;
			}
		}
	}
	else
		ch = '.';
}

string checkWinner(int N, int K)
{
	char ch = '.';
	int counter = 0;
	bool red_win = false;
	bool blue_win = false;
	// check horizontal
	FORI(i, 0, N - 1) FORI(j, 0, N - 1)
	{
		check(i, j, K, red_win, blue_win);
	}

	// check vertical
	FORI(j, 0, N - 1) FORI(i, 0, N - 1)
	{
		check(i, j, K, red_win, blue_win);
	}

	// check diagonal



	if (red_win && blue_win)
		return "Both";
	else if (red_win)
		return "Red";
	else if (blue_win)
		return "Blue";
	else
		return "Neither";
}

int main()
{
	//freopen("D:\\algorithm\\Algorithm\\output\\out.txt", "w", stdout);
	int t, N, K;
	cin >> t;
	FORI(test_case, 1, t)
	{
		cin >> N >> K;
		memset(board, NULL, sizeof(board));
		FORI(i, 0, N - 1) cin >> board[i];
		rotateBoard(N);
		string winner = checkWinner(N, K);
		cout << "Case #" << test_case << ": " << winner << endl;
	}

	return 0;
}

#endif
