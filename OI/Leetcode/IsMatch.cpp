#include "god.h"
using namespace std;

class Solution {
    static bool check(string a, string b) {
        if (a.size() != b.size()) return false;
        for (int i = 0; i <= b.size(); i++) {
            if (a[i] != b[i] && b[i] != '?')
                return false;
        }
        return true;
    }
public:
    bool isMatch(string s, string p) {
        int l = 0, r = 0;
        vector<string> ps;
        string x;
        for (int i = 0; i < p.size(); i++) {
            if (p[i] != '*')
                x.push_back(p[i]);
            else {
                if (x != "")
                    ps.push_back(x);
                x = "";
            }
        }
        if (x != "") ps.push_back(x);
        int k = 0, i = 0;
        while (k < ps.size() && i < s.size()) {
            x = "";
            for (int j = 0; j < ps[k].size() && i < s.size(); j++) {
                x.push_back(s[i++]);
            }
            while (!check(x, ps[k])) {
                for (int o = 0; o < x.size() - 1; o++) {
                    x[o] = x[o + 1];
                }
                x.back() = s[i++];
                if (i > s.size())
                    return false;
            }
            k++;
        }
        if (k < ps.size()) return false;
        if (i < s.size() && p.back() != '*') return false;
        return true;
    }
};

int main() {
    string s = "aaaa", p = "***a";
    Solution outputs;
    bool result = outputs.isMatch(s, p);
    cout << (result ? "true " : "false ");
}