#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int l = 0;
        while (l < s.size())
        {
            if (s[l] != t[l])
                return t[l];
            else
                l++;
        }
        return t[l];
    }
};

int main()
{
    string s = "abcd", t = "abcde";
    Solution o;
    char result = o.findTheDifference(s, t);
    cout << result << endl;
    return 0;
}