// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("O3")
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
int n;
const int maxN = 300005;
const int inf = 1e9;
int a[maxN];
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
gp_hash_table<int, int, chash> dp[maxN];
set<pair<int, int>> p[maxN], s[maxN];
int lg[maxN];
// dp[mx_cost][index]
// mx_cost -> logN*9
// index -> N
// dp[k][idx] = furthest r starting from idx with k cost
// dp[k][idx] = max(dp[k - 1][idx], );
// transisi: pake lazy segtree
// set idx as mid
// find max on the left with cost less than cur_cost - k
// O(9NlogN???)
int cost(int l, int r) {
    if(r < l)
        return 0;
    else if(l == r)
        return a[l];
    else if(r - l == 1)
        return a[l] + a[r];
    else if(r - l == 2)
        return a[l + 1] + max(a[l], a[r]);
    else if(dp[l][r] != 0)
        return dp[l][r];
    else if(r - l + 1 <= 40) {
        int tmp = inf;
        // bisa pakai prefix/suffix buat transisi?
        // buat calculate cost, bisa pakai cara yg lebih efisien prob, bs order calculate tertentu
        for(int i = l; i <= r; ++i) {
            tmp = min(tmp, max(cost(l, i - 1), cost(i + 1, r)) + a[i]);
        }
        return dp[l][r] = tmp;
    }
    int cl = l, cr = r, idx;
    // coba pakai konsep dp dnc
    // given a certain l, find the previous r and next r, pasti binsernya antara 2 titik itu aja
    // bisa pakai cara yang sama dr biar binsernya lebih ter kerucut
    auto it1 = p[l].lb(mp(r, 0));
    if(it1 != p[l].end()) {
        pair<int, int> tmp = *it1;
        cr = min(cr, tmp.se);
        //cl = max(cl, tmp.se - lg[tmp.fi - r] * (tmp.fi - r));
    }
    if(it1 != p[l].begin()) {
        pair<int, int> tmp = *--it1;
        cl = max(cl, tmp.se);
        //cr = min(cr, tmp.se + lg[r - tmp.fi] * (r - tmp.fi));
    }
    auto it2 = s[r].lb(mp(l, 0));
    if(it2 != s[r].end()) {
        pair<int, int> tmp = *it2;
        cr = min(cr, tmp.se);
        //cl = max(cl, tmp.se - lg[tmp.fi - l] * (tmp.fi - l));
    }
    if(it2 != s[r].begin()) {
        pair<int, int> tmp = *--it2;
        cl = max(cl, tmp.se);
        //cr = min(cr, tmp.se + lg[tmp.fi - l] * (l - tmp.fi));
    }
    while(cl <= cr) {
        int mid = (cl + cr) >> 1;
        int le = cost(l, mid - 1), re = cost(mid + 1, r);
        // cost left terlalu besar, pergi ke kiri
        if(le > re) {
            cr = mid - 1;
        }
        // cost right terlalu besar, pergi ke kanan
        else {
            cl = mid + 1;
        }
    }
    idx = cl;
    idx = min(idx, r);
    // di sini bisa di optimize
    // perlu cek at most 18
    // first 9 di kanan, first 9 di kiri
    // first 8 di kanan, first 8 di kiri
    // ...
    // pakai count of 1...9
    // terus nnti binser paek count aja buat cri yg paling tengah di mana
    int cur_mn = inf;
    // ini yg buat lemot, yg atas ga terlalu lemot
    int act = idx;
    int tmp = max(cost(l, idx - 1), cost(idx + 1, r)) + a[idx];
    for(int i = idx - 1; i >= max(idx - 20, l); --i) {
        if(a[i] < cur_mn) {
            int old = tmp;
            tmp = min(tmp, max(cost(l, i - 1), cost(i + 1, r)) + a[i]);
            if(tmp != old)
                act = i;
        }
        cur_mn = min(cur_mn, a[i]);
    }
    cur_mn = inf;
    for(int i = idx + 1; i <= min(idx + 20, r); ++i) {
        if(a[i] < cur_mn) {
            int old = tmp;
            tmp = min(tmp, max(cost(l, i - 1), cost(i + 1, r)) + a[i]);
            if(tmp != old)
                act = i;
        }
        cur_mn = min(cur_mn, a[i]);
    }
    p[l].ins(mp(r, act));
    s[r].ins(mp(l, act));
    return dp[l][r] = tmp;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); ++i) 
        a[i] = s[i] - '0';
    lg[0] = 9;
    for(int i = 1; i <= s.size(); ++i)
        lg[i] = lg[i >> 1] + 20;
    n = s.size();
    // let's say solve for position x as init
    // max(cost(1, x - 1), cost(x + 1, n)) + a_x
    // minimize maximum
    // cost(i, i) = a_i
    // cost(i, i + 1) = a_i + a_{i+1}
    // small a_i -> something to consider?
    // dp[l][r] maybe bisa di dnc? spy O(N^2)
    // dp[l][r] O(N^3) -> transisi manual utk cost
    // observasi dr N^3 ke N^2: semakin besar r, posisi opt semakin ke kanan, sehingga bisa pakai teknik dp dnc? 
    // (atau mungkin hanya cek 10 bisa)
    // define pref[i] as cost for i first elements, define suff[i] as cost for last i elements
    // claim: bcs of low a_i, the binary search will roughly do O(logn)
    cout << cost(0, n - 1) << endl;   
    // construct a rooted tree such that the maximum path from root to leaf is minimum, each vertex has value a_i
    // maintain states using sparse segment trees?
    // general tendencies: optimal to choose lower number first and larger numbers later
    // coba bsta, terus constructnya pruning/random?
    // obs: ga mungkin most left and most right in any circumstance (kcuali no choice)
    // r - l + 1 == 2 -> a_l + a_r
    // tiap binser, cek kiri 5 dan kanan 5, jika ada both left larger dan right larger, berarti answer is in the vicinity
    // in this case cek 10 ke kiri dan 10 ke kanan
    // for small ranges, just use manual (<= 50)
    return 0;
}