//¶þ²æÊ÷µÄDFS±éÀú

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ios>
#include <set>

using namespace std;

#define maxn 260

struct Node {
	bool b;
	int v, sum;
	Node* l, * r;
	Node() :b(false), l(nullptr), r(nullptr) {}
}*root;

int n, p;
vector<int> mid(0, 0), bk(0, 0);
vector<Node*> ans;
bool failed = false;

void addnode(int l, int r, Node* now) {
	if (l > r || p < 0 || now == nullptr) return;
	int m = -1;
	for (int i = l; i <= r; i++) {
		if (mid[i] == bk[p]) {
			m = i;
			break;
		}
	}
	if (m == -1) {
		failed = true;
		return;
	}
	now->v = mid[m];
	now->b = true;
	now->sum = now->v;
	p--;
	if (m + 1 <= r) {
		now->r = new Node();
		addnode(m + 1, r, now->r);
	}
	if (l <= m - 1) {
		now->l = new Node();
		addnode(l, m - 1, now->l);
	}
}

void nodeclear(Node* now) {
	if (now == nullptr)
		return;
	nodeclear(now->l);
	nodeclear(now->r);
	delete(now);
}

void cul(Node* now) {
	if (now == nullptr)
		return;
	if (now->l != nullptr) {
		now->l->sum += now->sum;
		cul(now->l);
	}
	if (now->r != nullptr) {
		now->r->sum += now->sum;
		cul(now->r);
	}
	if (now->l == nullptr && now->r == nullptr) {
		ans.push_back(now);
	}
}

bool cmp(Node* a, Node* b) {
	return a->sum < b->sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> n) {
		nodeclear(root);
		root = nullptr;
		ans.clear();
		bk.clear();
		mid.clear();
		failed = false;
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			mid.push_back(t);
		}
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			bk.push_back(t);
		}
		root = new Node;
		p = n - 1;
		addnode(0, n - 1, root);
		if (failed) {
			cout << "error input or build failed\n";
			continue;
		}
		root->sum = root->v;
		cul(root);
		if (ans.empty()) {
			cout << "not found leaves\n";
			continue;
		}
		sort(ans.begin(), ans.end(), cmp);
		cout << ans[0]->v << endl;
	}
}
/*
7
3 2 1 4 5 6 7
3 1 2 5 6 7 4
*/