#include <iostream>
#include <cstdio>
#include <ios>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

struct action
{
    long long act, x;
}a;
string s;
long long n, x, m;
vector<long long> f;
vector<action> act;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    act.push_back({ 1, 1 });
    while (s != "END")
    {
        if (s == "NUM")
        {
            cin >> a.x;
            a.act = 1;
        }
        else if (s == "POP")
            a.act = 2;
        else if (s == "INV")
            a.act = 3;
        else if (s == "DUP")
            a.act = 4;
        else if (s == "SWP")
            a.act = 5;
        else if (s == "ADD")
            a.act = 6;
        else if (s == "SUB")
            a.act = 7;
        else if (s == "MUL")
            a.act = 8;
        else if (s == "DIV")
            a.act = 9;
        else if (s == "MOD")
            a.act = 10;
        act.push_back(a);
        cin >> s;
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> act[0].x;
        f.clear();
        m = act.size();
        for (int i = 0; i < m; i++)
        {
            switch (act[i].act)
            {
            case 1://NUM 压栈
            {
                x = act[i].x;
                if (abs(x) > 1e9)
                {
                    cout << "ERROR\n";
                    goto ed;
                }
                else
                {
                    f.push_back(x);
                }
                break;
            }
            case 2://POP抛栈顶
            {
                if (f.size())
                    f.pop_back();
                else
                {
                    cout << "ERROR\n";
                    goto ed;
                }
                break;
            }
            case 3://INV取栈顶相反数
            {
                if (!f.size())
                {
                    cout << "ERROR\n";
                    goto ed;
                }
                f.back() = -1 * f.back();
                break;
            }
            case 4://DUP重复放入相同的元素
            {
                f.push_back(f.back());
                break;
            }
            case 5://SWP交换栈顶两个元素
            {
                x = f.size();
                if (f.size() < 2)
                {
                    cout << "ERROR\n";
                    goto ed;
                }
                f[x - 1] += f[x - 2];
                f[x - 2] = f[x - 1] - f[x - 2];
                f[x - 1] -= f[x - 2];
                break;
            }
            case 6://ADD将栈顶两元素取出、相加、压栈
            {
                if (!f.size())
                {
                    cout << "ERROR\n";
                    goto ed;
                }
                x = f.back();
                f.pop_back();
                f.back() += x;
                if (abs(f.back()) > 1e9)
                {
                    cout << "ERROR\n";
                    goto ed;
                }
                break;
            }
            case 7://SUB栈顶两元素取出、相减、压栈
            {
                if (!f.size())
                {
                    cout << "ERROR\n";
                    goto ed;
                }
                x = f.back();
                f.pop_back();
                f.back() -= x;
                if (abs(f.back()) > 1e9)
                {
                    cout << "ERROR\n";
                    goto ed;
                }
                break;
            }
            case 8://MUL相乘
            {
                if (!f.size())
                {
                    cout << "ERROR\n";
                    goto ed;
                }
                x = f.back();
                f.pop_back();
                f.back() *= x;
                if (abs(f.back()) > 1e9)
                {
                    cout << "ERROR\n";
                    goto ed;
                }
                break;
            }
            case 9://DIV相除
            {
                if (!f.size())
                {
                    cout << "ERROR\n";
                    goto ed;
                }
                x = f.back();
                f.pop_back();
                if (x == 0)
                {
                    cout << "ERROR\n";
                    goto ed;
                }
                f.back() = (int)(f.back() / x);
                break;
            }
            case 10://MOD取模
            {
                if (!f.size())
                {
                    cout << "ERROR\n";
                    goto ed;
                }
                x = f.back();
                f.pop_back();
                if (x == 0)
                {
                    cout << "ERROR\n";
                    goto ed;
                }
                f.back() %= x;
                break;
            }
            }
        }
        if (f.size() != 1)
        {
            cout << "ERROR\n";
            goto ed;
        }
        cout << f.back() << endl;
    ed:continue;
    }
    return 0;
}