#include <bits/stdc++.h>
using namespace std;

bool isPrime[100000010];
int Prime[6000010], cnt = 0, n, q, k;

void GetPrime(int n)
{
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[1] = 0;
	
	for(int i = 2; i <= n; i++)
	{
		if(isPrime[i])
			Prime[++cnt] = i;
			
		for(int j = 1; j <= cnt && i*Prime[j] <= n; j++) 
		{
			isPrime[i*Prime[j]] = 0;
            
			if(i % Prime[j] == 0)
				break;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;
	GetPrime(n);
	while (q--)
	{
		cin >> k;
		cout << Prime[k] << endl;
	}
	return 0;
}

