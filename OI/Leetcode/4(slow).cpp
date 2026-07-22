#include <iostream>
#include <algorithm>
#include <vector>
//时间复杂度为O(log(min(m, n))), 但是是简单的归并排序求中位数法
//理论上应该还有更好的方法
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1, l2, n = nums1.size() + nums2.size();
        l1 = l2 = 0;
        vector<int> ans;
        while (l1 + l2 <= n / 2 && l1 < nums1.size() && l2 < nums2.size())
        {
            if (nums1[l1] > nums2[l2])
            {
                if (l2 < nums2.size())
                    ans.push_back(nums2[l2++]);
            }
            else 
            { 
                if (l1 < nums1.size())
                    ans.push_back(nums1[l1++]); 
            }
        }
        while (l2 < nums2.size())
            ans.push_back(nums2[l2++]);
        while (l1 < nums1.size())
            ans.push_back(nums1[l1++]);
        if ((nums1.size() + nums2.size()) % 2 == 0)
        {
            return (double)(ans[n/2]+ans[n/2-1]) / 2.0;
        }else
            return (double)(ans[n/2]);
    }
};

int main()
{
    vector<int> nums1 = {1, 2}, nums2 = {3};
    Solution o;
    double result = o.findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
    return 0;
}