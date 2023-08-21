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
    cin >> n;
    ll a[n];
    a[0] = 0;
    for(int i = 1; i < n; ++i)
        cin >> a[i];
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    multiset<int> buang;
    for(int i = 1; i < n; ++i) {
        if(a[i] - a[i - 1] > n || vis[a[i] - a[i - 1]])
            buang.ins(a[i] - a[i - 1]);
        else        
            vis[a[i] - a[i - 1]] = 1;
    }
    vector<int> unvis;
    for(int i = 1; i <= n; ++i) {
        if(!vis[i])
            unvis.pb(i);
    }
    //cout << buang.size() << " " << unvis.size() << endl; 
    if(buang.size() == 0 && unvis.size() == 1) {
        cout << "YES" << endl;
        return;
    }
    if(buang.size() != 1 || unvis.size() != 2) {
        cout << "NO" << endl;
        return;
    }
    //cout << "DEB " << *buang.begin() << " " << unvis[0]
    if(*buang.begin() == unvis[0] + unvis[1])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // ada semua elemen kecuali 2 posisi
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}