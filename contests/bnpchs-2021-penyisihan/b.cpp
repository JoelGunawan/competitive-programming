#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lll __int128
#define ulll unsigned __int128
#define pb push_back
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define x first
#define y second
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
bool intersect(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b)
{
    if(a == b)
        return 1;
    else if(a.first.y == a.second.y && b.first.x == b.first.x)
        return a.first.x < b.first.x && a.second.x > b.first.x && b.first.y < a.first.y && b.second.y > a.first.y;
    else if(a.first.x == a.second.x && b.first.y == b.second.y)
        return b.first.x < a.first.x && b.second.x > a.first.x && a.first.y < b.first.y && a.second.y > b.first.y;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    pair<pair<int, int>, pair<int, int>> points[n];
    for(int i = 0; i < n; ++i)
        cin >> points[i].first.x >> points[i].first.y >> points[i].second.x >> points[i].second.y;
    int x1, y1, x2, y2;
    while(q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        // determine whether 2 lines intersect
        int res = 0;
        for(int i = 0; i < n; ++i)
            if(intersect(points[i], {{x1, y1}, {x2, y2}}))
                ++res;
        cout << res << endl;
    }
    return 0;
}