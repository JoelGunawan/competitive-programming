#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pb push_back
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int W, H, x1, y1, x2, y2, w, h;
        cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
        if(x2 - x1 + w > W && y2 - y1 + h > H)
        {
            cout << -1 << endl;
            continue;
        }
        if(x2 - x1 + w > W)
        {
            // we need to move the y
            int bottomy = y1, topy = H - y2;
            cout << min(max(0, h - bottomy), max(0, h - topy)) << endl;
        }
        else if(y2 - y1 + h > H)
        {
            int leftx = x1, rightx = W - x2;
            cout << min(max(0, w - leftx), max(0, w - rightx)) << endl;
        }
        else
            cout << min(min(max(0, h - y1), max(0, h + y2 - H)), min(max(0, w - x1), max(0, w + x2 - W))) << endl;
    }
    return 0;
}