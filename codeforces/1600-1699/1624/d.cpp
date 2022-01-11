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
        int cnt[26], odd_cnt = 0;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; ++i) {
            char x;
            cin >> x;
            ++cnt[x - 'a'];
        }
        for(int i = 0; i < 26; ++i)
            if(cnt[i] & 1)
                ++odd_cnt;
        //cout << n << " " << odd_cnt << " " << k << endl;
        int res = (n - odd_cnt) / k;
        if(res % 2 == 0 && n / k > res)
            ++res;
        cout << res << endl;
    }
    return 0;
}