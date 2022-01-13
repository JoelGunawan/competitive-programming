// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n + 1];
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        // condition -1 -> all elements are unique
        map<int, int> p;
        int res = -1;
        for(int i = 1; i <= n; ++i) {
            if(p[a[i]] == 0) {
                p[a[i]] = i;
            }
            else {
                int x = p[a[i]];
                p[a[i]] = i;
                res = max(res, n - (i - x));
            }
        }
        cout << res << endl;
    }
    return 0;
}