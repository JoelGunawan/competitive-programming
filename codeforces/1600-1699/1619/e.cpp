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
void tc() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int cnt[n + 1];
    memset(cnt, 0, sizeof(cnt));
    bool pos = 1;
    int idx = 0;
    for(int i = 0; i < n; ++i)
        ++cnt[a[i]];
    multiset<int> unused;
    ll prev_cost = 0;
    for(int i = 0; i <= n; ++i) {
        if(!pos) {
            cout << -1 << " ";
            continue;
        }
        int cur_cost = 0;
        if(i != 0) {
            if(unused.size() == 0) {
                cout << -1 << " ";
                pos = 0;
                continue;
            }
            else
                cur_cost += i - *--unused.end() - 1, unused.erase(--unused.end());
        }
        prev_cost += cur_cost;
        cout << prev_cost + cnt[i] << " ";
        for(int j = 0; j < cnt[i]; ++j)
            unused.ins(i);
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) 
        tc();
    return 0;
}