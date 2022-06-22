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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> rem;
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        rem.pb(mp(x, y));
    }
    // x positif
    function<int(int)> func = [&] (int bau) -> int {
        vector<pair<pair<int, int>, pair<int, int>>> cur;
        bool used[rem.size()];
        memset(used, 0, sizeof(used));
        used[0] = 1;
        cur.pb(mp(rem[0], mp(bau, 0)));
        for(int i = 0; i < cur.size(); ++i) {
            int curx = cur[i].fi.fi, cury = cur[i].fi.se, curd = cur[i].se.fi, time = cur[i].se.se;
            //cout << i << endl;
            //cout << curx << " " << cury << " " << curd << " " << time << endl;
            for(int j = 0; j < rem.size(); ++j) {
                if(!used[j]) {
                    //cout << i << " " << j << endl;
                    // find intersect
                    int tx = rem[j].fi, ty = rem[j].se;
                    int dx = abs(curx - tx), dy = abs(cury - ty);
                    //cout << tx << " " << ty << " " << dx << " " << dy << endl;
                    if(curd == 0 && curx <= tx) {
                        if(cury == ty && dx / 2 >= time) {
                            cur.pb(mp(rem[j], mp(2, dx / 2 + dx % 2)));                   
                            used[j] = 1;
                        }
                        else {
                            if(dx == dy && dy >= time) {
                                if(ty < cury) {
                                    cur.pb(mp(rem[j], mp(1, dy)));
                                }
                                else {
                                    cur.pb(mp(rem[j], mp(3, dy)));
                                }
                                used[j] = 1;
                            }
                        }
                    }
                    else if(curd == 1 && cury <= ty) {
                        if(curx == tx && dy / 2 >= time) {
                            cur.pb(mp(rem[j], mp(3, dy / 2 + dy % 2)));                   
                            used[j] = 1;
                        }
                        else {
                            if(dx == dy && dy >= time) {
                                if(tx < curx) {
                                    cur.pb(mp(rem[j], mp(0, dy)));
                                }
                                else {
                                    cur.pb(mp(rem[j], mp(2, dy)));
                                }
                                used[j] = 1;
                            }
                        }
                    }
                    else if(curd == 2 && curx >= tx) {
                        if(cury == ty && dx / 2 >= time) {
                            cur.pb(mp(rem[j], mp(0, dx / 2 + dx % 2)));                   
                            used[j] = 1;
                        }
                        else {
                            if(dx == dy && dy >= time) {
                                if(ty < cury) {
                                    cur.pb(mp(rem[j], mp(1, dy)));
                                }
                                else {
                                    cur.pb(mp(rem[j], mp(3, dy)));
                                }
                                used[j] = 1;
                            }
                        }
                    }
                    else if(curd == 3 && cury >= ty) {
                        if(curx == tx && dy / 2 >= time) {
                            cur.pb(mp(rem[j], mp(1, dy / 2 + dy % 2)));                   
                            used[j] = 1;
                        }
                        else {
                            if(dx == dy && dy >= time) {
                                if(tx < curx) {
                                    cur.pb(mp(rem[j], mp(0, dy)));
                                }
                                else {
                                    cur.pb(mp(rem[j], mp(2, dy)));
                                }
                                used[j] = 1;
                            }
                        }
                    }
                }
            }
        }
        return cur.size();
    };
    int res = max({func(0), func(1), func(2), func(3)});
    cout << res << endl;
    return 0;
}