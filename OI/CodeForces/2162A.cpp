#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	int maxn = -1000;
	cin >> t;
	int a[12];
	for (int o = 0; o < t; o++)
	{
		int n;
		cin >> n;
		maxn = -1000;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i ++)
		{
			scanf("%d", &a[i]);
		}
		int sum;
		for (int i = 0; i < n; i ++)
		{
			for (int j = 0; j <= i; j ++)
			{
				sum = 0;
				for (int z = j; z <= i; z ++)
				{
					sum += a[z];
					maxn = max(maxn, sum/(i - j + 1));
				}
			} 
		}
		printf("%d\n", maxn);
	}
	return 0;
}