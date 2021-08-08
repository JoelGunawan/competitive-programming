#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int x1, x2, x3, y1, y2, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        int res = abs(x1 - x2) + abs(y1 - y2);
        if((x1 == x2 && x2 == x3 && ((y3 > y1 && y3 < y2) || (y3 < y1 && y3 > y2))) || (y1 == y2 && y2 == y3 && ((x3 > x1 && x3 < x2) || (x3 < x1 && x3 > x2))))
            res += 2;
        cout << res << endl;
    }
}