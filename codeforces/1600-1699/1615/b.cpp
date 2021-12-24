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
int prefix[31][200001];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 1; i <= 200000; ++i) {
        for(int j = 0; j < 31; ++j) {
            prefix[j][i] = prefix[j][i - 1];
            if(i & (1 << j))
                ++prefix[j][i];
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        int m = 0;
        for(int i = 0; i < 31; ++i)
            m = max(m, prefix[i][r] - prefix[i][l - 1]);
        cout << r - l + 1 - m << endl;
    }
    return 0;
}