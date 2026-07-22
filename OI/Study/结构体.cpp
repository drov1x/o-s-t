#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
    Point(int x = 0, int y = 0):x(x), y(y) {}
};

Point operator+(Point &a, Point &b) 
{
    return Point(a.x + b.x, a.y + b.y);
}

ostream& operator<<(ostream &aaa, const Point &b) 
{
    aaa << '(' << b.x << ", " << b.y << ')' << endl;
    return aaa;
}

int main() 
{
    Point a, b;
    cin >> a.x >> b.x >> a.y >> b.y;
    cout << (a + b) << endl;
    return 0;
}