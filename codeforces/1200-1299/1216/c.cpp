// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
struct point {
    point() {
        x = 0, y = 0;
    }
    point(int a, int b) {
        x = a, y = b;
    }
    int x, y;
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pair<point, point> rectangles[3];
    for(int i = 0; i < 3; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        rectangles[i] = mp(point(a, b), point(c, d));
    }
    bool ans = 0;
    for(double i = 0; i <= 1e6; i += 0.5) {
        if(i >= rectangles[0].fi.x && i <= rectangles[0].se.x) {
            vector<pair<int, int>> blocked;
            if(i >= rectangles[1].fi.x && i <= rectangles[1].se.x) {
                blocked.pb(mp(rectangles[1].fi.y, rectangles[1].se.y));
            }
            if(i >= rectangles[2].fi.x && i <= rectangles[2].se.x) {
                blocked.pb(mp(rectangles[2].fi.y, rectangles[2].se.y));
            }
            sort(blocked.begin(), blocked.end());
            if(blocked.size() > 1) {
                if(blocked[1].fi <= blocked[0].se)
                    blocked = {mp(blocked[0].fi, max(blocked[0].se, blocked[1].se))};
            }
            bool fully_blocked = 0;
            for(auto i : blocked) {
                // if covers completely
                //cout << i.fi << " " << i.se << endl;
                if(rectangles[0].fi.y >= i.fi && rectangles[0].se.y <= i.se)
                    fully_blocked = 1;
            }
            if(!fully_blocked) {
                //cout << i << endl;
                ans = 1;
            }
        }
    }
    if(ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}