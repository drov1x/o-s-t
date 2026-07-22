#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cout << (n % 4 == 0 || ((n - 2) % 4 == 0 && n > 2)? "YES" : "NO") << endl;
	return 0;
}