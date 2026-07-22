#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
struct com
{
    int x, num;
    com(int x = 0, int num = 0):x(x), num(num){}
}x;

static bool cmp(com a, com b)
{
    if (a.x == b.x) return a.num < b.num;
    else return a.x < b.x;
}
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<com> num;
        for (size_t i = 0; i < nums.size(); i ++)
        {
            x.num = i, x.x = nums[i];
            num.push_back(x);
        }    

        sort(num.begin(), num.end(), cmp);
        int l = 0, r = num.size() - 1;
        int re = num[l].x + num[r].x;
        while (re != target)
        {
            if (re < target) l ++;
            else r --;
            re = num[l].x + num[r].x;
        }
        vector<int> result = {num[l].num, num[r].num};
        return result;
    }
};

int main()
{
    vector<int> nums = {3, 2, 3};
    int target = 6;
    Solution o;
    vector<int> resultd = o.twoSum(nums, target);
    for (size_t i = 0; i < resultd.size(); i ++)
    {
        cout << resultd[i] << ' ';
    }
    cout << endl;
    return 0;
}