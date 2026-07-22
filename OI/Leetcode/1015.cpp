#include "god.h"
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;
        int r = 1 % k, i = 1;
        for (i = 1; i < k && r != 0; i++)
            r = (r * 10 + 1) % k;
        return i;
    }
};

int main() {
    int k = 11;
    Solution outputs;
    int result = outputs.smallestRepunitDivByK(k);
    cout << result;
    return 0;
}