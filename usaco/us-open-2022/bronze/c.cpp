// header file
#include <bits/stdc++.h>
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
vector<int> child[105];
int a[105];
bool get_one(int nd) {
    if(a[nd]) {
        --a[nd];
        return 1;
    }
    else {
        if(child[nd].size() == 0)
            return 0;
        else {
            bool ans = 1;
            for(auto i : child[nd]) {
                if(!get_one(i))
                    ans = 0;
            }
            return ans; 
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int k;
    cin >> k;
    for(int i = 0; i < k; ++i) {
        int l, m;
        cin >> l >> m;
        for(int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            child[l].pb(x);
        }
    }
    if(child[n].size() == 0)
        cout << a[n] << endl, exit(0);
    bool add = 1;
    while(add) {
        for(auto i : child[n])
            if(!get_one(i))
                add = 0;
        if(add)
            ++a[n];
    }
    cout << a[n] << endl;
    return 0;
}