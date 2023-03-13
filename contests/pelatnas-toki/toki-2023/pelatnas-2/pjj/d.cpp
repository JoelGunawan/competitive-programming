#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int lim = 2e5 + 5;
struct disjoint_set {
    int h[lim], sz[lim];
    disjoint_set() {
        memset(h, -1, sizeof(h));
        fill(sz, sz + lim, 1);
    }
    int fh(int nd) {
        return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
    }
    bool merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            sz[x] += sz[y];
            h[y] = x;
        }
        return x != y;
    }
};
int main() {
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    bool special[n + 1];
    memset(special, 0, sizeof(special));
    for(int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        special[x] = 1;
    }
    vector<pair<int, pair<int, int>>> spec, norm;
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if(special[a] ^ special[b]) {
            spec.pb(mp(c, mp(a, b)));
        }
        else
            norm.pb(mp(c, mp(a, b)));
    }
    sort(spec.begin(), spec.end());
    sort(norm.begin(), norm.end());
    // binser antara -1e5 dan +1e5
    // spec di modif sama nilai itu
    // semakin rendah c, semakin banyak spec
    // ambil spec paling dikit (prioritas norm)
    // check max_s using other method
    disjoint_set dum;
    int max_s = 0, min_s = n - 1;
    for(auto i : spec) {
        if(dum.merge(i.se.fi, i.se.se))
            ++max_s;
    }
    memset(dum.h, -1, sizeof(dum.h));
    fill(dum.sz, dum.sz + lim, 1);
    for(auto i : norm) {
        //cout << dum.fh(i.se.fi) << " " << dum.fh(i.se.se) << endl;
        if(dum.merge(i.se.fi, i.se.se))
            --min_s;
    }
    for(auto i : spec)
        dum.merge(i.se.fi, i.se.se);
    //cout << min_s << " " << max_s << endl;
    if(dum.sz[dum.fh(1)] != n)
        cout << -1 << endl, exit(0);
    if(w < min_s || w > max_s)
        cout << -1 << endl, exit(0);
    int lb = 0, rb = 1e5, ans = -1;
    while(lb <= rb) {
        int mb = (lb + rb) / 2;
        // calculate here
        int idxs = 0, idxn = 0, spec_cnt = 0;
        ll cur = 0;
        disjoint_set dsu;
        while(idxs < spec.size() || idxn < norm.size()) {
            if(idxs == spec.size() || (idxn < norm.size() && norm[idxn].fi < spec[idxs].fi + mb)) {
                if(dsu.merge(norm[idxn].se.fi, norm[idxn].se.se))
                    cur += norm[idxn].fi;
                ++idxn;
            }
            else {
                if(dsu.merge(spec[idxs].se.fi, spec[idxs].se.se))
                    cur += spec[idxs].fi + mb, ++spec_cnt;
                ++idxs;
            }
        }
        if(spec_cnt >= w) {
            lb = mb + 1, ans = mb;
        }
        else
            rb = mb - 1;
    }
    // gmn klo max_s ga sampe
    if(ans != -1) {
        int idxs = 0, idxn = 0;
        ll cur = 0;
        disjoint_set dsu;
        int spec_cnt = 0;
        while(idxs < spec.size() || idxn < norm.size()) {
            if(idxs == spec.size() || (idxn < norm.size() && norm[idxn].fi < spec[idxs].fi + ans)) {
                if(dsu.merge(norm[idxn].se.fi, norm[idxn].se.se))
                    cur += norm[idxn].fi;
                ++idxn;
            }
            else {
                if(dsu.merge(spec[idxs].se.fi, spec[idxs].se.se))
                    cur += spec[idxs].fi, ++spec_cnt;
                ++idxs;
            }
        }
        spec_cnt -= w;
        cout << cur + 1ll * spec_cnt * ans << endl;
        return 0;
    }
    // hitung normalnya
    lb = 0, rb = 1e5, ans = -1;
    //cout << "TEST" << endl;
    while(lb <= rb) {
        int mb = (lb + rb) / 2;
        // calculate here
        int idxs = 0, idxn = 0, spec_cnt = 0;
        ll cur = 0;
        disjoint_set dsu;
        while(idxs < spec.size() || idxn < norm.size()) {
            if(idxs == spec.size() || (idxn < norm.size() && norm[idxn].fi + mb <= spec[idxs].fi)) {
                if(dsu.merge(norm[idxn].se.fi, norm[idxn].se.se))
                    cur += norm[idxn].fi + mb; //cout << norm[idxn].se.fi << " " << norm[idxn].se.se << " " << norm[idxn].fi << endl;
                ++idxn;
            }
            else {
                if(dsu.merge(spec[idxs].se.fi, spec[idxs].se.se))
                    cur += spec[idxs].fi, ++spec_cnt; // cout << spec[idxs].se.fi << " " << spec[idxs].se.se << " " << spec[idxs].fi << endl;
                ++idxs;
            }
        }
        //cout << "OUT " << mb << " " << cur << " " << spec_cnt << endl;
        if(spec_cnt <= w) {
            lb = mb + 1, ans = mb;
        }
        else
            rb = mb - 1;
    }
    int idxs = 0, idxn = 0, spec_cnt = 0;
    ll cur = 0;
    disjoint_set dsu;
    while(idxs < spec.size() || idxn < norm.size()) {
        if(idxs == spec.size() || (idxn < norm.size() && norm[idxn].fi + ans <= spec[idxs].fi)) {
            if(dsu.merge(norm[idxn].se.fi, norm[idxn].se.se))
                cur += norm[idxn].fi;
            ++idxn;
        }
        else {
            if(dsu.merge(spec[idxs].se.fi, spec[idxs].se.se))
                cur += spec[idxs].fi, ++spec_cnt;
            ++idxs;
        }
    }
    w -= spec_cnt;
    cout << cur + 1ll * w * ans << endl;
}