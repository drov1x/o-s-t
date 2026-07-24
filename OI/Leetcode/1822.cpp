#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for (auto i : nums) {
            if (i == 0) return 0;
            if (i < 0) 
                ans = -1 * ans;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {3, -2, 3};
    Solution o;
    int resultd = o.arraySign(nums);
    cout << resultd << endl;
    return 0;
}