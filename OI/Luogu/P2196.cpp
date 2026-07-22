//Luogu P2196[NOIP1996提高组]挖地雷 DP&DAG

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

int n, m;
vector<int> nums, dp;
vector<vector<bool>> mp;
vector<vector<int>>road;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x = 0;
		cin >> x;
		nums.push_back(x);
	}
	for (int i = 1; i < n; i++) {
		vector<bool> x;
		int y;
		for (int j = 1; j <= n - i; j++) {
			cin >> y;
			x.push_back(y);
		}
		mp.push_back(x);
	}
	dp.resize(n, 0);
	dp[n - 1] = nums[n - 1];
	road.resize(n, vector<int>());
	road[n - 1].push_back(n - 1);
	for (int i = n - 2; i >= 0; i--) {
		int p = 0;
		dp[i] = nums[i];
		for (int j = i + 1; j <= i + mp[i].size(); j++) {
			if (mp[i][j - i - 1] == 0) continue;
			if (dp[i] < dp[j] + nums[i]) {
				p = j;
				dp[i] = dp[j] + nums[i];
			}
		}
		vector<int> r;
		r.push_back(i);
		for (int j = 0; j < road[p].size(); j++) {
			r.push_back(road[p][j]);
		}
		road[i] = r;
	}
	int maxn = -1, p = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] > maxn) {
			maxn = dp[i];
			p = i;
		}
	}
	for (int i = 0; i < road[p].size(); i++) {
		cout << road[p][i] + 1 << ' ';
	}
	cout << endl << maxn << endl;
}