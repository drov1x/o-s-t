//简单的模拟题，模拟树的遍历过程

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
using namespace std;
//#define _CRT_SECURE_NO_WARNINGS
int main() {
	int d, l, x;
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &d, &l);
		x = 1;
		for (int i = 1; i < d; i++) {
			x += x + !((l > 0) * (l & 1));
			l = (l & 1) + l >> 1;
		}
		cout << x << endl;
	}
}

/*
lrj原代码，有个t他不在书里写

#include<cstdio>
int main() {
	int T, D, I;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &D, &I);
		int k = 1;
		for (int i = 0; i < D - 1; i++)
			if (I % 2) { k = k * 2; I = (I + 1) / 2; }
			else { k = k * 2 + 1; I /= 2; }
		printf("%d\n", k);
	}
	return 0;
}*/



/*int main() {
	int d, l, x;
	while (cin >> d >> l) {
		vector<bool> tree(1 << d+1, false);
		for (int i = 0; i < l; i++) {
			x = 1;
			for (int j = 1; j < d; j++) {
				tree[x] = !tree[x];
				x += x + !tree[x];
			}
		}
		cout << x << endl;
	}

}*/