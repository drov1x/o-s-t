#include <bits/stdc++.h>//01trie的静态实现
using namespace std;

struct Node{
    int Next[2];
    Node(){
        memset(Next, -1, sizeof(Next));
    }
};

vector<Node> Nodes;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, num, maxn = 0;
    cin >> n;
    vector<int> nums;
    Nodes.push_back(Node());
    for (int i = 0; i < n; i ++){
        cin >> num;
        nums.push_back(num);
        int now = 0;
        for (int i = 27; i >= 0; --i){
            int bit = (num >> i) & 1;
            if (Nodes[now].Next[bit] == -1){
                Nodes[now].Next[bit] = Nodes.size();
                Nodes.push_back(Node());
            }
            now = Nodes[now].Next[bit];
        }
    }
    for (int i = 0; i < n; i ++){
        int now = 0, ans = 0;
        for (int j = 27; j >= 0; j --){
            int bit = (nums[i] >> j) & 1;
            if (Nodes[now].Next[bit ^ 1] != -1){
                ans |= (1 << j);
                now = Nodes[now].Next[bit ^ 1];
            }
            else{
                now = Nodes[now].Next[bit];
            }
        }
        maxn = max(maxn, ans);
    }
    cout << maxn << endl;
}