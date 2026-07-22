//DP:最大子序列和（Luogu P1115, AC)

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

int n, maxn = -1;
vector<int> nums, dp;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		nums.push_back(x);
	}

	dp.resize(n, 1);
	maxn = dp[0] = nums[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + nums[i], nums[i]);
		maxn = max(dp[i], maxn);
	}
	cout << maxn;


}