// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
int query(int x) {
    cout << "? " << x << endl;
    int a;
    cin >> a;
    return a;
}
void tc() {
    int n;
    cin >> n;
    int ans[n + 1];
    memset(ans, -1, sizeof(ans));
    for(int i = 1; i <= n; ++i) {
        if(ans[i] != -1)
            continue;
        vector<int> x = {query(i)};
        int q;
        while((q = query(i)) != x[0]) {
            x.pb(q);
        }
        for(int j = 0; j < x.size(); ++j) {
            ans[x[j]] = x[(j + 1) % x.size()];
        }
    }
    cout << "! ";
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}