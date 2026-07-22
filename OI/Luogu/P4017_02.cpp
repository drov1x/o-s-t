//Luogu P4017 食物链计算 DAG的路径可能数 拓扑DP

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

const int mod = 80112002;
int n, m, ans = 0;
vector<vector<int>> dag;
vector<bool> bg;
vector<int> dp, sortd;//InDegree
queue<int> q;


int main() {
	cin >> n >> m;
	dag.resize(n + 1, vector<int>(0, 0));
	dp.resize(n + 1, 0);
	bg.resize(n + 1, true);
	while (m--) {
		int x = 0, y = 0;
		cin >> x >> y;
		dag[x].push_back(y);
		dp[y]++;
		bg[y] = false;
	}
	for (int i = 1; i <= n; i++) {
		if (bg[i])
			q.push(i);
	}
	while (!q.empty()) {
		int& u = q.front();
		for (int i : dag[u]) {
			dp[i]--;
			if (!dp[i])
				q.push(i);
		}
		sortd.push_back(u);
		q.pop();
	}
	dp.clear();
	dp.resize(n + 1);
	for (int i = sortd.size() - 1; i >= 0; i--) {
		int& x = sortd[i];
		for (int j = 0; j < dag[x].size(); j++) {
			int& y = dag[x][j];
			dp[x] += dp[y];
			dp[x] %= mod;
		}
		if (!dp[x])
			dp[x] = 1;
		else if (bg[x]) {
			ans += dp[x];
			ans %= mod;
		}
	}
	cout << ans;
}