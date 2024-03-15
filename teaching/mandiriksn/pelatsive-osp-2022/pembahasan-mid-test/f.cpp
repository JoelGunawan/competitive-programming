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
void tc() {
    int n;
    cin >> n;
    int b[n];
    for(int i = 0; i < n; ++i) 
        cin >> b[i];
    ll sum = 0;
    for(int i = 0; i < n; ++i)
        sum += b[i];
    if(sum % (1ll * n * (n + 1) / 2)) {
        cout << "NO" << endl;
        return;
    }
    ll suma = sum / (1ll * n * (n + 1) / 2);
    ll a[n];
    for(int i = 0; i < n; ++i) {
        a[i] = (suma + b[(i - 1 + n) % n] - b[i]);
        if(a[i] % n || a[i] <= 0) {
            cout << "NO" << endl;
            return ;
        }
        a[i] /= n;
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}