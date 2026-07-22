#include <bits/stdc++.h>
using namespace std;

struct aa
{
	int x, y, l, w;//横坐标，纵坐标，长，宽
};


int main()
{
	int n, x, y;
	cin >> n;
	aa a[n + 5];
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &a[i].x, &a[i].y, &a[i].l, &a[i].w);
	}
	scanf("%d %d", &x, &y);
	for (int i = n - 1; i >= 0; i--)
	{
		if (x >= a[i].x && x <= a[i].x + a[i].l && y >= a[i].y && y <= a[i].y + a[i].w)
		{
			printf("%d\n", i + 1);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}