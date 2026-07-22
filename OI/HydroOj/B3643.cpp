#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mp(n+5, vector<int>(n+5, 0)), list(n+5);
    for (int i = 1; i <= m; i ++){
        int x, y;
        cin >> x >> y;
        mp[x][y] = mp[y][x] += 1;
        list[x].push_back(y);
        list[y].push_back(x);
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cout << mp[i][j] << " ";
        }
        cout << endl;   
    }
    for (int i = 1; i <= n; i ++){
        sort(list[i].begin(), list[i].end());
        cout << list[i].size() << " ";
        for (auto j : list[i]){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}