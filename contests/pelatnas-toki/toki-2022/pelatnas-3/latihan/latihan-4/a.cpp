// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
const int lim = 150000 + 5;
struct fenwick {
    int a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, int val) {
        while(idx < lim) {
            a[idx] += val;
            idx += (idx&-idx);
        }
    }
    int query(int idx) {
        int res = 0;
        while(idx > 0) {
            res += a[idx];
            idx -= (idx&-idx);
        }
        return res;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
struct line {
    // fi.fi start pos, fi.se start idx, se end pos
    // transition index paling banyak sqrt
    vector<pair<pair<int, int>, int>> transition_index = {};
    // array
    vector<int> arr = {}, pos = {};
    // shift value, tiap access, kurangi shift
    // sz -> size of arr
    int shift = 0, sz;
    int get(int idx) {
        return arr[(((idx - shift) % sz) + sz) % sz];
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    // square root decomp
    // every square root of n queries, build prefsum
    // use BIT for the range query (normal)
    // for >= 200, count for each, use binser for each
    // for all <= 200, count
    // coba 1e9 <= 3s
    // or use mo for update
    // kita tahu kalo updatenya itu melingkar, tapi kita pending update aja yang penting sumnya sama
    // update sqrt
    // query sqrt
    // waktu update, kita tinggal cek transisi antara tiap sqrt blok itu berapa, ga usah catat yang di dalam sqrt blok
    // waktu query, tinggal query sum sqrt, di tiap indeks, cari shift berapa dari keretanya in O(1)
    // tiap jalur, precompute transisi index mana aja
    // tiap index di array, kita compute
    int s = ceil(sqrt(n * 1.0));
    line lines[m];
    int l[n], a[n], order[n];
    for(int i = 0; i < n; ++i) {
        cin >> l[i];
        --l[i];
        order[i] = lines[l[i]].pos.size();
        lines[l[i]].pos.pb(i);
    }
    int block[n];
    for(int i = 0; i < n; ++i) {
        block[i] = i / s;
    }
    int decomp[s + 1];
    memset(decomp, 0, sizeof(decomp));
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        //cout << "BLOCK " << block[i] << " " << a[i] << endl;
        decomp[block[i]] += a[i];
        lines[l[i]].arr.pb(a[i]);
    }
    for(int i = 0; i < m; ++i)
        lines[i].sz = lines[i].arr.size();
    for(int i = 0; i < m; ++i) {
        // get transition index
        for(int j = 0; j < lines[i].sz; ++j) {
            int pr = (j - 1 + lines[i].sz) % lines[i].sz;
            if(block[lines[i].pos[j]] != block[lines[i].pos[pr]]) {
                lines[i].transition_index.pb(mp(mp(block[lines[i].pos[pr]], pr), block[lines[i].pos[j]]));
                //cout << "TRANS " << i << " " << lines[i].pos[pr] << " " << lines[i].pos[j] << endl;
            }
        }
    }
    //cout << "CHECK " << decomp[1] << endl;
    for(int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if(t == 1) {
            // query sqrt decomp
            int x, y;
            cin >> x >> y;
            --x, --y;
            int cl = block[x], cr = block[y], sum = 0;
            //cout << x << " " << y << " " << cl << " " << cr << endl;
            if(cl == cr) {
                for(int i = x; i <= y; ++i)
                    sum += lines[l[i]].get(order[i]);   
            }
            else {
                for (int i = x; i <= (cl + 1) * s - 1; ++i)
                    sum += lines[l[i]].get(order[i]);   
                //cout << sum << endl;
                for(int i = cl + 1; i < cr; ++i)
                    sum += decomp[i];
                //cout << sum << endl;
                for(int i = cr * s; i <= y; ++i)
                    sum += lines[l[i]].get(order[i]);   
                //cout << sum << endl;
            }
            cout << sum << endl;
        }
        else {
            // update sqrt decomp
            int x;
            cin >> x;
            --x;
            for(pair<pair<int, int>, int> &i : lines[x].transition_index) {
                int &start_idx = i.fi.fi, &end_idx = i.se, &idx = i.fi.se;
                //cout << "UPD " << start_idx << " " << end_idx << " " << lines[x].get(idx) << endl;
                decomp[end_idx] += lines[x].get(idx);
                decomp[start_idx] -= lines[x].get(idx);
            }
            ++lines[x].shift;
        }
    }
    return 0;
}