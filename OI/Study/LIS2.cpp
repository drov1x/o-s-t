//DP:最长上升子序列（非递归）

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

int n;
vector<int> nums, dp;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		nums.push_back(x);
	}

	dp.resize(n, 1);
	for (int i = n - 1; i >= 0; i++) {
		for (int j = i + 1; j < n; j++) {
			if (nums[i] < nums[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}


}