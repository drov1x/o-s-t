//Luogu P1802 五倍经验日 01背包

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

struct member {
	int lose, win, use;
};

int n, x;
vector<member> v;
vector<int> dp;

int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int x = 0, y = 0, z = 0;
		cin >> x >> y >> z;
		v.push_back({ x, y, z });
	}
	dp.resize(x + 1, 0);
	for (int i = 0; i < v.size(); i++) {
		for (int j = x; j >= v[i].use; j--) {
			dp[j] = max(dp[j - v[i].use] + v[i].win, dp[j] + v[i].lose);
		}
		for (int j = v[i].use - 1; j >= 0; j--) {
			dp[j] += v[i].lose;
		}
	}

	cout << 5 * (long long)dp[x];

}