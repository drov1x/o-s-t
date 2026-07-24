#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        auto i = nums.begin();
        for (; (i + 1) != nums.end() && *i == *(i + 1); i ++)
            continue;
        if (i == nums.end() || i + 1 == nums.end()) return true;
        bool b = *i < *(i + 1);
        i ++;
        for (; i != nums.end(); i ++){
            if ((b && *i < *(i - 1)) || (!b && *i > *(i - 1))){
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> nums = {1, 1};
    Solution o;
    bool resultd = o.isMonotonic(nums);
    cout << resultd << endl;
    return 0;
}