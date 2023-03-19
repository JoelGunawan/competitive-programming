#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define endl "\n"
using namespace std;
const int lim = 5e5 + 5;
struct disjoint_set {
    map<int, int> a[lim];
    int h[lim], sz[lim], l[lim], r[lim];
    disjoint_set() {
        memset(h, -1, sizeof(h));
        fill(sz, sz + lim, 1);
        for(int i = 1; i < lim; ++i)
            l[i] = i, r[i] = i;
    }
    int fh(int nd) {
        return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
    }
    bool merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            h[y] = x;
            sz[x] += sz[y];
            if(a[y].size() < a[x].size())
                swap(a[x], a[y]);
            for(auto i : a[y])
                a[x][i.fi] += i.se;
            a[y].clear();
            l[x] = min(l[x], l[y]);
            r[x] = max(r[x], r[y]);
            // max isi vektor sebanyak mlog saja
        }
        return x != y;
    }   
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> pr[n + 1];
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        pr[v].pb(u);
        //cout << v << " " << u << endl;
    }
    for(int i = 1; i <= n; ++i) {
        sort(pr[i].begin(), pr[i].end(), greater<int>());
    }
    // buat tc s[j] = 1
    // pakai prefix sum of possible
    // utk n <= 2000
    // coba terapin dp ini, tapi kita pakai 2 state, jadinya lebih efisien
    // problem -> high m, dikali n nanti g mungkin nutut
    // jadi harus murni O(N^2)
    // sub 5 -> sqrt()?
    // maintain ke tiap sqrt lain ada berapa aja, untuk detailnya ga usah di maintain tapi
    // pake teknik mo, nanti dia maju terus mundur
    // range intersect -> boleh digabung jadi lebih besar
    // problem: find all range intersects?
    bool vis[n + 1];
    int pref[n + 1][n + 1];
    memset(pref, 0, sizeof(pref));
    // sort pr, paling pendek ke paling jauh
    for(int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof(vis));
        for(int j = 0; j < pr[i].size(); ++j) {
            int tmp = pr[i][j], nx = 1;
            pref[i][tmp] = 1;
            if(j != pr[i].size() - 1)
                nx = pr[i][j + 1];
            for(int k = tmp - 1; k >= nx - 1; --k) {
                pref[i][k] = min(1, pref[i - 1][k] - pref[tmp - 2][k]);
            }
        }
        //
        //for(auto j : pr[i]) {
        //    pref[i][j] = 1;
        //    // tiap edge kita query lebih dari yang mungkin
        //    for(int k = j - 1; k >= 1; --k) {
        //        pref[i][k] = min(1, pref[i - 1][k] - pref[j - 2][k]);
        //    }
        //}
        for(int j = 1; j < i; ++j) {
            pref[i][j] += pref[i - 1][j];
            //cout << pref[i][j] << " ";
        }
        //cout << endl;
        // for everything di tengah
        //cout << "CUR IS " << i << endl;
        //for(auto j : possible[i])
        //    cout << j << " ";
        //cout << endl;
    }
    for(int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        if(pref[r][l] - pref[r - 1][l] == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    /*
    vector<pair<int, int>> query[n];
    for(int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        query[r].pb(mp(l, i));
    }
    vector<int> cur;
    disjoint_set dsu;
    bool ans[q];
    memset(ans, 0, sizeof(ans));
    for(int i = 1; i <= n; ++i) {
        // proc all queries ending in R
        int min_pr = 1e9, mx_pr = 0;
        //cout << "EDGES" << endl;
        for(auto j : pr[i]) {
            min_pr = min(j, min_pr), mx_pr = max(mx_pr, j), dsu.a[i][j]++;
            //cout << j << " ";
        }
        //cout << endl;
        //cout << "PR " << min_pr << " " << mx_pr << endl;
        while(cur.size() && dsu.r[cur.back()] >= min_pr - 1) {
            //cout << "OUTPUT " << dsu.r[cur.back()] << " " << min_pr << endl;
            dsu.merge(cur.back(), i), cur.pop_back();
        }
        // harus sort edges, supaya karena bisa jadi dia "skip" beberapa dsu
        // kalo ada dsu yang di skip -> masalah
        // hanya dsu yang ada di antara min_pr dan max_pr yang bisa diambil sebenernya
        // di bawah itu gabisa diambil
        // cari range answer di tengah"nya yang lebih dari cur
        // kalo buat yang cur, dia harus strictly larger dari elemen yg kita merge
        int tmp = dsu.fh(i);
        for(auto j : query[i]) {
            if(j.fi <= mx_pr && dsu.a[tmp][j.fi] != 0) {
                //cout << j.fi << " " << mx_pr << " " << dsu.a[tmp][j.fi] << endl;
                ans[j.se] = 1;
            }
        }
        cur.pb(tmp);
        //for(auto i : cur)
            //cout << dsu.l[i] << " " << dsu.r[i] << endl;
        //cout << endl;
    }
    for(auto i : ans) {
        if(i)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    // offline query
    // sort all by l
    // nanti bisa merging pakai dsu
    */
}