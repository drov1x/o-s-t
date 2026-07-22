//Luogu P2842纸币问题1 简单DP

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

int n, maxn = -1, m;
vector<int> nums, dp;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x > m) {
			for (int j = i + 1; j < n; j++) cin >> x;
			break;
		}
		nums.push_back(x);
	}
	dp.resize(m + 1, 99999999);
	dp[0] = 0;
	for (int i = 0; i < nums.size(); i++) {
		for (int j = nums[i]; j <= m; j++) {
			dp[j] = min(dp[j - nums[i]] + 1, dp[j]);
		}
	}
	cout << dp[m];

}