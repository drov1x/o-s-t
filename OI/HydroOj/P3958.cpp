#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
vector<int> mp;
int n, h, r;
struct ball{
    int x, y, z;
};
vector<ball> balls;

int find(int x){
    if (mp[x] == x){
        return x;
    }
    return mp[x] = find(mp[x]);
}

void UnionSet(int a, int b){
    int fa = find(a);
    int fb = find(b);
    if (fa != fb){
        mp[fb] = fa;
    }
}

int main(){
    int k;
    cin >> k;
    while (k--){;
        cin >> n >> h >> r;
        mp.clear();
        mp.assign(n, 0);
        balls.clear();
        int x, y, z;
        for (int i = 0; i < n; i++){
            cin >> x >> y >> z;
            balls.push_back({x, y, z});
        }
        sort(balls.begin(), balls.end(), [](const ball &a, const ball &b){
            return a.z < b.z;
        });
        for (int i = 0; i < n; i ++){
            mp[i] = i;
		}
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i != j){
                    int dx = balls[i].x - balls[j].x;
                    int dy = balls[i].y - balls[j].y;
                    int dz = balls[i].z - balls[j].z;
                    if ((long long)dx * dx + (long long)dy * dy + (long long)dz * dz <= 4 * (long long)r * r && find(i) != find(j)){
                        UnionSet(i, j);
                    }
                }
            }
        }
        for (int i = 0; i < n && balls[i].z - r <= 0; i++){
            for (int j = n - 1; j >= 0 && balls[j].z + r >= h; j--){
                if (find(i) == find(j)){
                    cout << "Yes" << endl;
                    goto end;
                }
            }
        }   
        cout << "No" << endl;
        end:;
    }


    return 0;
}