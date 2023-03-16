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
const int lim = 5e5 + 5;
vector<int> child[lim];
bool win[lim];
int child_lose[lim], res;
vector<int> ans;
void get_subtree(int nd) {
    win[nd] = 0;
    for(auto i : child[nd]) {
        get_subtree(i);
        win[nd] |= !win[i];
        if(!win[i])
            ++child_lose[nd];
    }
}
void dfs(int nd, bool par) {
    // cek atas (par)
    // cek bawah
    //bool include = 0;
    if(!win[nd] && par) {
        ans.pb(nd);
        //include = 1;
        //cout << nd << " ";
    }
    // kalo par = 0 -> prop ke bawahnya pasti 1
    // kalo par = 1, harus cek lainnya
    int tmp = !par;
    for(auto i : child[nd]) {
        if(!win[i])
            ++tmp;
    }
    //cout << nd << " " << win[nd] << " " << par << " " << tmp << endl;
    for(auto i : child[nd]) {
        // kalo pilih karena HARUS ke child i, maka parent set ke 1
        // kalo dia ke parent, statenya lose/win?
        if(!par || (win[nd] && (win[i] || tmp != 1))) {
            dfs(i, 1);
        }
        else
            dfs(i, 0);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        child[x].pb(i);
    }
    get_subtree(1);
    dfs(1, 1);
    sort(ans.begin(), ans.end());
    for(auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}