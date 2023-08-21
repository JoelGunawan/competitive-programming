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
string operate(string a, string b) {
    for(int it = 0; it < a.size(); ++it) {
        if(a[it] == b[it])
            continue;
        bool j = 0, o = 0, i = 0;
        if(a[it] == 'J')
            j = 1;
        else if(a[it] == 'O')
            o = 1;
        else
            i = 1;
        if(b[it] == 'J')
            j = 1;
        else if(b[it] == 'O')
            o = 1;
        else
            i = 1;
        if(!j)
            a[it] = 'J';
        else if(!o)
            a[it] = 'O';
        else
            a[it] = 'I';
    }
    return a;
}
int to_num(string s) {
    if(s == "J")
        return 0;
    else if(s == "O")
        return 1;
    else
        return 2;
}
int to_num(char x) {
    if(x == 'J')
        return 0;
    else if(x == 'O')
        return 1;
    else
        return 2;
}
const int lim = 2e5 + 5;
// buat bit 27 state 1 nya implicit disimpan di segment bawahnya
// remove segment bawahnya per segment gtu
// nanti cnt cari mutually exclusive segment
// char akhirnya berapa
// char 1, 2, 3, dan akhir
// 4 pertama -> quadruplet 1
// 4 kedua -> quadruplet 2
bool compatible[3][3][3][3][3][3][3][3];
bool possible[3][3][3][3];
int pref[lim][3][3][3];
int cnt[3][3][3][3];
vector<vector<int>> masks[3][3][3][3];
// precompute itu incompatible pairsnya gmn aja
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    // coba cek tiap possibility pengambilan
    // max pengambilan cmn 3?
    int e[n + 1][3];
    for(int i = 0; i < 3; ++i) {
        for(int j = 1; j <= n; ++j) {
            char x;
            cin >> x;
            e[j][i] = to_num(x);
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 3; ++j) {
            for(int k = 0; k < 3; ++k) {
                for(int l = 0; l < 3; ++l) {
                    pref[i][j][k][l] += pref[i - 1][j][k][l];
                }
            }
        }
        pref[i][e[i][0]][e[i][1]][e[i][2]]++;
    }
    int q;
    cin >> q;
    set<pair<pair<int, int>, int>> segments;
    for(int i = 1; i <= n; ++i) {
        char x;
        cin >> x;
        for(int j = 0; j < 3; ++j) {
            for(int k = 0; k < 3; ++k) {
                for(int l = 0; l < 3; ++l) {
                    cnt[j][k][l][to_num(x)] += pref[i][j][k][l] - pref[i - 1][j][k][l];
                }
            }
        }
        segments.insert(make_pair(make_pair(i, i), to_num(x)));
    }
    string choice[3] = {"J", "O", "I"};
    vector<vector<int>> triplets;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            for(int k = 0; k < 3; ++k) {
                triplets.push_back({i, j, k});
            }
        }
    }
    // utk tiap triple consider tiap pengambilan dengan triple itu sendiri, apa bisa buat char tertentu?
    for(auto p : triplets) {
        for(int i = 0; i < 3; ++i) {
            string tmp = choice[p[i]];
            for(int j = 0; j < 3; ++j) {
                tmp = operate(tmp, choice[p[j]]);
                for(int k = 0; k < 3; ++k) {
                    tmp = operate(tmp, choice[p[k]]);
                    possible[p[0]][p[1]][p[2]][to_num(tmp)] = 1;
                    masks[p[0]][p[1]][p[2]][to_num(tmp)].push_back({i, j, k});
                }
            }
        }
    }
    for(int trip = 0; trip < triplets.size(); ++trip) {
        for(int trip2 = 0; trip2 < triplets.size(); ++trip2) {
            vector<int> p1 = triplets[trip], p2 = triplets[trip2];
            for(int i = 0; i < 3; ++i) {
                string tmp1 = choice[p1[i]];
                string tmp2 = choice[p2[i]];
                for(int j = 0; j < 3; ++j) {
                    tmp1 = operate(tmp1, choice[p1[j]]);
                    tmp2 = operate(tmp2, choice[p2[j]]);
                    for(int k = 0; k < 3; ++k) {
                        tmp1 = operate(tmp1, choice[p1[k]]);
                        tmp2 = operate(tmp2, choice[p2[k]]);
                        compatible[p1[0]][p1[1]][p1[2]][to_num(tmp1)][p2[0]][p2[1]][p2[2]][to_num(tmp2)] = 1;
                    }
                }
            }
        }
    }
    // coba permutasi size 1, 2, 3
    // given same sequence tp resultnya beda -> pasti gabisa -> O(81Q) -> 1.6e7
    // klo misal ga ada yg beda, berarti max ada 27 aja
    // klo 27, nanti cek O(27^2*Q) -> 1.4e8
    // total O(81Q)
    bool ans = 1;
    vector<vector<int>> a;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            for(int k = 0; k < 3; ++k) {
                for(int l = 0; l < 3; ++l) {
                    if(cnt[i][j][k][l] && !possible[i][j][k][l])
                        ans = 0;
                    if(cnt[i][j][k][l])
                        a.push_back({i, j, k, l});
                }
            }
        }
    }
    int res[3][3][3];
    memset(res, 0, sizeof(res));
    for(int i = 0; i < a.size(); ++i) {
        for(auto j : masks[a[i][0]][a[i][1]][a[i][2]][a[i][3]]) {
            res[j[0]][j[1]][j[2]] += cnt[a[i][0]][a[i][1]][a[i][2]][a[i][3]];
        }
    }
    int mx = 0;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            for(int k = 0; k < 3; ++k)
                mx = max(mx, res[i][j][k]);
        }
    }
    //cout << mx << endl;
    if(ans && mx == n)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    while(q--) {
        // jalankan kode update
        int l, r; char x;
        cin >> l >> r >> x;
        while(segments.lower_bound(mp(make_pair(l, 0), 0)) != segments.end() && (*segments.lower_bound(mp(make_pair(l, 0), 0))).fi.se <= r) {
            pair<pair<int, int>, int> tmp = *segments.lower_bound(mp(mp(l, 0), 0));
            int cl = tmp.fi.se, cr = tmp.fi.fi, type = tmp.se;
            segments.erase(tmp);
            if(cl < l) {
                segments.ins(mp(mp(l - 1, cl), type));
            }
            if(cr > r) {
                segments.ins(mp(mp(cr, r + 1), type));
            }
            cl = max(l, cl);
            cr = min(r, cr);
            for(int i = 0; i < 3; ++i) {
                for(int j = 0; j < 3; ++j) {
                    for(int k = 0; k < 3; ++k) {
                        cnt[i][j][k][type] -= pref[cr][i][j][k] - pref[cl - 1][i][j][k];
                        cnt[i][j][k][to_num(x)] += pref[cr][i][j][k] - pref[cl - 1][i][j][k];
                        // cek mask yg bs buat i, j, k jadi type?
                    }
                }
            }
        }
        segments.ins(mp(mp(r, l), to_num(x)));
        // kode cek answer
        bool ans = 1;
        vector<vector<int>> a;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                for(int k = 0; k < 3; ++k) {
                    for(int l = 0; l < 3; ++l) {
                        if(cnt[i][j][k][l] && !possible[i][j][k][l])
                            ans = 0;
                        if(cnt[i][j][k][l])
                            a.push_back({i, j, k, l});
                    }
                }
            }
        }
        if(!ans) {
            cout << "No" << endl;
            continue;
        }
        // cari subset yg compatiblenya terbanyak?
        int res[3][3][3];
        memset(res, 0, sizeof(res));
        for(int i = 0; i < a.size(); ++i) {
            for(auto j : masks[a[i][0]][a[i][1]][a[i][2]][a[i][3]]) {
                res[j[0]][j[1]][j[2]] += cnt[a[i][0]][a[i][1]][a[i][2]][a[i][3]];
            }
        }
        int mx = 0;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                for(int k = 0; k < 3; ++k)
                    mx = max(mx, res[i][j][k]);
            }
        }
        if(ans && mx == n)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}