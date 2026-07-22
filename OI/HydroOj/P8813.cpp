#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b;
	long long ans = 1;
	cin >> a >> b;
	if (a == 1)
	{
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= b; i ++)
	{
		ans *= a;
		if (ans < a || ans > 1000000000)
		{
			cout << "-1";
			return 0;
		}
	}
	cout << ans;
	return 0;
} 