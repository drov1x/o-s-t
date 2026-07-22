//Luogu P2834纸币问题3 简单DP
//该题与 P2840纸币问题2的区别在于循环方式的区别导致更新的区别，问题2可以计算排列问题，问题3只计算组合问题。

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
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 1/*可以使用nums[i]优化*/; j <= m; j++) {
			if (j >= nums[i]) {//该部分可以优化进j的for循环
				dp[j] = (dp[j] + dp[j - nums[i]]) % mod;
			}
		}
	}
	cout << dp[m];

}
