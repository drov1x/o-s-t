#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l = 0, max = min(word1.size(), word2.size());
        string s;
        while (l < max )
        {
            s.push_back(word1[l]);
            s.push_back(word2[l]);
            l ++;
        }
        if (l >= word1.size())
            while (l < word2.size())
            {
                s.push_back(word2[l++]);
            }
        else while (l < word1.size())
            {
                s.push_back(word1[l++]);
            }
        return s;
    }   
};

int main()
{
    string word1 = "abc", word2 = "pqr";
    Solution o;
    string result = o.mergeAlternately(word1, word2);
    cout << result << endl;
    return 0;
}