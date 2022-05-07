// header file
#include <bits/stdc++.h>
// pragma
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string buang;
    cin >> buang >> buang;
    int n, m, q, t;
    cin >> n >> m >> q >> t;
    pair<int, int> a[m];
    vector<int> p[q];
    for(int i = 0; i < m; ++i) {
        cin >> a[i].fi >> a[i].se;
        p[a[i].se - 1].pb(a[i].fi);
    }
    int k = 0;
    // fi -> val, se.fi -> province, se.se -> peringkat
    priority_queue<pair<int, pair<int, int>>> s;
    for(int i = 0; i < q; ++i) {
        k = max(k, (int)p[i].size());
        sort(p[i].begin(), p[i].end());
        reverse(p[i].begin(), p[i].end());
        for(int j = 0; j < p[i].size(); ++j) {
            s.push(mp(p[i][j], mp(i, j)));
        }
    }
    int ans[k];
    // buat T terbesar nasional
    // pastikan passing gradenya di indeks ke-i itu minimal segitu
    // terus lower passing gradenya hingga valid di tiap indeks
    // waktu mau tambahin ke hasil akhir, kita buat set yg belum kepilih terus kita mulai dari yang paling besar
    // as choosing from biggest itu pasti menghasilkan hasil akhir yang optimal
    fill(ans, ans + k, 100001);
    int cnt = 0;
    map<pair<int, int>, bool> used;
    while(cnt < t) {
        int val = s.top().fi, prov = s.top().se.fi, rank = s.top().se.se;
        ++cnt;
        used[mp(prov, rank)] = 1;
        //cout << val << " " << prov << endl;
        //cout << cnt << " " << val << endl;
        s.pop();
        ans[rank] = val;
    }
    // x.fi -> index, x.se.fi -> val, x.se.se -> prov
    set<pair<int, pair<int, int>>> x;
    for(int i = 0; i < q; ++i) {
        for(int j = 0; j < p[i].size(); ++j) {
            if(!used[mp(i, j)]) {
                x.ins(mp(j, mp(-p[i][j], i)));
                break;
            }
        }
    }
    while(cnt < n) {
        // pilih provinsi yang pesertanya paling dikit
        // cost paling mahal
        int idx = (*x.begin()).fi, prov = (*x.begin()).se.se;
        x.erase(x.begin());
        ans[idx] = p[prov][idx], ++cnt;
        if(idx + 1 < p[prov].size()) {
            x.ins(mp(idx + 1, mp(-p[prov][idx + 1], prov)));
        }
        //cout << idx << " " << p[prov][idx] << endl;
    }
    for(int i = 0; i < k; ++i) {
        cout << ans[i];
        if(i != k - 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}