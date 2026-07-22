#include <bits/stdc++.h>
using namespace std;

string s;
int n, m;
unsigned long long x;
vector<unsigned long long> z;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while (n--)
    {
        cin >> m;
        z.clear();
        while (m--)
        {
            cin >> s;
            if (s == "push")
            {
                cin >> x;
                z.push_back(x);
            }else if (s == "pop")
            {
                if (z.size())
                    z.pop_back();
                else
                    cout << "Empty\n";
            }else if (s == "query")
            {
                if (z.size())
                    cout << z.back() << endl;
                else
                    cout << "Anguei!\n";
            }else if (s == "size")
            {
                cout << z.size() << endl;
            }
        }
    }
    return 0;
}