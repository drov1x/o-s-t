#include <iostream>
//#include <cstdio>
#include <ios>
//#include <cmath>
//#include <cstring>
//#include <vector>
#include <queue>
using namespace std;

int n, x, y;
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--)
    {
        cin >> x;
        switch (x)
        {
            case 1:
            {
                cin >> y;
                q.push(y);
                break;
            }
            case 2:
            {
                if (q.size())
                    q.pop();
                else
                    cout << "ERR_CANNOT_POP\n";
                break;
            }
            case 3:
            {
                if (q.size())
                    cout << q.front() << endl;
                else
                    cout << "ERR_CANNOT_QUERY\n";
                break;
            }
            case 4:
            {
                cout << q.size() << endl;
                break;
            }
        }


    }


    
    return 0;
}