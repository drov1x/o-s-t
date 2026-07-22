#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

class Solution {
    struct str
    {
        string t, s;
    };
    static bool cmp(str a, str b)
    {
        return a.s < b.s;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<str> a;
        for (auto it = strs.begin(); it != strs.end(); it ++)
        {
            str t;
            t.s = t.t = *it;
            sort(t.s.begin(), t.s.end());
            a.push_back(t);
        }
        sort(a.begin(), a.end(), cmp);
        vector<vector<string>> ans;
        for (auto it = a.begin(); it != a.end();)
        {
            vector<string> b;
            str before = *it;
            for (;it != a.end() && ((*it).s == before.s); it ++)
            {
                before = (*it);
                b.push_back(before.t);
            }
            ans.push_back(b);
        }
        return ans;
    }
};

int main()
{
    vector<string> strs = {""};
    Solution o;
    vector<vector<string>> resultd = o.groupAnagrams(strs);
    for (auto it = resultd.begin(); it != resultd.end(); it ++)
    {
        for (auto j = (*it).begin(); j != (*it).end(); j ++)
        {
            cout << *j << '/';
        }
        cout << endl;
    }
    return 0;
}