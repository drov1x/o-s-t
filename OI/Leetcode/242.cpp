#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class Solution {//排序判断
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main()
{
    string s = "rat", t = "car";
    Solution o;
    bool resultd = o.isAnagram(s, t);
    cout << resultd << endl;
    return 0;
}

/*逐字符判断
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        int a[26];
        memset(a, 0, sizeof(a));
        for (int i = 0; i < s.size(); i ++)
            a[s[i]-'a'] ++;
        for (int i = 0; i < t.size(); i ++)
        {
            if (a[t[i]-'a'])
                a[t[i]-'a'] --;
            else
                return false;
        }
        return true;
    }
};*/