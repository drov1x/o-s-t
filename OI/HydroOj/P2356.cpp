#include <bits/stdc++.h>
using namespace std;

struct p
{
    int x, y;
    p(int x = 0, int y = 0):x(x),y(y){}
};

int main()
{
	int n;
	cin >> n;
	const int nn = 1005;
	int a[nn][nn], sum, x[nn], y[nn], maxn = 0;
    vector<p> v;
    p c;
	memset(a, 0, sizeof(a));
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
	for (int i = 1; i <= n; i++)
	{
        sum = 0;
		for (int j = 1; j <= n; j ++)
		{
			cin >> a[i][j];
            if (a[i][j] == 0)
            {
                c.x = i;
                c.y = j;
                v.push_back(c);
            }
            else {
                x[i] += a[i][j];
                y[j] += a[i][j];
            }
		}
	}
    if (!v.size())
    {
        cout << "Bad Game!";
        return 0;
    }
    for (size_t i = 0; i < v.size(); i ++)
    {
        maxn = max(maxn, x[v[i].x] + y[v[i].y]);
    }
    cout << maxn;
	return 0;
}