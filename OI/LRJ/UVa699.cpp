//树叶（二叉树累加求和）

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

bool failed = false;
int n, c, maxn = -1;
vector<int> ans, tree;

struct Node {
	int v;
	Node* l, * r;
	Node() :l(nullptr), r(nullptr) {}
}*root;

void addnode(int &index, Node* now) {
	c++;
	if (index >= n)
		return;
	now->v = tree[index];
	if (tree[++index] != -1) {
		now->l = new Node;
		addnode(index, now->l);
	}
	if (tree[++index] != -1) {
		now->r = new Node;
		addnode(index, now->r);
	}
	maxn = max(maxn, c);
	c--;
}

void cul(int index, Node* now) {
	ans[index] += now->v;
	if (now->l != nullptr)
		cul(index - 1, now->l);
	if (now->r != nullptr)
		cul(index + 1, now->r);
}

void nodeclear(Node* now) {
	if (now == nullptr)
		return;
	nodeclear(now->l);
	nodeclear(now->r);
	delete(now);
	now = nullptr;
}

int main() {
	cin >> n;
	while (n != -1) {
		tree.clear();
		for (int i = 0; i < n; i++) {
			int val;
			cin >> val;
			tree.push_back(val);
		}
		c = 0;
		maxn = -1;
		root = new Node;
		int index = 0; 
		addnode(index, root);
		ans.clear();
		ans.resize(max(0, maxn * 2 - 1) , 0);
		cul(maxn, root);
		int l = 0, r = 2 * maxn - 2;
		while (ans[l] == 0)
			l++;
		while (ans[r] == 0)
			r--;
		for (int i = l; i <= r; i++)
			cout << ans[i] << " ";
		cout << endl;
		cin >> n;
	}
}
/*
9
5 7 -1 6 -1 -1 3 -1 -1
17
8 2 9 -1 -1 6 5 -1 -1 12 -1 -1 3 7 -1 -1 -1
-1
*/