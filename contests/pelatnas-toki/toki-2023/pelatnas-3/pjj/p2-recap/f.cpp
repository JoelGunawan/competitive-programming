#include <bits/stdc++.h>
#define ll long long
#define lll __int128
using namespace std;
const int lim = 2e5 + 5;
struct operations {
    int type, school, count, u, v;
};
struct query {
    int l, r, s, t, ans, num;
    long long k;
    const bool operator<(const query& a) const {
        return (a.l + a.r) / 2 < (l + r) / 2;
    }
};
struct disjoint_set {
    long long cnt[lim];
    int h[lim], sz[lim];
    disjoint_set() {
        memset(cnt, 0, sizeof(cnt));
        memset(h, -1, sizeof(h));
        fill(sz, sz + lim, 1);
    }
    int fh(int nd) {
        return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
    }
    void merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            sz[x] += sz[y];
            h[y] = x;
            //cout << x << " " << y << " " << cnt[x] << " " << cnt[y] << endl;
            cnt[x] += cnt[y];
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, d, s;
    cin >> n >> m >> d >> s;
    // dibuat dsu dr belakang ke depan, terus nanti diparalel binser jawabannya
    int stud[n + 1];
    for(int i = 1; i <= n; ++i) {
        // students
        cin >> stud[i];
    }
    vector<pair<int, int>> edges;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({min(u, v), max(u, v)});
    }
    operations a[d];
    vector<pair<int, int>> del;
    for(int i = 0; i < d; ++i) {
        operations tmp;
        cin >> tmp.type;
        if(tmp.type == 1) {
            cin >> tmp.u >> tmp.v;
            // remove dr edge
            del.push_back({min(tmp.u, tmp.v), max(tmp.u, tmp.v)});
        }
        else {
            cin >> tmp.school >> tmp.count;
            // remove dr school
            stud[tmp.school] -= tmp.count;
        }
        a[i] = tmp;
    }
    sort(del.begin(), del.end());
    vector<pair<int, int>> buang;
    for(auto i : edges) {
        if(!binary_search(del.begin(), del.end(), i))
            buang.push_back(i);
    }
    edges = buang;
    buang.clear(), del.clear();
    reverse(a, a + d);
    vector<query> nxt;
    for(int i = 0; i < s; ++i) {
        query x;
        cin >> x.s >> x.t >> x.k;
        x.l = 0, x.r = d, x.ans = d + 1;
        x.num = i;
        nxt.push_back(x);
    }
    int res[s];
    memset(res, -1, sizeof(res));
    for(int te = 0; te < 18; ++te) {
        vector<query> q[d + 1];
        //cout << nxt.size() << endl;
        for(auto i : nxt) {
            q[(i.l + i.r) / 2].push_back(i);
        }
        nxt.clear();
        disjoint_set dsu;
        for(int i = 1; i <= n; ++i)
            dsu.cnt[i] = stud[i];
        for(auto i : edges)
            dsu.merge(i.first, i.second);
        for(int i = 0; i <= d; ++i) {
            // cek dlu, baru lakuin operasinya
            for(auto j : q[i]) {
                int x = dsu.fh(j.s), y = dsu.fh(j.t);
                //cout << x << " " << y << endl;
                //cout << dsu.cnt[x] << " " << dsu.cnt[y] << endl;
                if(dsu.cnt[x] + dsu.cnt[y] >= j.k) {
                    j.r = i - 1;
                    j.ans = i;
                }
                else
                    j.l = i + 1;
                //cout << i << endl;
                //cout << "OUTPUT " << dsu.cnt[x] + dsu.cnt[y] << " " << j.k << " " << j.num << " " << j.l << " " << j.r << endl;
                if(j.l <= j.r) {
                    nxt.push_back(j);
                }
                else {
                    res[j.num] = j.ans;
                }
            }
            if(i == d)
                break;
            if(a[i].type == 1) {
                dsu.merge(a[i].u, a[i].v);
            }
            else {
                dsu.cnt[dsu.fh(a[i].school)] += a[i].count;
            }
        }
    }
    for(auto i : res)
        cout << d - i << endl;
}