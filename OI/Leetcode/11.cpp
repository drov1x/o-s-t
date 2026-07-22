#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, rn = min(height[l], height[r]) * (r - l);
		while (l < r)
		{
			if (height[l] <= height[r])
			{
				rn = max(rn, height[l] * (r - l));
				l ++;
			}else
			{
				rn = max(rn, height[r] * (r - l));
				r --;
			}
		}
		return rn;
    }
};

int main()
{
    vector<int> nums = {1, 1};
    Solution o;
	int result = o.maxArea(nums);
    cout << result << endl;
    return 0;
}