#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int x;
	for (int i = n; i >= 0; i--)
	{
		scanf("%d", &x);
		if (x != 0)
		{
			if (x < 0)
				printf("-");
			else if (i != n)
				printf("+");
			if (abs(x) != 1 || i == 0)
				printf("%d", abs(x));
			if (i > 0)
				printf("x");
			if (i > 1)
				printf("^%d", i);
		}
	}
	return 0;
}