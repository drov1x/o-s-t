//DP:最长上升子序列

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
vector<int> nums, lis;

int LIS(int c) {
	if (c >= n - 1)
		return 1;
	if (lis[c] != 1)
		return lis[c];
	for (int i = c + 1; i < n; i++) {
		if (nums[i] > nums[c]) {
			lis[c] = max(lis[c], 1 + LIS(i));
		}
	}
	return lis[c];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		nums.push_back(x);
	}

	lis.resize(n, 1);
	cout << LIS(0) << endl;


}