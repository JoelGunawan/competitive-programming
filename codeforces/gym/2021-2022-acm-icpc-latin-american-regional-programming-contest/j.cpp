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
int w, h;
bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if(a.fi.fi == 0) {
        if(b.fi.fi == 0)
            return a.fi < b.fi;
        else
            return 1;
    }
    else if(a.fi.se == h) {
        if(b.fi.fi == 0)
            return 0;
        else if(b.fi.se == h)
            return a.fi < b.fi;
        else
            return 1;
    }
    else if(a.fi.fi == w) {
        if(b.fi.fi == 0 || b.fi.se == h)
            return 0;
        else if(b.fi.fi == w)
            return a.fi > b.fi;
        else
            return 1;
    }
    else {
        if(b.fi.fi == 0 || b.fi.fi == w || b.fi.se == h)
            return 0;
        else
            return a.fi > b.fi;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> w >> h;
    int n;
    cin >> n;
    // sort the points and use stack algo
    vector<pair<pair<int, int>, int>> points;
    for(int i = 0; i < n; ++i) {
        pair<int, int> a, b;
        cin >> a.fi >> a.se >> b.fi >> b.se;
        if((a.fi == 0 || a.fi == w || a.se == 0 || a.se == h) && (b.fi == 0 || b.fi == w || b.se == 0 || b.se == h))
            points.pb(mp(a, i)), points.pb(mp(b, i));
    }
    bool ans = 1;
    sort(points.begin(), points.end(), comp);
    stack<int> s;
    for(int i = 0; i < points.size(); ++i) {
        //cout << s.size() << endl;
        if(s.size() > 0 && s.top() == points[i].se)
            s.pop();
        else
            s.push(points[i].se);
    }
    if(s.size() == 0)
        cout << "Y" << endl;
    else
        cout << "N" << endl;
    return 0;
}