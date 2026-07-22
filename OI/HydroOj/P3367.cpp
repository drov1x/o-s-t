#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int find(int x){
    if (a[x] == x){
        return x;
    }
    return a[x] = find(a[x]);//路径压缩
}

void UnionSet(int x, int y){
    int ax = find(x);
    int ay = find(y);//寻找两个变量的父节点
    if (ax == ay){
        return;
    }
    a[ax] = ay;//合并集合
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    a.resize(n + 5);
    for (int i = 0; i < a.size(); i++){
        a[i] = i;//MakeSet
    }
    int x, y, z;
    for (int i = 0; i < m; i++){
        cin >> x >> y >> z;
        if (x == 1){
            UnionSet(y, z);
        }else{
            if (find(y) == find(z)){
                cout << "Y\n";
            }else{
                cout << "N\n";
            }
        }
    }

    return 0;
}