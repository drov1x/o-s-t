//¶þ²æÊ÷µÄBFS±éÀú

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

#define maxn 260

bool failed = false;
vector<int> ans(0, 0);

struct Node {
	bool b;
	int v;
	Node *l, *r;
	Node() :b(false), l(nullptr), r(nullptr) {}
}*root;

void addnode(int v, char s[]) {
	int n = strlen(s);
	Node *now = root;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			if (now->l == nullptr)
				now->l = new Node;
			now = now->l;
		}
		else if (s[i] == 'R') {
			if (now->r == nullptr)
				now->r = new Node;
			now = now->r;
		}
	}
	if (now->b)
		failed = true;
	now->b = true;
	now->v = v;
}

void nodeclear(Node *now) {
	if (now == nullptr)
		return;
	nodeclear(now->l);
	nodeclear(now->r);
	delete(now);
	now = nullptr;
}
/*(11,LL) (7,LLL) (8,R) (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR)*/

bool read_input() {
	nodeclear(root);
	failed = false;
	root = new Node;
	int v = 0;
	char s[maxn];
	while (1) {
		if (scanf("%s", s) != 1)
			return false;
		if (!strcmp(s, "()"))
			return 1;
		sscanf(s + 1, "%d", &v);
		addnode(v, strchr(s, ',') + 1);
	}
}

bool bfs() {
	queue<Node*> q;
	q.push(root);
	Node* now;
	while (!q.empty()) {
		now = q.front(), q.pop();
		if (!now->b)
			return true;
		ans.push_back(now->v);
		if (now->l != nullptr)
			q.push(now->l);
		if (now->r != nullptr)
			q.push(now->r);
	}
	return false;
}




int main() {
	while (read_input()) {
		ans.clear();
		if (bfs() || failed)
			printf("not complete\n");
		else {
			for (int i = 0; i < ans.size(); i++)
				printf((i ? " %d" : "%d"), ans[i]);
			printf("\n");
		}
	}
}