#include <bits/stdc++.h>
using namespace std;

const int x1[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int yowww[8] = {2, 1, -1, -2, -2, -1, 1, 2};


int main(){
    int x, xx, y, yy;
    cin >> x >> y >> xx >> yy;
    long long mp[25][25];
    memset(mp, 0, sizeof(mp));
    for (int i = 0; i < 8; i ++){
        int x2 = x1[i] + xx;
        int y2 = yowww[i] + yy;
        if (x2 >= 0 && x2 <= x && y2 >= 0 && y2 <= y){
            mp[x2+1][y2+1] = -1;
        }
    }
    mp[xx+1][yy+1] = -1;
    mp[1][1] = 1;
    for (int i = 1; i <= x+1; i ++){
        for (int j = 1; j <= y+1; j ++ ){
            if (mp[i][j] != -1){
                mp[i][j] += max(mp[i-1][j], 0LL) + max(mp[i][j-1], 0LL);
            }
        }
    }
    cout << max(mp[x+1][y+1], 0LL);
    return 0;
}