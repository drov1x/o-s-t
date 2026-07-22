#include <bits/stdc++.h>
using namespace std;

bool isNonDecreasing(const string& s, int mask) {
    bool seenOne = false;
    for (int i = 0; i < s.length(); i++) {
        if (mask >> i & 1) 
		{
            if (s[i] == '1') 
			{
                seenOne = true;
            } else if (s[i] == '0' && seenOne) 
			{
                return false;
            }
        }
    }
    return true;
}

bool isPalindromeAfterRemove(const string& s, int mask) {
    string x;
    for (int i = 0; i < s.length(); i++) {
        if (!(mask >> i & 1)) 
		{
            x.push_back(s[i]);
        }
    }
    int len = x.length();
    for (int i = 0; i < len / 2; i++) 
	{
        if (x[i] != x[len - 1 - i]) 
		{
            return false;
        }
    }
    return true;
}

int main() 
{
    int t;
    cin >> t;
    
    while (t --) 
	{
        int n;
        string s;
        cin >> n >> s;
        
        bool found = false;
        for (int mask = 0; mask < (1 << n); mask++) 
		{
            if (!isNonDecreasing(s, mask)) {
                continue;
            }
            if (!isPalindromeAfterRemove(s, mask)) {
                continue;
            }
            found = true;
            int k = __builtin_popcount(mask);
            cout << k << "\n";
            if (k > 0) 
			{
                for (int i = 0; i < n; i++) {
                    if (mask >> i & 1) {
                        cout << i + 1 << " ";
                    }
                }
                cout << "\n";
            } else 
			{
                cout << "\n";
            }
            break;
        }
        
        if (!found) {
            cout << "-1\n";
        }
    }
    
    return 0;
}