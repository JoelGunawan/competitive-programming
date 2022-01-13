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
        int n, l;
        cin >> n >> l;
        int a[n];
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int res = 0;
        for(int i = 0; i <= l; ++i) {
            int on_cnt = 0;
            for(int j = 0; j < n; ++j) {
                if((1 << i) & a[j])
                    ++on_cnt;
            }
            if(on_cnt > n / 2)
                res += (1 << i);
        }
        cout << res << endl;
    }
    return 0;
}