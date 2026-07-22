//P5440 奇迹 超级DFS+质数筛

#include <iostream>
#include <set>  
#include <cstring>
using namespace std;

string s;
set<int> primeCount;
int primes[100000000];
int ans;

bool isPrime(int x){
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) {
            primes[x] = -1;
            return false;
        }
    }
    primes[x] = 1;
    return true;
}

bool isPrimePlus(int x){
    if (primes[x] != 0){
        if (primes[x] == 1) return true;
        if (primes[x] == -1) return false;
    }   
    for (int i : primeCount){
        if (x % i == 0){ 
            primes[x] = -1;
            return false;
        }
        if (i * i > x) break;
    }
    primes[x] = 1;
    return true;
}

int ToInt(){
    int res = 0;
    for(char c : s){
        res = res * 10 + (c - '0');
    }
    return res;
}

const int daysInMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

void dfs(int index){
    if (index >= 8){
        int num = ToInt();
        int y = num / 10000, m = (num / 100) % 100, d = num % 100;
        int ry = (int)((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) ? 1 : 0);
        if (m > 12 || m < 1) return;
        if (d > daysInMonth[m] + (m == 2 ? ry : 0) || d < 1) return;

        if (primeCount.find(d) == primeCount.end()) return;
        if (primeCount.find(m*100 + d) == primeCount.end()) return;
        if (!isPrimePlus(num)) return;
        
        ans ++;
        
        return;
    }
    if (index == 6){
        int x = (s[4] - '0') * 10 + (s[5] - '0');
        if (x > 12 || x < 1){
            return ;
        }
    }
    if (index == 4){
        if (s[0] == '0' && s[1] == '0' && s[2] == '0' && s[3] == '0'){
            return ;
        }
    }

    if (s[index] != '-'){
        dfs(index + 1);
    } else {
        for (char c = '0'; c <= '9'; c++){
            s[index] = c;
            dfs(index + 1);
        }
        s[index] = '-';
    }
    return ;
}

int main(){
    for (int i = 1; i <= 10000; i++) {
        if (isPrime(i)) {
            primeCount.insert(i);
        }
    }
    memset(primes, 0, sizeof(primes));

    int t;
    cin >> t;
    while (t--){
        cin >> s;
        if (s[4] != '-' && s[5] != '-'){
            int x = (s[4] - '0') * 10 + (s[5] - '0');
            if (x > 12 || x < 1){
                cout << 0 << endl;
                continue;
            }
        }
        ans = 0;
        dfs(0);
        cout << ans << endl;
    }

}
