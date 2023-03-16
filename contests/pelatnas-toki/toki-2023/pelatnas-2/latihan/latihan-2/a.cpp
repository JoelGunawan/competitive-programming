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
/*
const int lim = 1 << 18;
struct segment_tree {
    int mn[lim], mx[lim], lazyadd[lim], lazymax[lim], lazymin[lim];
    void propagate(int nd, int cl, int cr) {
        // masalah timbul kalo
        // max + max +
        // lazy ops harus dilakukan in order tersebut (harusnya aman)
        // hati-hati lazymin bisa override lazy max jika lazymin < lazymax
        // cek lazymin dan lazymax dulu
        // nilai lama di tambah dulu, terus di min sama lazymin
        // nilai lama di tambah dulu, terus di max sama lazymax
        mx[nd] = min(lazymin[nd], max(mx[nd] + lazyadd[nd], lazymax[nd]));
        mn[nd] = max(lazymax[nd], min(mn[nd] + lazyadd[nd], lazymin[nd]));
        if(cl != cr) {
            lazyadd[2 * nd] += lazyadd[nd];
            lazyadd[2 * nd + 1] += lazyadd[nd];
            // harus ambil min antara lazymax child dan lazymin sekarang
            lazymax[2 * nd] = max(min(lazymax[2 * nd] + lazyadd[nd], lazymin[nd]), min(lazymax[nd], lazymin[nd]));
        }
        lazymax[nd] = 0;
        lazymin[nd] = 1e9;
    }
    void update_sum(int nd, int cl, int cr, int l, int r, int val) {
        if(cl >= l && cr <= r) {
            lazymax[nd] += val;
            lazymin[nd] += val;
            lazyadd[nd] += val;
        }
    }
    void update_max(int nd, int cl, int cr, int l, int r, int val) {
        if(cl >= l && cr <= r) {
            lazymax[nd] = max(lazymax[nd], val);
            lazymin[nd] = max(lazymin[nd], val);
        }
    }
    void update_min(int nd, int cl, int cr, int l, int r, int val) {
        if(cl >= l && cr <= r) {
            lazymin[nd] = min(lazymin[nd], val);
            lazymax[nd] = min(lazymax[nd], val);
            // min can overpower max
        }
    }
    int query(int nd, int cl, int cr) {

    }
};
*/
struct operations {
    int type, l, r, k;
};
struct prop {
    int mx = -1e9 - 5e8, mn = 1e9 + 5e8;
    vector<int> arr;
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // range set min (lazy)
    // range set max (lazy)
    // range update (lazy)
    // min/max -> constant time
    int n, q;
    cin >> n >> q;
    // do sqrt
    // make into blocks size sqrt(n) and do operations to set max, min, add range, and determine min and max
    int a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int akar = sqrt(n), sz = 0;
    vector<int> blk;
    for(int i = 0; i < akar; ++i)
        blk.pb(akar), sz += akar;
    for(int i = 0; i < n - sz; ++i)
        blk[i % blk.size()]++;
    for(int i = 1; i < blk.size(); ++i)
        blk[i] += blk[i - 1];
    vector<operations> ops[blk.size()];
    prop blocks[blk.size()];
    int pr = 0;
    for(int i = 0; i < blk.size(); ++i) {
        for(int j = pr + 1; j <= blk[i]; ++j) {
            blocks[i].arr.pb(a[j]);
            blocks[i].mn = min(blocks[i].mn, a[j]);
            blocks[i].mx = max(blocks[i].mx, a[j]);
        }
        pr = blk[i];
    }
    while(q--) {
        operations cur;
        cin >> cur.type;
        if(cur.type == 1) {
            cin >> cur.l >> cur.r >> cur.k;
            // do operations.push_back di semua kecuali lblock dan rblock
            int l = lb(blk.begin(), blk.end(), cur.l) - blk.begin(), r = lb(blk.begin(), blk.end(), cur.r) - blk.begin();
            if(l == r) {
                int x = l;
                deque<pair<int, int>> tmparr;
                for(int i = 0; i < blocks[x].arr.size(); ++i) {
                    tmparr.push_back(make_pair(blocks[x].arr[i], i));
                }
                sort(tmparr.begin(), tmparr.end());
                // kapan dia pertama kena max, kapan dia pertama kena min
                bool mx[blocks[x].arr.size()], mn[blocks[x].arr.size()];
                memset(mx, 0, sizeof(mx)); memset(mn, 0, sizeof(mn));
                int cur_sum = 0;
                for(auto i : ops[x]) {
                    if(i.type == 1) {
                        cur_sum += i.k;
                    }
                    else if(i.type == 2) {
                        // cek apa yang bisa dibuat min sama sekarang
                        int tmp = i.k - cur_sum;
                        while(tmparr.size() && tmparr.back().fi >= tmp) {
                            mn[tmparr.back().se] = 1;
                            tmparr.pop_back();
                        }
                    }
                    else if(i.type == 3) {
                        int tmp = i.k - cur_sum;
                        while(tmparr.size() && tmparr.front().fi <= tmp) {
                            mx[tmparr.front().se] = 1;
                            tmparr.pop_front();
                        }
                    }
                }
                for(int i = 0; i < blocks[x].arr.size(); ++i) {
                    if(mn[i])
                        blocks[x].arr[i] = blocks[x].mn;
                    else if(mx[i])
                        blocks[x].arr[i] = blocks[x].mx;
                    else
                        blocks[x].arr[i] += cur_sum;
                }
                int idxl, idxr;
                if(x == 0)
                    idxl = cur.l - 1, idxr = cur.r - 1;
                else
                    idxl = cur.l - blk[x - 1] - 1, idxr = cur.r - blk[x - 1] - 1;
                for(int i = idxl; i <= idxr; ++i)
                    blocks[x].arr[i] += cur.k;
                int newmn = 2e9, newmx = -2e9;
                for(int i = 0; i < blocks[x].arr.size(); ++i)
                    newmn = min(newmn, blocks[x].arr[i]), newmx = max(newmx, blocks[x].arr[i]);
                blocks[x].mn = newmn, blocks[x].mx = newmx;
            }
            else {
                for(int i = l + 1; i < r; ++i) {
                    ops[i].pb(cur);
                    blocks[i].mx += cur.k;
                    blocks[i].mn += cur.k;
                }
                // update l
                // buat set yang isinya items
                // update indices masuk min/max
                // kalo ga masuk min/max -> ikuti sum
                // cek paling kecil berapa biar kena lazymin
                // cek paling besar berapa biar kena lazymax
                // update r
                int x = l;
                deque<pair<int, int>> tmparr;
                for(int i = 0; i < blocks[x].arr.size(); ++i) {
                    tmparr.push_back(make_pair(blocks[x].arr[i], i));
                }
                sort(tmparr.begin(), tmparr.end());
                // kapan dia pertama kena max, kapan dia pertama kena min
                bool mx[blocks[x].arr.size()], mn[blocks[x].arr.size()];
                memset(mx, 0, sizeof(mx)); memset(mn, 0, sizeof(mn));
                int cur_sum = 0;
                for(auto i : ops[x]) {
                    if(i.type == 1) {
                        cur_sum += i.k;
                    }
                    else if(i.type == 2) {
                        // cek apa yang bisa dibuat min sama sekarang
                        int tmp = i.k - cur_sum;
                        while(tmparr.size() && tmparr.back().fi >= tmp) {
                            mx[tmparr.back().se] = 1;
                            tmparr.pop_back();
                        }
                    }
                    else if(i.type == 3) {
                        int tmp = i.k - cur_sum;
                        while(tmparr.size() && tmparr.front().fi <= tmp) {
                            mn[tmparr.front().se] = 1;
                            tmparr.pop_front();
                        }
                    }
                }
                for(int i = 0; i < blocks[x].arr.size(); ++i) {
                    if(mn[i])
                        blocks[x].arr[i] = blocks[x].mn;
                    else if(mx[i])
                        blocks[x].arr[i] = blocks[x].mx;
                    else
                        blocks[x].arr[i] += cur_sum;
                }
                int idxl, idxr;
                if(x == 0)
                    idxl = cur.l - 1, idxr = blk[x] - 1;
                else
                    idxl = cur.l - blk[x - 1] - 1, idxr = blk[x] - blk[x - 1] - 1;
                for(int i = idxl; i <= idxr; ++i)
                    blocks[x].arr[i] += cur.k;
                int newmn = 2e9, newmx = -2e9;
                for(int i = 0; i < blocks[x].arr.size(); ++i)
                    newmn = min(newmn, blocks[x].arr[i]), newmx = max(newmx, blocks[x].arr[i]);
                blocks[x].mn = newmn, blocks[x].mx = newmx;
                x = r;
                tmparr.clear();
                for(int i = 0; i < blocks[x].arr.size(); ++i) {
                    tmparr.push_back(make_pair(blocks[x].arr[i], i));
                }
                sort(tmparr.begin(), tmparr.end());
                // kapan dia pertama kena max, kapan dia pertama kena min
                memset(mx, 0, sizeof(mx)); memset(mn, 0, sizeof(mn));
                cur_sum = 0;
                for(auto i : ops[x]) {
                    if(i.type == 1) {
                        cur_sum += i.k;
                    }
                    else if(i.type == 2) {
                        // cek apa yang bisa dibuat min sama sekarang
                        int tmp = i.k - cur_sum;
                        while(tmparr.size() && tmparr.back().fi >= tmp) {
                            mn[tmparr.back().se] = 1;
                            tmparr.pop_back();
                        }
                    }
                    else if(i.type == 3) {
                        int tmp = i.k - cur_sum;
                        while(tmparr.size() && tmparr.front().fi <= tmp) {
                            mx[tmparr.front().se] = 1;
                            tmparr.pop_front();
                        }
                    }
                }
                for(int i = 0; i < blocks[x].arr.size(); ++i) {
                    if(mn[i])
                        blocks[x].arr[i] = blocks[x].mn;
                    else if(mx[i])
                        blocks[x].arr[i] = blocks[x].mx;
                    else
                        blocks[x].arr[i] += cur_sum;
                }
                idxl, idxr;
                if(x == 0)
                    idxl = 0, idxr = cur.r - 1;
                else
                    idxl = 0, idxr = cur.r - blk[x - 1] - 1;
                for(int i = idxl; i <= idxr; ++i)
                    blocks[x].arr[i] += cur.k;
                newmn = 2e9, newmx = -2e9;
                for(int i = 0; i < blocks[x].arr.size(); ++i)
                    newmn = min(newmn, blocks[x].arr[i]), newmx = max(newmx, blocks[x].arr[i]);
                blocks[x].mn = newmn, blocks[x].mx = newmx;
            }
            ops[l].clear(), ops[r].clear();
        }
        else if(cur.type == 2) {
            cin >> cur.l >> cur.r >> cur.k;
            // do operations.push_back di semua kecuali lblock dan rblock
            int l = lb(blk.begin(), blk.end(), cur.l) - blk.begin(), r = lb(blk.begin(), blk.end(), cur.r) - blk.begin();
            if(l == r) {
                int x = l;
                deque<pair<int, int>> tmparr;
                for(int i = 0; i < blocks[x].arr.size(); ++i) {
                    tmparr.push_back(make_pair(blocks[x].arr[i], i));
                }
                sort(tmparr.begin(), tmparr.end());
                // kapan dia pertama kena max, kapan dia pertama kena min
                bool mx[blocks[x].arr.size()], mn[blocks[x].arr.size()];
                memset(mx, 0, sizeof(mx)); memset(mn, 0, sizeof(mn));
                int cur_sum = 0;
                for(auto i : ops[x]) {
                    if(i.type == 1) {
                        cur_sum += i.k;
                    }
                    else if(i.type == 2) {
                        // cek apa yang bisa dibuat min sama sekarang
                        int tmp = i.k - cur_sum;
                        while(tmparr.size() && tmparr.back().fi >= tmp) {
                            mn[tmparr.back().se] = 1;
                            tmparr.pop_back();
                        }
                    }
                    else if(i.type == 3) {
                        int tmp = i.k - cur_sum;
                        while(tmparr.size() && tmparr.front().fi <= tmp) {
                            mx[tmparr.front().se] = 1;
                            tmparr.pop_front();
                        }
                    }
                }
                for(int i = 0; i < blocks[x].arr.size(); ++i) {
                    if(mn[i])
                        blocks[x].arr[i] = blocks[x].mn;
                    else if(mx[i])
                        blocks[x].arr[i] = blocks[x].mx;
                    else
                        blocks[x].arr[i] += cur_sum;
                }
                int idxl, idxr;
                if(x == 0)
                    idxl = cur.l - 1, idxr = cur.r - 1;
                else
                    idxl = cur.l - blk[x - 1] - 1, idxr = cur.r - blk[x - 1] - 1;
                for(int i = idxl; i <= idxr; ++i)
                    blocks[x].arr[i] = min(blocks[x].arr[i], cur.k);
                int newmn = 2e9, newmx = -2e9;
                for(int i = 0; i < blocks[x].arr.size(); ++i)
                    newmn = min(newmn, blocks[x].arr[i]), newmx = max(newmx, blocks[x].arr[i]);
                blocks[x].mn = newmn, blocks[x].mx = newmx;
            }
            else {
                for(int i = l + 1; i < r; ++i) {
                    ops[i].pb(cur);
                    blocks[i].mx = min(blocks[i].mx, cur.k);
                    blocks[i].mn = min(blocks[i].mx, cur.k);
                }
                // update l
                // buat set yang isinya items
                // update indices masuk min/max
                // kalo ga masuk min/max -> ikuti sum
                // cek paling kecil berapa biar kena lazymin
                // cek paling besar berapa biar kena lazymax
                // update r
                int x = l;
                deque<pair<int, int>> tmparr;
                for(int i = 0; i < blocks[x].arr.size(); ++i) {
                    tmparr.push_back(make_pair(blocks[x].arr[i], i));
                }
                sort(tmparr.begin(), tmparr.end());
                // kapan dia pertama kena max, kapan dia pertama kena min
                bool mx[blocks[x].arr.size()], mn[blocks[x].arr.size()];
                memset(mx, 0, sizeof(mx)); memset(mn, 0, sizeof(mn));
                int cur_sum = 0;
                for(auto i : ops[x]) {
                    if(i.type == 1) {
                        cur_sum += i.k;
                    }
                    else if(i.type == 2) {
                        // cek apa yang bisa dibuat min sama sekarang
                        int tmp = i.k - cur_sum;
                        while(tmparr.size() && tmparr.back().fi >= tmp) {
                            mx[tmparr.back().se] = 1;
                            tmparr.pop_back();
                        }
                    }
                    else if(i.type == 3) {
                        int tmp = i.k - cur_sum;
                        while(tmparr.size() && tmparr.front().fi <= tmp) {
                            mn[tmparr.front().se] = 1;
                            tmparr.pop_front();
                        }
                    }
                }
                for(int i = 0; i < blocks[x].arr.size(); ++i) {
                    if(mn[i])
                        blocks[x].arr[i] = blocks[x].mn;
                    else if(mx[i])
                        blocks[x].arr[i] = blocks[x].mx;
                    else
                        blocks[x].arr[i] += cur_sum;
                }
                int idxl, idxr;
                if(x == 0)
                    idxl = cur.l - 1, idxr = blk[x] - 1;
                else
                    idxl = cur.l - blk[x - 1] - 1, idxr = blk[x] - blk[x - 1] - 1;
                for(int i = idxl; i <= idxr; ++i)
                    blocks[x].arr[i] = min(blocks[x].arr[i], cur.k);
                int newmn = 2e9, newmx = -2e9;
                for(int i = 0; i < blocks[x].arr.size(); ++i)
                    newmn = min(newmn, blocks[x].arr[i]), newmx = max(newmx, blocks[x].arr[i]);
                blocks[x].mn = newmn, blocks[x].mx = newmx;
                x = r;
                tmparr.clear();
                for(int i = 0; i < blocks[x].arr.size(); ++i) {
                    tmparr.push_back(make_pair(blocks[x].arr[i], i));
                }
                sort(tmparr.begin(), tmparr.end());
                // kapan dia pertama kena max, kapan dia pertama kena min
                memset(mx, 0, sizeof(mx)); memset(mn, 0, sizeof(mn));
                cur_sum = 0;
                for(auto i : ops[x]) {
                    if(i.type == 1) {
                        cur_sum += i.k;
                    }
                    else if(i.type == 2) {
                        // cek apa yang bisa dibuat min sama sekarang
                        int tmp = i.k - cur_sum;
                        while(tmparr.size() && tmparr.back().fi >= tmp) {
                            mn[tmparr.back().se] = 1;
                            tmparr.pop_back();
                        }
                    }
                    else if(i.type == 3) {
                        int tmp = i.k - cur_sum;
                        while(tmparr.size() && tmparr.front().fi <= tmp) {
                            mx[tmparr.front().se] = 1;
                            tmparr.pop_front();
                        }
                    }
                }
                for(int i = 0; i < blocks[x].arr.size(); ++i) {
                    if(mn[i])
                        blocks[x].arr[i] = blocks[x].mn;
                    else if(mx[i])
                        blocks[x].arr[i] = blocks[x].mx;
                    else
                        blocks[x].arr[i] += cur_sum;
                }
                idxl, idxr;
                if(x == 0)
                    idxl = 0, idxr = cur.r - 1;
                else
                    idxl = 0, idxr = cur.r - blk[x - 1] - 1;
                for(int i = idxl; i <= idxr; ++i)
                    blocks[x].arr[i] = min(blocks[x].arr[i], cur.k);
                newmn = 2e9, newmx = -2e9;
                for(int i = 0; i < blocks[x].arr.size(); ++i)
                    newmn = min(newmn, blocks[x].arr[i]), newmx = max(newmx, blocks[x].arr[i]);
                blocks[x].mn = newmn, blocks[x].mx = newmx;
            }
            ops[l].clear(), ops[r].clear();
        }
        else if(cur.type == 3) {
            cin >> cur.l >> cur.r >> cur.k;
            int l = lb(blk.begin(), blk.end(), cur.l) - blk.begin(), r = lb(blk.begin(), blk.end(), cur.r) - blk.begin();
            if(l == r) {
                int x = l;
                deque<pair<int, int>> tmparr;
                for(int i = 0; i < blocks[x].arr.size(); ++i) {
                    tmparr.push_back(make_pair(blocks[x].arr[i], i));
                }
                sort(tmparr.begin(), tmparr.end());
                // kapan dia pertama kena max, kapan dia pertama kena min
                bool mx[blocks[x].arr.size()], mn[blocks[x].arr.size()];
                memset(mx, 0, sizeof(mx)); memset(mn, 0, sizeof(mn));
                int cur_sum = 0;
                for(auto i : ops[x]) {
                    if(i.type == 1) {
                        cur_sum += i.k;
                    }
                    else if(i.type == 2) {
                        // cek apa yang bisa dibuat min sama sekarang
                        int tmp = i.k - cur_sum;
                        while(tmparr.size() && tmparr.back().fi >= tmp) {
                            mn[tmparr.back().se] = 1;
                            tmparr.pop_back();
                        }
                    }
                    else if(i.type == 3) {
                        int tmp = i.k - cur_sum;
                        while(tmparr.size() && tmparr.front().fi <= tmp) {
                            mx[tmparr.front().se] = 1;
                            tmparr.pop_front();
                        }
                    }
                }
                for(int i = 0; i < blocks[x].arr.size(); ++i) {
                    if(mn[i])
                        blocks[x].arr[i] = blocks[x].mn;
                    else if(mx[i])
                        blocks[x].arr[i] = blocks[x].mx;
                    else
                        blocks[x].arr[i] += cur_sum;
                }
                int idxl, idxr;
                if(x == 0)
                    idxl = cur.l - 1, idxr = cur.r - 1;
                else
                    idxl = cur.l - blk[x - 1] - 1, idxr = cur.r - blk[x - 1] - 1;
                for(int i = idxl; i <= idxr; ++i)
                    blocks[x].arr[i] = max(blocks[x].arr[i], cur.k);
                int newmn = 2e9, newmx = -2e9;
                for(int i = 0; i < blocks[x].arr.size(); ++i)
                    newmn = min(newmn, blocks[x].arr[i]), newmx = max(newmx, blocks[x].arr[i]);
                blocks[x].mn = newmn, blocks[x].mx = newmx;
            }
            else {
                for(int i = l + 1; i < r; ++i) {
                    ops[i].pb(cur);
                    blocks[i].mx = max(blocks[i].mx, cur.k);
                    blocks[i].mn = max(blocks[i].mx, cur.k);
                }
                // update l
                // buat set yang isinya items
                // update indices masuk min/max
                // kalo ga masuk min/max -> ikuti sum
                // cek paling kecil berapa biar kena lazymin
                // cek paling besar berapa biar kena lazymax
                // update r
                int x = l;
                deque<pair<int, int>> tmparr;
                for(int i = 0; i < blocks[x].arr.size(); ++i) {
                    tmparr.push_back(make_pair(blocks[x].arr[i], i));
                }
                sort(tmparr.begin(), tmparr.end());
                // kapan dia pertama kena max, kapan dia pertama kena min
                bool mx[blocks[x].arr.size()], mn[blocks[x].arr.size()];
                memset(mx, 0, sizeof(mx)); memset(mn, 0, sizeof(mn));
                int cur_sum = 0;
                for(auto i : ops[x]) {
                    if(i.type == 1) {
                        cur_sum += i.k;
                    }
                    else if(i.type == 2) {
                        // cek apa yang bisa dibuat min sama sekarang
                        int tmp = i.k - cur_sum;
                        while(tmparr.size() && tmparr.back().fi >= tmp) {
                            mx[tmparr.back().se] = 1;
                            tmparr.pop_back();
                        }
                    }
                    else if(i.type == 3) {
                        int tmp = i.k - cur_sum;
                        while(tmparr.size() && tmparr.front().fi <= tmp) {
                            mn[tmparr.front().se] = 1;
                            tmparr.pop_front();
                        }
                    }
                }
                for(int i = 0; i < blocks[x].arr.size(); ++i) {
                    if(mn[i])
                        blocks[x].arr[i] = blocks[x].mn;
                    else if(mx[i])
                        blocks[x].arr[i] = blocks[x].mx;
                    else
                        blocks[x].arr[i] += cur_sum;
                }
                int idxl, idxr;
                if(x == 0)
                    idxl = cur.l - 1, idxr = blk[x] - 1;
                else
                    idxl = cur.l - blk[x - 1] - 1, idxr = blk[x] - blk[x - 1] - 1;
                for(int i = idxl; i <= idxr; ++i)
                    blocks[x].arr[i] = max(blocks[x].arr[i], cur.k);
                int newmn = 2e9, newmx = -2e9;
                for(int i = 0; i < blocks[x].arr.size(); ++i)
                    newmn = min(newmn, blocks[x].arr[i]), newmx = max(newmx, blocks[x].arr[i]);
                blocks[x].mn = newmn, blocks[x].mx = newmx;
                x = r;
                tmparr.clear();
                for(int i = 0; i < blocks[x].arr.size(); ++i) {
                    tmparr.push_back(make_pair(blocks[x].arr[i], i));
                }
                sort(tmparr.begin(), tmparr.end());
                // kapan dia pertama kena max, kapan dia pertama kena min
                memset(mx, 0, sizeof(mx)); memset(mn, 0, sizeof(mn));
                cur_sum = 0;
                for(auto i : ops[x]) {
                    if(i.type == 1) {
                        cur_sum += i.k;
                    }
                    else if(i.type == 2) {
                        // cek apa yang bisa dibuat min sama sekarang
                        int tmp = i.k - cur_sum;
                        while(tmparr.size() && tmparr.back().fi >= tmp) {
                            mn[tmparr.back().se] = 1;
                            tmparr.pop_back();
                        }
                    }
                    else if(i.type == 3) {
                        int tmp = i.k - cur_sum;
                        while(tmparr.size() && tmparr.front().fi <= tmp) {
                            mx[tmparr.front().se] = 1;
                            tmparr.pop_front();
                        }
                    }
                }
                for(int i = 0; i < blocks[x].arr.size(); ++i) {
                    if(mn[i])
                        blocks[x].arr[i] = blocks[x].mn;
                    else if(mx[i])
                        blocks[x].arr[i] = blocks[x].mx;
                    else
                        blocks[x].arr[i] += cur_sum;
                }
                idxl, idxr;
                if(x == 0)
                    idxl = 0, idxr = cur.r - 1;
                else
                    idxl = 0, idxr = cur.r - blk[x - 1] - 1;
                for(int i = idxl; i <= idxr; ++i)
                    blocks[x].arr[i] = max(blocks[x].arr[i], cur.k);
                newmn = 2e9, newmx = -2e9;
                for(int i = 0; i < blocks[x].arr.size(); ++i)
                    newmn = max(newmn, blocks[x].arr[i]), newmx = max(newmx, blocks[x].arr[i]);
                blocks[x].mn = newmn, blocks[x].mx = newmx;
            }
            ops[l].clear(), ops[r].clear();
        }
        else {
            cin >> cur.l >> cur.r;
            int l = lb(blk.begin(), blk.end(), cur.l) - blk.begin(), r = lb(blk.begin(), blk.end(), cur.r) - blk.begin();
            int x = l;
            int mnres = 2e9, mxres = -2e9;
            deque<pair<int, int>> tmparr;
            for(int i = 0; i < blocks[x].arr.size(); ++i) {
                tmparr.push_back(make_pair(blocks[x].arr[i], i));
            }
            sort(tmparr.begin(), tmparr.end());
            // kapan dia pertama kena max, kapan dia pertama kena min
            bool mx[blocks[x].arr.size()], mn[blocks[x].arr.size()];
            memset(mx, 0, sizeof(mx)); memset(mn, 0, sizeof(mn));
            int cur_sum = 0;
            for(auto i : ops[x]) {
                if(i.type == 1) {
                    cur_sum += i.k;
                }
                else if(i.type == 2) {
                    // cek apa yang bisa dibuat min sama sekarang
                    int tmp = i.k - cur_sum;
                    while(tmparr.size() && tmparr.back().fi >= tmp) {
                        mx[tmparr.back().se] = 1;
                        tmparr.pop_back();
                    }
                }
                else if(i.type == 3) {
                    int tmp = i.k - cur_sum;
                    while(tmparr.size() && tmparr.front().fi <= tmp) {
                        mn[tmparr.front().se] = 1;
                        tmparr.pop_front();
                    }
                }
            }
            ops[x].clear();
            for(int i = 0; i < blocks[x].arr.size(); ++i) {
                if(mn[i])
                    blocks[x].arr[i] = blocks[x].mn;
                else if(mx[i])
                    blocks[x].arr[i] = blocks[x].mx;
                else
                    blocks[x].arr[i] += cur_sum;
            }
            int idxl, idxr;
            if(x == 0)
                idxl = cur.l - 1, idxr = min(cur.r, blk[x]) - 1;
            else
                idxl = cur.l - blk[x - 1] - 1, idxr = min(cur.r, blk[x]) - blk[x - 1] - 1;
            for(int i = idxl; i <= idxr; ++i)
                mxres = max(blocks[x].arr[i], mxres), mnres = min(blocks[x].arr[i], mnres);
            if(l == r) {
                cout << mnres << " " << mxres << endl;
                continue;
            }
            x = r;
            tmparr.clear();
            for(int i = 0; i < blocks[x].arr.size(); ++i) {
                tmparr.push_back(make_pair(blocks[x].arr[i], i));
            }
            sort(tmparr.begin(), tmparr.end());
            // kapan dia pertama kena max, kapan dia pertama kena min
            memset(mx, 0, sizeof(mx)); memset(mn, 0, sizeof(mn));
            cur_sum = 0;
            for(auto i : ops[x]) {
                if(i.type == 1) {
                    cur_sum += i.k;
                }
                else if(i.type == 2) {
                    // cek apa yang bisa dibuat min sama sekarang
                    int tmp = i.k - cur_sum;
                    while(tmparr.size() && tmparr.back().fi >= tmp) {
                        mn[tmparr.back().se] = 1;
                        tmparr.pop_back();
                    }
                }
                else if(i.type == 3) {
                    int tmp = i.k - cur_sum;
                    while(tmparr.size() && tmparr.front().fi <= tmp) {
                        mx[tmparr.front().se] = 1;
                        tmparr.pop_front();
                    }
                }
            }
            for(int i = 0; i < blocks[x].arr.size(); ++i) {
                if(mn[i])
                    blocks[x].arr[i] = blocks[x].mn;
                else if(mx[i])
                    blocks[x].arr[i] = blocks[x].mx;
                else
                    blocks[x].arr[i] += cur_sum;
            }
            ops[x].clear();
            for(int i = l + 1; i < r; ++i)
                mnres = min(mnres, blocks[i].mn), mxres = max(mxres, blocks[i].mx);
            idxl, idxr;
            if(x == 0)
                idxl = 0, idxr = cur.r - 1;
            else
                idxl = 0, idxr = cur.r - blk[x - 1] - 1;
            for(int i = idxl; i <= idxr; ++i)
                mxres = max(blocks[x].arr[i], mxres), mnres = min(blocks[x].arr[i], mnres);
            cout << mnres << " " << mxres << endl;
        }
    }
    return 0;
}