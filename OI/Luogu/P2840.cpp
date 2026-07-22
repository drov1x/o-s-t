//Luogu P2840纸币问题2 简单DP

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

const int mod = 1e9 + 7;

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
	dp.resize(m + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < nums.size(); j++) {
			if (i >= nums[j]) {
				dp[i] = (dp[i - nums[j]] + dp[i]) % mod;
			}
		}
	}
	cout << dp[m];

}