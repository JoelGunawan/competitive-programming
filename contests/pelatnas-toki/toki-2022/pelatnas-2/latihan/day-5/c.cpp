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
ll get_dist(pair<ll, ll> a, pair<ll, ll> b) {
    return (a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se);
}
ll area(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    return (a.fi * b.se) + (b.fi * c.se) + (c.fi * a.se) - (a.se * b.fi) - (b.se * c.fi) - (c.se * a.fi);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // determine congruency by the length of the side of the triangle
    // there are 1e6 triangles
    // sort the triangles by length
    // 1e7/1e8 operations at most?
    int n;
    cin >> n;
    pair<ll, ll> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].fi >> a[i].se;
    vector<pair<vector<ll>, vector<int>>> triangles;
    int idx = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            for(int k = j + 1; k < n; ++k) {
                if(area(a[i], a[j], a[k]) == 0)
                    continue;
                vector<ll> tmp = {get_dist(a[i], a[j]), get_dist(a[i], a[k]), get_dist(a[j], a[k])};
                sort(tmp.begin(), tmp.end());
                vector<int> tmp2 = {i, j, k};
                triangles.pb(mp(tmp, tmp2));
            }
        }
    }
    sort(triangles.begin(), triangles.end());
    int prev = 0;
    ll res = 0;
    // forgor 6 distinct points
    // here, make a data structure that maintains count of int and pair in calculating result
    // find (A U B U C) complement
    // A U B U C = A + B + C - A irisan B - A irisan C - B irisan C
    map<int, int> map1;
    map<pair<int, int>, int> map2;
    for(int i = 0; i < triangles.size(); ++i) {
        // buat special case kalo ada 2 elemen sama
        // buat special case kalo ada 3 elemen sama
        // kalo ada 2 elemen sama kali 2 di res (permutasi)
        // kalo ada 3 elemen sama kali 6 di res (permutasi)
        if(i != 0 && triangles[i].fi == triangles[i - 1].fi) {
            ll add = 0;
            set<ll> tmp;
            for(int j = 0; j < 3; ++j)
                add += map1[triangles[i].se[j]], tmp.ins(triangles[i].fi[j]);
            for(int j = 0; j < 3; ++j) {
                for(int k = j + 1; k < 3; ++k) {
                    add -= map2[mp(triangles[i].se[j], triangles[i].se[k])];                   
                }
            }
            if(tmp.size() == 3)
                res += (prev - add);
            else if(tmp.size() == 2)
                res += 2 * (prev - add);
            else
                res += 6 * (prev - add);
        }
        else
            map1.clear(), map2.clear(), prev = 0;
        ++prev;
        for(int j = 0; j < 3; ++j)
            ++map1[triangles[i].se[j]];
        for(int j = 0; j < 3; ++j) {
            for(int k = j + 1; k < 3; ++k) {
                ++map2[mp(triangles[i].se[j], triangles[i].se[k])];
            }
        }
    }
    cout << 2 * res << endl;
    return 0;
}