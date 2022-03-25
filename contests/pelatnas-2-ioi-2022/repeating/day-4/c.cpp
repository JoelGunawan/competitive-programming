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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    bool d[n + 1][m];
    memset(d, 0, sizeof(d));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) {
            char x;
            cin >> x;
            d[i + 1][j] = x == '#';
        }
    //  check how to use n, m
    vector<pair<int, int>> submask[1 << m];
    int vert[1 << m], bitmask[1 << m], p[1 << m];
    for(int i = 0; i < 1 << m; ++i) {
        for(int j = 0; j <= i; ++j) {
            bool is_mask = 1;
            int cnt = 0;
            for(int k = 0; k < m; ++k) {
                if((1 << k) & j && !((1 << k) & i))
                    is_mask = 0;
                if((1 << k) & i && !((1 << k) & j))
                    ++cnt;
            }
            if(is_mask) {
                submask[i].pb(mp(j, cnt));
                //cout << bitset<3>(i) << " " << bitset<3>(j) << " " << cnt << endl;
            }
        }
    }
    memset(p, 0, sizeof(p));
    for(int i = 1; i <= n; ++i) {
        fill(bitmask, bitmask + (1 << m), INT_MAX);
        memset(vert, -1, sizeof(vert));
        bool prev_ext[m], ext[m];
        for(int j = 0; j < m; ++j)
            ext[j] = d[i][j];
        for(int j = 0; j < m; ++j)
            prev_ext[j] = d[i - 1][j];
        for(int j = 0; j < 1 << m; ++j) {
            // cek horizontal segment ada berapa
            // horizontal itu 0
            // buat bitmask horizontal
            int h = 0;
            for(int k = 0; k < m; ++k) {
                if(!ext[k])
                    continue;
                if(k == 0) {
                    if(!(1 & j))
                        ++h;
                }
                else {
                    if(!((1 << k) & j) && (!ext[k - 1] || (1 << (k - 1)) & j))
                        ++h;
                }
            }
            int v = 0;
            // cek buat vertikal
            // v -> harus buat baru
            // syarat:
            // kalo current yang vertikal exists tapi prev tidak exists
            // add ke v
            // kalo vertikal tidak exist -> buat jadi 0
            // terus kita buat integer baru
            // buat cari submask sebelumnya
            // :)
            int tmp = 0;
            for(int k = 0; k < m; ++k) {
                if(ext[k] && (1 << k) & j) {
                    if(!prev_ext[k])
                        ++v;
                    else
                        tmp += 1 << k;
                }
            }
            if(vert[tmp] == -1) {
                // find vert[tmp]
                // use all previous submasks
                int tmp2 = INT_MAX;
                for(auto i : submask[tmp])
                    tmp2 = min(tmp2, i.se + p[i.fi]);
                vert[tmp] = tmp2;
            }
            bitmask[j] = v + h + vert[tmp];
            //cout << bitset<3>(j) << " " << h << " " << v << " " << vert[tmp] << " " << bitmask[j] << endl;
        }
        fill(p, p + (1 << m), INT_MAX);
        for(int j = 0; j < (1 << m); ++j) {
            for(auto k : submask[j])
                p[k.fi] = min(p[k.fi], bitmask[j]);
        }
    }
    int res = INT_MAX;
    for(int i = 0; i < 1 << m; ++i)
        res = min(res, p[i]);
    cout << res << endl;
    return 0;
}