#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1 = haystack.size(), l2 = needle.size();
        bool b;
        for (int i = 0; i <= l1 - l2; i ++)
        {
            b = true;
            for (int j = i, k = 0; j < i + l2; j ++, k ++)
            {
                if (needle[k] != haystack[j])
                {
                    b = false;
                    break;
                }
            }
            if (b)
                return i;
        }
        return -1;
    }
};

int main()
{
    string haystasck = "sadbutsad", needle = "sad";
    Solution o;
    int resultd = o.strStr(haystasck, needle);
    cout << resultd << endl;
    return 0;
}