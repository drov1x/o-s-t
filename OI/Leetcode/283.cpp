#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
		for (size_t r = 0; r < nums.size(); r ++)
		{
			if (nums[r])
				nums[l++] = nums[r];
		}
		for (size_t r = l; r < nums.size(); r ++)
		{
			nums[r] = 0;
		}
    }
};

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution o;
    o.moveZeroes(nums);
    for (size_t i = 0; i < nums.size(); i ++)
    {
        cout << nums[i] << ' ';
    }
    cout << endl;
    return 0;
}