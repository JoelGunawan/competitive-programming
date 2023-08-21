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
void tc() {
    int n;
    ll x, y;
    cin >> n >> x >> y;
    ll a[n + 1];
    for(int i = 1; i <= n; ++i) {
        // aw math
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    // di first run, kalo ketemu jawaban, langsung output
    // nanti klo a[i] = a[i - 1] + 1, maka dia akan merge jadi 1
    // nanti dia akan peak 
    // cari first peak berapa
    // merge next -> peak itu lebih dr minimum
    // only consider peak, kalo peak sudah sampe x, berarti done :D
    // kalo cycle count negative, harus in fisrt run, kalo ga no answer
    // consider dr nilai max(a[i] - i, pref[i - 1]) as to when nilai init apa yg buat i jadi peak
    ll pr[n + 1];
    pr[0] = 0;
    for(int i = 1; i <= n; ++i) {
        pr[i] = max(pr[i - 1], a[i] - (i - 1));
    }
    // cek negative cycle dlu
    ll cur_rat = x;
    for(int i = 1; i <= n; ++i) {
        if(cur_rat >= a[i])
            ++cur_rat;
        else
            --cur_rat;
        if(cur_rat >= y) {
            cout << i << endl;
            return;
        }
    }
    if(cur_rat < x) {
        cout << -1 << endl;
        return;
    }
    // else berarti kita coba cri cek merge nya terjadi kapan aja
    // coba cek terjadi di index ke berapa
    ll last_act;
    for(int i = n; i >= 1; --i) {
        // coba cek last activate sebelum y
        // pr[i] + i -> last activate tanpa kena peak accidentally
        if(pr[i] + i < y) {
            last_act = i;
            break;
        }
    }
    // yapa coba cara cri nya aaaaaaa
    // harus nge math buat peaknya mager ah
    ll op_cnt = 0;
    for(int i = 1; i <= n; ++i) {
           
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}