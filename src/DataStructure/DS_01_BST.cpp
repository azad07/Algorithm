#include "CommonHeader.h"


#ifdef DS_01_BST
READ_INPUT(DS_01_BST)


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

typedef int Value;
typedef int Key;

class Node
{
public:
	Key key;
	Value value;
	Node *left;
	Node *right;
	int count;
	Node(Key& k, Value& v) :key(k), value(v), left(NULL), right(NULL), count(1)
	{}
};

class BST
{
public:
	BST() :root(NULL) {}
	~BST() { delete root; }

	void Put(Key& key, Value& value) 
	{
		root = Put(root, key, value);
	}

	const Value& Get(Key& key) 
	{
		Node* node = Get(root, key);
		if (node == NULL) return NULL;
		return node->value;
	}

	//Value& Min() {}
	
	//Value& Max() {}

	int Size() 
	{
		return Size(root);
	}

	//Key& Floor() {}

	//Key& Ceil() {}

	//void DeleteAll() {}

	//void Delete(Key& key) {}
private:
	int Size(Node* node)
	{
		if (node == NULL) return 0;
		return node->count;
	}

	Node* Put(Node* node, Key& key, Value& value)
	{
		if (node == NULL) return new Node(key, value);

		if (key < node->key)
			node->left = Put(node->left, key, value);
		else if (key > node->key)
			node->right = Put(node->right, key, value);
		else
			node->key = key;

		node->count = 1 + Size(node->left) + Size(node->right);

		return node;
	}

	Node* Get(Node* node, Key& key)
	{
		if (node == NULL) return NULL;

		if (key < node->key)
			return Get(node->left, key);
		else if (key > node->key)
			return Get(node->right, key);
		else
			return node;
	}
private:
	Node *root;
};

int main()
{
	// driver program to test BST implementation.
	BST bstTest;
	map<Key, Value> mapTest;

	int testCount = 100;

	enum
	{
		PUT = 0,
		GET,
		LAST
	};

	FORI(testCase, 1, testCount)
	{
		Key key = rand() % (testCount /2);
		Value value = rand();
		int bstSize, mapSize;
		Value mapV, bstV;
		int operation = rand() % (LAST);
		switch (operation)
		{
		case PUT:
		{
			mapTest.insert(make_pair(key, value));
			bstTest.Put(key, value);
			mapSize = mapTest.size();
			bstSize = bstTest.Size();
			if (mapSize == bstSize)
				cout << green << "PASS: [PUT] mapSize:" << mapSize << "\tbstSize:" << bstSize << endl;
			else
				cout << red << "FAIL: [PUT]	mapSize:" << mapSize << "\tbstSize:" << bstSize << endl;
			break;
		}
		case GET:
		{
			mapV = mapTest[key];
			bstV = bstTest.Get(key);
			mapSize = mapTest.size();
			bstSize = bstTest.Size();
			if (mapV == bstV)
				cout << green << "PASS: [GET] mapSize:" << mapSize << "\tbstSize:" << bstSize << endl;
			else
				cout << red << "FAIL: [GET]	mapV:" << mapV << "\tbstV:" << bstV << endl;
			break;
		}
		default:
			break;
		}

	}

	

	
	return 0;
}

#endif
