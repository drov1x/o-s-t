//Luogu P1434[SHOI2002]滑雪 记忆化搜索

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

struct place {
	int x;
	int y;
	int h;
};

bool cmp(place a, place b) {
	return a.h > b.h;
}

const int xx[4] = { 0, 1, 0, -1 }, yy[4] = { 1, 0, -1, 0 };

int n, m, maxn = -1;
vector<vector<int>> mp, dp;
vector<place> high;

void search(int x, int y, int step) {
	if (dp[x][y] == 0) {
		dp[x][y] = step;
	}
	else if (dp[x][y] > step) {
		return;
	}
	maxn = max(maxn, step);
	for (int i = 0; i < 4; i++) {
		if (x + xx[i] >= 0 && x + xx[i] < n && y + yy[i] >= 0 && y + yy[i] < m && mp[x + xx[i]][y + yy[i]] < mp[x][y]) {
			search(x + xx[i], y + yy[i], step + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		vector<int> row;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			row.push_back(x);
		}
		mp.push_back(row);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int p = mp[i][j];
			for (int k = 0; k < 4; k++) {
				if (p < mp[min(max(0, i + xx[i]), n - 1)][min(max(0, j + yy[k]), m - 1)])
					goto next;
			}
			high.push_back({ i, j, p });
		next:continue;
		}
	}
	dp.resize(n, vector<int>(m, 0));
	sort(high.begin(), high.end(), cmp);//神之一笔
	for (int i = 0; i < high.size(); i++) {
		search(high[i].x, high[i].y, 1);
	}
	cout << maxn;
}