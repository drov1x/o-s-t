#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int o = 1;
        for (int i = digits.size() - 1; i > 0; i --)
        {
            digits[i] += o;
            o = digits[i] / 10;
            digits[i] %= 10;
        }
        digits[0] += o;
        if (digits[0] >= 10)
        {
            digits.push_back(digits.back());
            for (int i = digits.size() - 2; i >= 1; i --)
                digits[i] = digits[i - 1];
            digits[0] = digits[1] / 10;
            digits[1] %= 10;
        }
        return digits;
    }
};

int main()
{
    vector<int> digits = {9, 9, 9, 9};
    Solution o;
    vector<int> resultd = o.plusOne(digits);
    for (auto it = resultd.begin(); it != resultd.end(); it ++)
    {
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}