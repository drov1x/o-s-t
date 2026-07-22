//ÃÏ∆Ω

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ios>
#include <set>

using namespace std;

bool solve(int& m) {
	int a1, a2, b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;
	if (!a1)
		solve(a1);
	if (!b1)
		solve(b1);
	if (a1 * a2 == b1 * b2) {
		m = a1 + b1;
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cout << (solve(m) ? "Yes\n" : "No\n");
	}

}