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
    int f[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> f[i];
    int in[n + 1], out[n + 1];
    memset(in, -1, sizeof(in)), memset(out, -1, sizeof(out));
    for(int i = 1; i <= n; ++i) {
        if(f[i] != 0)
            out[i] = f[i], in[f[i]] = i;
    }
    vector<int> isolated;
    for(int i = 1; i <= n; ++i) {
        if(out[i] == -1 && in[i] == -1)
            isolated.pb(i);
    }
    if(isolated.size() > 1) {
        for(int i = 0; i < isolated.size(); ++i) {
            in[isolated[i]] = isolated[(i + 1) % isolated.size()];
            out[isolated[(i + 1) % isolated.size()]] = isolated[i];
        }
    }
    else if(isolated.size()) {
        for(int i = 1; i <= n; ++i) {
            if(in[i] == -1 && i != isolated.front()) {
                in[i] = isolated.front();
                out[isolated.front()] = i;
                break;
            }
        }
    }
    vector<int> noin, noout;
    for(int i = 1; i <= n; ++i) {
        if(in[i] == -1)
            noin.pb(i);
        else if(out[i] == -1)
            noout.pb(i);
    }
    assert(noin.size() == noout.size());
    for(int i = 0; i < noin.size(); ++i) {
        out[noout[i]] = noin[i];
        in[noin[i]] = noout[i];
    }
    for(int i = 1; i <= n; ++i)
        cout << out[i] << " ";
    cout << endl;
    return 0;
}