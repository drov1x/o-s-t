#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n = nums.size();
        vector<int> result;
        int i;
        for (i = 0; i < k - 1; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }   //预处理窗口

        for (; i < n; i ++){
            while (!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            if (q.front() <= i - k){
                q.pop_front();
            }
            result.push_back(nums[q.front()]);
        }

        return result;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> nums = {3, 1, 1, 3};
    int k = 3;
    Solution sol;
    vector<int> result = sol.maxSlidingWindow(nums, k);
    for(int num : result){
        cout << num << " ";
    }

}