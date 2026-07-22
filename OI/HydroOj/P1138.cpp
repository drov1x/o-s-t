#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    set<int> s;
    int n, k, x;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.insert(x);
    }
    if (k > s.size())
    {
        cout << "NO RESULT" << endl;
        return 0;
    }
    auto key = s.begin();
    key = next(key, k - 1);
    cout << *key << endl;

    return 0;
}