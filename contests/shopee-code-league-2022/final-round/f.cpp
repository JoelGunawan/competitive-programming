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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].fi >> a[i].se;
    sort(a, a + n);
    // find max sum of a[i].se
    // greedynya by largest
    // sort by largest
    multiset<int> num;
    for(int i = 0; i < n; ++i) {
        num.insert(a[i].se);
        while(num.size() > a[i].fi)
            num.erase(num.begin());
    }
    ll res = 0;
    for(int i : num)
        res += i;
    cout << res << endl;
    return 0;
}