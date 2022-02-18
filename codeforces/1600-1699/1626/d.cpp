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
int lg[2 * (int)1e5];
void tc() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    // we can select based on weights
    // optimal way for a binary number
    // if there is 3 '1'
    // 1 on bit in lightweight, 1 on bit for middleweight, 1 on bit for heavyweight
    // consider the way we can select if we have a fixed amount of lightweight
    // binser on prefsum + bitwise
    // set what msb we want to choose
    // find the largest number <= to msb
    // if we choose the largest number
    // is it always optimal?
    // i think so?
    // segment vector
    // have a prefsum based on s
    vector<int> s = {0};
    int cur = 1;
    for(int i = 1; i < n; ++i) {
        if(a[i] != a[i - 1])
            s.pb(cur), cur = 0;
        ++cur;
    }
    s.pb(cur);
    int pref_sum[s.size()];
    pref_sum[0] = s[0];
    for(int i = 1; i < s.size(); ++i)
        pref_sum[i] = pref_sum[i - 1] + s[i];
    int res = INT_MAX;
    for(int i = 1; i < s.size(); ++i) {
        for(int j = 0; j < 20; ++j) {
            int l = i, r = s.size() - 1, cur = -1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(pref_sum[mid] - pref_sum[i - 1] <= 1 << j)
                    cur = mid, l = mid + 1;
                else
                    r = mid - 1;
            }
            if(cur != -1) {
                res = min(res, ((1 << lg[pref_sum[i - 1]]) - pref_sum[i - 1]) 
                + ((1 << j) - (pref_sum[cur] - pref_sum[i - 1]))
                + ((1 << lg[pref_sum[s.size() - 1] - pref_sum[cur]]) - (pref_sum[s.size() - 1] - pref_sum[cur])));
            }
        }
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    lg[0] = 0, lg[1] = 0;
    for(int i = 2; i <= 2 * 1e5; ++i) {
        if((i - 1) - ((i - 1)&-(i - 1)) == 0)
            lg[i] = lg[i - 1] + 1;
        else
            lg[i] = lg[i - 1];
    }
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}