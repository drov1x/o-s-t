#include <bits/stdc++.h>//字典树的动态实现
using namespace std;

inline int Hash(char c){
    return c - 'a';
}

int ans = 0;

bool Fail = 0;

struct Node{
    Node *alphabet[26];
    bool end;
    int cnt;
    Node(){
        memset(alphabet, 0, sizeof(alphabet));
        end = false;
        cnt = 0;
    }
}*root;

void BuildTrie(string s){
    Node *now = root;
    int c;
    for (int i = 0; i < s.size(); i ++){
        c = Hash(s[i]);
        if (now->alphabet[c] == 0){
            now->alphabet[c] = new Node();
        }
        now = now->alphabet[c];
        now->cnt ++;
    }
    if (!now->end) ans ++;
    now->end = true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n;
    root = new Node();
    ans = 0;
    for (int i = 0; i < n; i ++){
        cin >> s;
        BuildTrie(s);
    }
    cout << ans;
}