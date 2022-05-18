#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert
using namespace std;
const int lim = 1e6 + 1;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    pair<int, int> points[n];
    for(int i = 0; i < n; ++i)
        cin >> points[i].fi >> points[i].se;
    // do bitmask of horizontal and vertical
    for(int i = 0; i < (1 << n); ++i) {
        map<int, multiset<int>> vert, hor;
        map<int, int> vc, hc;
        map<pair<int, int>, bool> vis;
        // 0 -> vertical
        // 1 -> horizontal
        // for each axis, add the left most and right most
        for(int j = 0; j < n; ++j) {
            if((1 << j) & i) {
                hor[points[j].fi].ins(points[j].se);
                vert[points[j].se].ins(points[j].fi);
            }
        }
        
        bool valid = 1;
        for(auto i : hor) {
            //cout << i.fi << " " << i.se.size() << endl;
            if(i.se.size() > 2)
                valid = 0;
        }
        for(auto i : vert) {
            //cout << i.fi << " " << i.se.size() << endl;
            if(i.se.size() > 2)
                valid = 0;
        }
        for(int j = 0; j < n; ++j) {
            if(!((1 << j) & i)) {
                // check vert and hor
                bool ans = 0;
                if(vert[points[i].se].size() == 2 && *vert[points[i].se].begin() < points[i].fi && *--vert[points[i].se].end() > points[i].fi)
                    ans = 1;
                else if(hor[points[i].fi].size() == 2 && *hor[points[i].fi].begin() < points[i].se && *--hor[points[i].fi].end() > points[i].se)
                    ans = 1;
                if(!ans)
                    valid = 0;
            }
        }
        cout << endl;
        if(valid) {
            for(int j = 0; j < n; ++j) {
                if((1 << j) & i)
                    cout << '1';
                else
                    cout << '0';
            }
            cout << endl;
            return 0;
        }
    }
}