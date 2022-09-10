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
const int lim = 4e6 + 5;
struct disjoint_set {
    int head[lim], size[lim];
    disjoint_set() {
        memset(head, -1, sizeof(head));
        fill(size, size + lim, 1);
    }
    int find_head(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int x, int y) {
        x = find_head(x), y = find_head(y);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            head[y] = x, size[x] += size[y];
        }
        return x != y;
    }
};
int mod = 998244353;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string res = "";
    disjoint_set dsu;
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0) {
            dsu.merge(b, c);
        }
        else {
            if(dsu.find_head(b) != dsu.find_head(c))
                res += '0';
            else    
                res += '1';
        }
    }
    ll tmp = 1, out = 0;
    for(int i = res.size() - 1; i >= 0; --i) {
        if(res[i] == '1')
            out += tmp, out %= mod;
        tmp = (tmp << 1) % mod;
    }
    cout << out << endl;
    return 0;
}