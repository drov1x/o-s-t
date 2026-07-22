#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i ++){
        cin >> nums[i];
    }
    deque<int> q, p;//大、小
    vector<int> result1, result2;
    int i;
    for (i = 0; i < k - 1; ++i) {
        while (!q.empty() && nums[i] >= nums[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
        while (!p.empty() && nums[i] <= nums[p.back()]){
            p.pop_back();
        }
        p.push_back(i);
    }   //预处理窗口

    for (; i < n; i ++){
        while (!q.empty() && nums[i] >= nums[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
        if (q.front() <= i - k){
            q.pop_front();
        }
        result2.push_back(nums[q.front()]);
        while (!p.empty() && nums[i] <= nums[p.back()]){
            p.pop_back();
        }
        p.push_back(i);
        if (p.front() <= i - k){
            p.pop_front();
        }
        result1.push_back(nums[p.front()]);
    }
    for (int num : result1){
        cout << num << " ";
    }
    cout << "\n";
    for(int num : result2){
        cout << num << " ";
    }

}