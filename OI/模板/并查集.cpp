#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> t;

int findp(int x){
    int r = x;
    while (t[r] >= 0) r = t[r];
    while (x != r) { int nxt = t[x]; t[x] = r; x = nxt; }
    return r;
}

void unite(int x, int y){
    x = findp(x); y = findp(y);
    if (x == y) return;
    if (-t[x] < -t[y]) swap(x, y);
    t[x] += t[y];
    t[y] = x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    t.resize(n + 4, -1);
    int k, x, y;
    while (m--){
        cin >> k >> x >> y;
        if (k == 1){
            unite(x, y);
        }
        else{
            if (findp(x) == findp(y)) cout << "Y\n";
            else cout << "N\n";
        }
    }


}