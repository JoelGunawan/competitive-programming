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
        int n, k;
        cin >> n >> k;
        int x[k];
        for(int i = 0; i < k; ++i)
            cin >> x[i];
        int cat = 0, res = 0;
        sort(x, x + k, greater<int>());
        for(int i = 0; i < k; ++i) {
            if(cat < x[i])
                ++res, cat += n - x[i];
        }
        cout << res << endl;
    }
    return 0;
}