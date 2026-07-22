#include <bits/stdc++.h>//单调栈
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n + 2, 0), p(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }

    vector<int> st;
    st.push_back(1);
    for (int i = 2; i <= n; i++){
        if (nums[i] <= nums[st.back()]) {
            st.push_back(i);
        } else {
            while (!st.empty() && nums[i] > nums[st.back()]) {
                p[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << p[i] << " ";
    }

}