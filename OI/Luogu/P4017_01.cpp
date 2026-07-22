//Luogu P4017 食物链计算 DAG的路径可能数 记忆化搜索+DFS

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
vector<bool> begind, endd;
vector<int> dp;

int dfs(int index) {
	if (dp[index] != 0)
		return dp[index];
	for (int i = 0; i < dag[index].size(); i++) {
		dp[index] += dfs(dag[index][i]);
		dp[index] %= mod;
	}
	return dp[index];
}

int main() {
	cin >> n >> m;
	dag.resize(n + 1, vector<int>(0, 0));
	begind.resize(n + 1, true);
	endd.resize(n + 1, true);
	while (m--) {
		int x = 0, y = 0;
		cin >> x >> y;
		dag[x].push_back(y);
		begind[y] = false;
		endd[x] = false;
	}
	dp.resize(n + 1, 0);
	copy(endd.begin(), endd.end(), dp.begin());
	for (int i = 1; i <= n; i++) {
		if (begind[i]) {
			ans += dfs(i);
			ans %= mod;
		}
	}
	cout << ans;
}