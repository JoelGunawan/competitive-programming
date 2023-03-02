// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
// #define endl "\n"
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
int query(vector<int> num) {
    cout << "? ";
    for(auto i : num)
        cout << i << " ";
    cout << endl;
    int t;
    cin >> t;
    return t;
}
void tc() {
    int n;
    cin >> n;
    vector<int> cur, unused;
    set<int> not_zero;
    for(int i = 1; i <= n; ++i)
        unused.pb(i);
    /*
    unused -> kita ga punya info tntng node ini
    cur -> yang sedang kita cari
    not_zero -> node yang kita pasti tahu bukan 0
    untuk menyelesaikan ini, kita coba kerjakan untuk kasus n = 4 terlebih dahulu
    misal a, b, c, d
    cari mana yang bisa merupakan 0 dari beberapa query
    mis a <= b <= c <= d
    maka:
    q(a, b, c) = c - a
    q(a, b, d) = d - a
    q(a, c, d) = d - a
    q(b, c, d) = d - b
    diketahui pasti d - a >= d -b dan d - a >= c - a
    d - a = d - b jika a = b, sehingga semuanya tidak mungkin merupakan 0
    d - a = c - a jika hanya c = d
    dari sini kita bisa simpulkan jika kita tidak menggunakan x di query, dan hasil query tersebut maksimal
    maka pasti x bukan 0
    kita bisa lakukan proses ini berulang kali hingga bisa menemukan 2 angka yang bukan 0
    */
    while(unused.size() > 0) {
        while(cur.size() < 4 && unused.size() > 0)
            cur.pb(unused.back()), unused.pop_back();
        auto it = not_zero.begin();
        while(cur.size() < 4)
            cur.pb(*it), ++it;
        // we have cur of size 4
        vector<pair<int, int>> queries;
        for(int i = 0; i < 4; ++i) {
            vector<int> tmp2;
            for(int j = 0; j < 4; ++j)
                if(i != j)
                    tmp2.pb(cur[j]);
            queries.pb(mp(query(tmp2), cur[i]));
        }
        sort(queries.begin(), queries.end());
        reverse(queries.begin(), queries.end());
        not_zero.ins(queries[0].se), not_zero.ins(queries[1].se);
        cur.erase(find(cur.begin(), cur.end(), queries[0].se)), cur.erase(find(cur.begin(), cur.end(), queries[1].se));
    }
    cout << "! ";
    int cnt = 0;
    for(int i = 1; i <= n; ++i)
        if(not_zero.find(i) == not_zero.end())
            cout << i << " ", ++cnt;
    while(cnt < 2)
        cout << *not_zero.begin() << " ", ++cnt, not_zero.erase(not_zero.begin());
    cout << endl;
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}