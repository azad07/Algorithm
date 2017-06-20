#include "CommonHeader.h"


#ifdef DS_02_test
READ_INPUT(DS_02_test)


<<<<<<< HEAD

=======
>>>>>>> origin/dev_ashish
#include <iostream>

using namespace std;

extern void init(int track_size, int head);
extern void request(int track_no);
extern int fcfs();
extern int sspt();
extern int look();
extern int clook();

#define REQ   0
#define FCFS  1
#define SSPT  2
#define LOOK  3
#define CLOOK 4

#define MAX_TRACK 10000

int arr_track[MAX_TRACK + 1];
int arr_cmd[2*MAX_TRACK + 1];
int arr_ans[MAX_TRACK + 1];

int run()
{
	int track_size, head;
	cin >> track_size >> head;
	int n_arr_track, n_arr_cmd, n_arr_ans;
	cin >> n_arr_track;
	for (int i = 0; i < n_arr_track; ++i)
		cin >> arr_track[i];
	cin >> n_arr_cmd;
	for (int i = 0; i < n_arr_cmd; ++i)
		cin >> arr_cmd[i];
	cin >> n_arr_ans;
	for (int i = 0; i < n_arr_ans; ++i)
		cin >> arr_ans[i];

	// first call init.
	init(track_size, head);

	int p_track = 0, p_ans = 0;
	int score = 0;
	for (int i = 0; i < n_arr_cmd; ++i) {
		switch (arr_cmd[i]) {
		case REQ:
		{
			request(arr_track[p_track++]);
			break;
		}
		case FCFS:
		{
			int ans = fcfs();
			if (ans == arr_ans[p_ans++])
				score++;
			break;
		}
		case SSPT:
		{
			int ans = sspt();
			if (ans == arr_ans[p_ans++])
				score++;
			break;
		}
		case LOOK:
		{
			int ans = look();
			if (ans == arr_ans[p_ans++])
				score++;
			break;
		}
		case CLOOK:
		{
			int ans = clook();
			if (ans == arr_ans[p_ans++])
				score++;
			break;
		}
		default:
			break;
		}
	}

	return score;
}


int main()
{
	int t;
	int total_score, total_score_earned = 0;
	cin >> t;
	for (int tc = 0; tc < t; ++tc)
	{
		total_score_earned += run();
	}
	cin >> total_score;
	cout << "TotalScore: " << total_score_earned << endl;
	cout << "Score percentage: "<<(total_score_earned * 100) / total_score << endl;
	return 0;
}

/**************************************************************************************************/
// write client code here.


struct Node {
	int key;
	Node *left;
	Node *right;
<<<<<<< HEAD
	Node *next;
	Node *prev;
=======
>>>>>>> origin/dev_ashish
	Node(int key) {
		this->key = key;
		this->left = NULL;
		this->right = NULL;
	}
};



class BST {
private:
	Node *root;
public:
	BST() {
		root = NULL;
<<<<<<< HEAD
		first_node = NULL;
		last_added = NULL;
=======
>>>>>>> origin/dev_ashish
	}
	~BST() {
	}

	void put(int key) {
		root = put(root, key);
	}

	void del(int key) {
		root = del(root, key);
	}

	int ceil(int key) {
		Node *t = ceil(root, key);
		if (t == NULL)
			return -1;		// invalid 
		return t->key;
	}

	int floor(int key) {
		Node *t = floor(root, key);
		if (t == NULL)
			return -1;		// invalid
		return t->key;
	}

	int Max() {
		Node *t = Max(root);
		if (t == NULL)
			return -1;
		return t->key;
	}

private:
<<<<<<< HEAD

=======
>>>>>>> origin/dev_ashish
	Node* Max(Node* node) {
		if (node == NULL)
			return NULL;
		while (node->right != NULL)
			node = node->right;
		return node;
	}

	Node* put(Node* node, int key) {
		if (node == NULL)
			return new Node(key);

		if (key < node->key)
			node->left = put(node->left, key);
		else if (key > node->key)
			node->right = put(node->right, key);
		else
			node->key = key;
		return node;
	}

	Node* del(Node* node, int key) {
		if (node == NULL)
			return NULL;
		if (key < node->key)
			node->left = del(node->left, key);
		else if (key > node->key)
			node->right = del(node->right, key);
		else
		{
			if (node->left == NULL)
			{
				Node *t = node->right;
				delete node;
				return t;
			}
			if (node->right == NULL)
			{
				Node *t = node->left;
				delete node;
				return t;
			}

			Node *t = node;
			node = getMin(t->right);
			node->right = delMin(t->right);
			node->left = t->left;
		}
		return node;
	}

	Node* delMin(Node* node) {
		if (node->left == NULL) {
			Node *t = node->right;
			//delete node;
			return t;
		}
		node->left = delMin(node->left);
		return node;
	}

	Node* getMin(Node* node)
	{
		if (node == NULL)
			return NULL;
		while (node->left != NULL)
			node = node->left;
		return node;
	}

	Node* ceil(Node* node, int key) {
		if (node == NULL)
			return NULL;
		if (key == node->key)
			return node;
		if (key > node->key)
			return ceil(node->right, key);

		Node *t = ceil(node->left, key);
		if (t != NULL)
			return t;
		else
			return node;
	}

	Node* floor(Node* node, int key) {
		if (node == NULL)
			return NULL;
		if (key == node->key)
			return node;
		if (key < node->key)
			return floor(node->left, key);

		Node *t = floor(node->right, key);
		if (t != NULL)
			return t;
		else
			return node;
	}
};


BST *bst = NULL;
int mTrackSize, mHead;

int diff(int a, int b) {
	int d = a - b;
	if (d < 0)
		d *= -1;
	return d;
}

void init(int track_size, int head) {
	if (bst != NULL)
		delete bst;
	bst = new BST();

	mTrackSize = track_size;
	mHead = head;
}

void request(int track_no) {
	bst->put(track_no);
}

int fcfs() {
	int track_no = -1;

	return track_no;
}

int sspt() {
	int track_no = -1;

	int ceil = bst->ceil(mHead);
	int floor = bst->floor(mHead);

	int c = (ceil == -1) ? INT_MAX : diff(mHead, ceil);
	int f = (floor == -1) ? INT_MAX : diff(mHead, floor);

	if (c < f)
		track_no = ceil;
	else
		track_no = floor;

	bst->del(track_no);
	mHead = track_no;

	return track_no;
}

#define LEFT 0
#define RIGHT 1
int dir = LEFT;

int look() {
	int track_no = -1;
	if (dir == LEFT) {
		int floor = bst->floor(mHead);
		if (floor == -1) {
			int ceil = bst->ceil(mHead);
			track_no = ceil;
			dir = RIGHT;
		}
		else {
			track_no = floor;
		}
	}
	else {
		int ceil = bst->ceil(mHead);
		if (ceil == -1) {
			int floor = bst->floor(mHead);
			track_no = floor;
			dir = LEFT;
		}
		else {
			track_no = ceil;
		}
	}

	bst->del(track_no);
	mHead = track_no;

	return track_no;
}

int clook() {
	int track_no = -1;

	int floor = bst->floor(mHead);
	if (floor == -1) {
		// find max item.
		track_no = bst->Max();
	}
	else {
		track_no = floor;
	}

	bst->del(track_no);
	mHead = track_no;

	return track_no;
}


#endif
