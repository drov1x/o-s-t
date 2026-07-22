#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if (n == 1) return false;
        for (int i = 1; i < n; i ++)
        {
            if (n % i == 0)
            {
                for (int j = i; j < n; j ++)
                {
                    if (s[j] != s[j % i])
                        goto next;
                }
                return true;
                next:continue;
            }
        }
        return false;
    }
};

int main()
{
    string s = "abcabc";
    Solution o;
    bool resultd = o.repeatedSubstringPattern(s);
    cout << resultd << endl;
    return 0;
}