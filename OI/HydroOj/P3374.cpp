//树状数组模板
#include <bits/stdc++.h>
using namespace std;

int lowbit(int x) {
    return x & -x;
}

vector<int> a;

int check(int x){
    int ans = 0;
    while (x > 0) {
        ans += a[x];
        x -= lowbit(x);
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    a.resize(n + 5);
    a.assign(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int y = i;
        while (y <= n) {
            a[y] += x;
            y += lowbit(y);
        }
    }
    for (int i = 1; i <= m; i++) {
        int x, y, z, ans = 0;
        cin >> x >> y >> z;
        if (x == 1) {
            while (y <= n) {
                a[y] += z;
                y += lowbit(y);
            }
        } else {
            ans = check(z) - check(y - 1);
            cout << ans << endl;
        }
    }

    return 0;
}