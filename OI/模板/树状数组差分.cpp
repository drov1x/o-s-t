#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & -x)  

int n, m;
vector<int> a;



void ip(int index, int value){
    for (int i = index; i <= n; i += lowbit(i)){
        a[i] += value;
    }
}

int take(int index){
    int res = 0;
    for (int i = index; i > 0; i -= lowbit(i)){
        res += a[i];
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    a.resize(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ip(i, x);
        ip(i + 1, -x);
    }

    for (int i = 1; i <= m; i++) {
        int k, x, y, v;
        cin >> k;
        if (k == 1){
            cin >> x >> y >> v;
            ip(x, v);
            ip(y + 1, -v);
        }else{
            cin >> x;
            cout << take(x) << "\n";
        }
    }

}