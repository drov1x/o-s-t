#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a[128], cut = 0, maxn = 0, j;
        bool b = 0;
        memset(a, 0, sizeof(a));
        if (s.size() == 1)
            return 1;
        for (int i = 0; i < s.size(); i ++)
        {
            if (a[s[i]] == 0)
            {
                cut ++;
                a[s[i]]  = i + 1;
            }else
            {
                b = 1;
                maxn = max(maxn, cut);
                cut = i + 1 - a[s[i]];
                j = a[s[i]];
                memset(a, 0, sizeof(a));
                for (; j <= i; j ++)
                {
                    a[s[j]] = j + 1;
                }
            }
        }
        maxn = max(maxn, cut);
        return maxn;
    }
};

int main()
{
    Solution o;
	string s = "abcabcac";
	cout << o.lengthOfLongestSubstring(s) << endl;
    return 0;
}

