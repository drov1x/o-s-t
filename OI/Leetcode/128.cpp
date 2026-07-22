#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (int x : st){
            if (st.contains(x-1)) continue;
            int y = x + 1;
            while (st.contains(y)) y ++;
            ans = max(ans, y - x);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {100,4,200,1,3,2};
    Solution o;
    int resultd = o.longestConsecutive(nums);
    cout << resultd << endl;
    return 0;
}