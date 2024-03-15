#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;
ll cross(pair<ll, ll> a, pair<ll, ll> b) {
    return a.first * b.second - b.first * a.second;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        pair<ll, ll> a, b, c;
        cin >> a.fi >> a.se >> b.fi >> b.se >> c.fi >> c.se;
        // origin p1 (a)
        b.fi -= a.fi;
        b.se -= a.se;
        c.fi -= a.fi;
        c.se -= a.se;
        ll res = cross(b, c);
        if(res > 0)
            cout << "LEFT" << endl;
        else if(res < 0)
            cout << "RIGHT" << endl;
        else
            cout << "TOUCH" << endl;
    }
}