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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt[k];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; ++i)
        ++cnt[s[i] - 'A'];
    int minimum = INT_MAX;
    for(int i = 0; i < k; ++i)
        minimum = min(minimum, cnt[i]);
    cout << minimum * k << endl;
    return 0;
}