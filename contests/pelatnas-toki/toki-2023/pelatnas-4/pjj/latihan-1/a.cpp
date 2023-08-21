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
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
struct Edge {
    lll tgt, dist, type;
    Edge(int a, int b, int c) {
        tgt = a, dist = b, type = c;
    }
    const bool operator< (const Edge &rhs) const {
        return true;
    }
};
lll cei(lll a, lll b) {
    if(a % b == 0)
        return a / b;
    else
        return a / b + 1;
}
lll inv(lll a, lll b) {
    if(a % b == 0)
        return 0;
    else
        return b - (a % b);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string sbsoal;
    cin >> sbsoal;
    int v, e;
    cin >> v >> e;
    ll costd, mxd, costp, mxp;
    cin >> costd >> mxd >> costp >> mxp;
    int a, b;
    cin >> a >> b;
    vector<Edge> edges[v + 1];
    for(int i = 1; i <= e; ++i) {
        int x, y, k, q;
        cin >> x >> y >> k >> q;
        edges[x].pb(Edge(y, k, q));
        edges[y].pb(Edge(x, k, q));
    }
    // kita buat ke tiap node, cek mau pake excess maximum atau nggak
    // kemungkinan:
    // ojek pangkalan lebih murah: cari shortest path murni
    // ojek daring lebih murah: cari shortest path menggunakan ojek daring digabung, coba tiap distance, tapi boleh stop kapanpun
    lll dist[v + 1][100];
    for(int i = 1; i <= v; ++i) {
        for(int j = 0; j < 100; ++j)
            dist[i][j] = 1e36;
    }
    // fi -> dist
    // se.fi -> node
    // se.se -> extra
    priority_queue<pair<lll, pair<int, int>>, vector<pair<lll, pair<int, int>>>, greater<pair<lll, pair<int, int>>>> pq;
    pq.push(mp(0, mp(a, 0)));
    lll lastd = 0;
    bool done[v + 1][v + 1];
    memset(done, 0, sizeof(done));
    while(pq.size()) {
        lll d = pq.top().fi; int nd = pq.top().se.fi;
        ll extra = pq.top().se.se;
        //cout << d << " " << nd << " " << extra << endl;
        //cout.flush();
        assert(d >= lastd);
        lastd = d;
        pq.pop();
        if(dist[nd][extra] <= d)
            continue;
        for(int j = extra; j >= 0; --j) {
            if(dist[nd][j] > d)
                dist[nd][j] = d;
            else
                break;
        }
        // coba pakai extra utk ke lainnya
        for(auto i : edges[nd]) {
            if(i.type) {
                // cmn boleh ojek pangkalan
                if(extra >= i.dist) {
                    //cout << extra << " " << i.dist << endl;
                    // lgsg ke next
                    if(d < dist[i.tgt][extra - i.dist])
                        pq.push(mp(d, mp(i.tgt, extra - i.dist)));
                }
                else {
                    // tambahkan ojek pangkalan
                    //cout << d << " " << i.dist - extra << " " << mxp << " " << costp << endl;
                    //cout << d + 1ll * cei((i.dist - extra), mxp) * costp << endl;
                    //cout << d + 1ll * cei((i.dist - extra), mxp) * costp << endl;
                    if(d + 1ll * cei((i.dist - extra), mxp) * costp < dist[i.tgt][inv(i.dist - extra, mxp)]) {
                        pq.push(mp(d + 1ll * cei((i.dist - extra), mxp) * costp, mp(i.tgt, inv(i.dist - extra, mxp))));
                    }
                }
                // pakai ojek daring dulu (buang ekstra), baru pakai ojek pangkalan
                if(mxd >= i.dist) {
                    // full daring
                    //cout << d + 1ll * i.dist * costd << endl;
                    if(dist[i.tgt][0] > d + 1ll * i.dist * costd)
                        pq.push(mp(d + 1ll * i.dist * costd, mp(i.tgt, 0)));
                }
                // consider case padding dengan ojek daring dulu, baru tambahin ojek pangkalan (misal klo ojek daring gabisa)
                // partial daring dan pangkalan (buat daring supaya pangkalannya pas, bs maximize pangkalan ataupun daring)
                // maximize pangkalan, daring cuman buat paskan
                if((i.dist % mxp) <= mxd && dist[i.tgt][0] > d + 1ll * costd * (i.dist % mxp) + 1ll * i.dist / mxp * costp)
                    pq.push(mp(d + 1ll * costd * (i.dist % mxp) + 1ll * i.dist / mxp * costp, mp(i.tgt, 0)));
                if(!done[nd][i.tgt]) {
                    done[nd][i.tgt] = 1;
                    // jadi use yg dist 0 dr tempat itu buat cri max dist ke tempat lain itu brp
                    for(int j = 1; j <= mxd; ++j) {
                        // use i amount of ojek daring, sisanya pakai ojek pangkalan
                        if(i.dist < j)
                            break;
                        ll cst = costd * j;
                        if(d + 1ll * cei((i.dist - j), mxp) * costp + cst < dist[i.tgt][inv(i.dist - j, mxp)]) {
                            pq.push(mp(d + 1ll * cei((i.dist - j), mxp) * costp + cst, mp(i.tgt, inv(i.dist - j, mxp))));
                        }
                    }
                }
                // maximize daring, tp paskan supaya pangkalan g overshoot city
                ll pcnt = cei(i.dist - mxd, mxp);
                if((i.dist - 1ll * mxp * pcnt) >= 0 && (i.dist - 1ll * mxp * pcnt) <= mxd && pcnt >= 0 && dist[i.tgt][0] > d + 1ll * costd * (i.dist - 1ll * mxp * pcnt) + 1ll * costp * pcnt)
                    pq.push(mp(d + 1ll * costd * (i.dist - 1ll * mxp * pcnt) + 1ll * costp * pcnt, mp(i.tgt, 0)));
            }
            else {
                // boleh pangkalan atau daring  
                // pangkalan: sama dengan case atas
                // daring: hitung murni distance ke target berapa
                // cmn pakai ojek pangkalan
                // cmn boleh ojek pangkalan
                if(extra >= i.dist) {
                    // lgsg ke next
                    if(d < dist[i.tgt][extra - i.dist])
                        pq.push(mp(d, mp(i.tgt, extra - i.dist)));
                }
                else {
                    // tambahkan ojek pangkalan
                    if(d + 1ll * cei((i.dist - extra), mxp) * costp < dist[i.tgt][inv(i.dist - extra, mxp)]) {
                        pq.push(mp(d + 1ll * cei((i.dist - extra), mxp) * costp, mp(i.tgt, inv(i.dist - extra, mxp))));
                    }
                }
                // pakai ojek daring dulu (buang ekstra), baru pakai ojek pangkalan
                // partial daring dan pangkalan (buat daring supaya pangkalannya pas, bs maximize pangkalan ataupun daring)
                // maximize pangkalan, daring cuman buat paskan
                // bisa jadi ojek daring di pakai buat "pas"kan dr ojek pangkalan
                // kenapa tdk boleh pakai ekstra di sini?
                //if(dist[i.tgt][0] > d + 1ll * costd * (i.dist % mxp) + 1ll * i.dist / mxp * costp)
                //    pq.push(mp(d + 1ll * costd * (i.dist % mxp) + 1ll * i.dist / mxp * costp, mp(i.tgt, 0)));
                // maximize daring, tp paskan supaya pangkalan g overshoot city
                // why tho???
                // harusnya case ini gperna dateng
                //int pcnt = (i.dist - mxd) / mxp;
                //if(pcnt >= 0 && && dist[i.tgt][0] > d + 1ll * costd * (i.dist - 1ll * mxp * pcnt) + 1ll * costp * pcnt)
                //    pq.push(mp(d + 1ll * costd * (i.dist - 1ll * mxp * pcnt) + 1ll * costp * pcnt, mp(i.tgt, 0)));
                ll ndist = i.dist - extra;
                if(ndist >= 0) {
                    // maximize pangkalan tp end precisely di kota tujuan
                    if(dist[i.tgt][0] > d + 1ll * costd * (ndist % mxp) + 1ll * ndist / mxp * costp)
                        pq.push(mp(d + 1ll * costd * (ndist % mxp) + 1ll * ndist / mxp * costp, mp(i.tgt, 0)));
                }
                // jadi yg bawah ini ojek daring doang :D
                if(i.dist >= extra && (dist[i.tgt][0] > d + 1ll * costd * (i.dist - extra))) {
                    pq.push(mp(d + 1ll * costd * (i.dist - extra), mp(i.tgt, 0)));
                }
                
            }
        }
    }
    assert(dist[b][0] <= 1e18);
    cout << (ll)dist[b][0] << endl;
    return 0;
}