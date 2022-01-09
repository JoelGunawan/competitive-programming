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
struct bit {
    vector<int> a;
    bit(int size) {
        a = vector<int>(size + 5, 0);
    }
    void update(int x, int val) {
        //cout << x << endl;
        while(x < a.size()) {
            a[x] += val;
            x += (x&-x);
        }
    }
    int query(int l, int r) {
        --l;
        //cout << l << " " << r << " ";
        int left = 0, right = 0;
        while(l > 0) {
            left += a[l];
            l -= (l&-l);
        }
        while(r > 0) {
            right += a[r];
            r -= (r&-r);
        }
        //cout << right - left << endl;
        return right - left;
    }
};
void tc() {
    int n; string s, t;
    cin >> n >> s >> t;
    bit bit(n + 5);
    string tmp = s;
    sort(tmp.begin(), tmp.end());
    if(tmp >= t) {
        cout << -1 << endl;
        return;
    }
    ll cur_cost = 0, res = LLONG_MAX;
    vector<int> arr[26];
    for(int i = n - 1; i >= 0; --i) {
        arr[s[i] - 'a'].pb(i);
    }
    // do for 0 common
    for(int i = 0; i < t[0] - 'a'; ++i) {
        if(arr[i].size() > 0)
            res = min(res, 1ll * arr[i].back());
    }
    for(int i = 0; i < n - 1; ++i) {
        int cur = t[i] - 'a';
        if(arr[cur].size() == 0)
            break;
        else {
            int x = arr[cur].back();
            x = x + bit.query(x + 1, n + 1);
            cur_cost += x - i;
            bit.update(arr[cur].back() + 1, 1);
            arr[cur].pop_back();
        }
        ll local_cost = 1e18;
        for(int j = 0; j < t[i + 1] - 'a'; ++j) {
            if(arr[j].size() > 0) {
                ll x = arr[j].back();
                x = x + bit.query(x + 1, n + 1);
                local_cost = min(local_cost, x - i - 1);
            }
        }
        res = min(res, local_cost + cur_cost);
    }
    cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while(q--)
        tc();
    return 0;
}