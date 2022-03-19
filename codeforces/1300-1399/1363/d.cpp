// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
int ans[1005];
vector<vector<int>> segments;
int query(vector<int> arr) {
    cout << "? " << arr.size() << " ";
    for(int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
    int in;
    cin >> in;
    return in;
}
void dnc(int l, int r, int prev_max) {
    if(l == r) {
        vector<int> tmp;
        for(int i = 0; i < l; ++i) {
            for(auto j : segments[i])
                tmp.pb(j);
        }
        for(int i = l + 1; i < segments.size(); ++i) {
            for(auto j : segments[i])
                tmp.pb(j);
        }
        ans[l] = query(tmp);
        return;
    }
    int mid = (l + r) / 2;
    //cout << l << " " << mid << " " << r << endl;
    vector<int> tmp;
    for(int i = l; i <= mid; ++i) {
        for(auto j : segments[i])
            tmp.pb(j);
    }
    int q = query(tmp);
    if(q == prev_max) {
        for(int i = mid + 1; i <= r; ++i)
            ans[i] = prev_max;
        dnc(l, mid, prev_max);
    }
    else {
        for(int i = l; i <= r; ++i)
            ans[i] = prev_max;
        dnc(mid + 1, r, prev_max);
    }
}
void tc() {
    memset(ans, 0, sizeof(ans));
    int n, k;
    cin >> n >> k;
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    memset(ans, 0, sizeof(ans));
    segments.clear();
    for(int i = 0; i < k; ++i) {
        int c;
        cin >> c;
        vector<int> tmp(c);
        for(int j = 0; j < c; ++j)
            cin >> tmp[j], vis[tmp[j]] = 1;
        segments.pb(tmp);
    }
    vector<int> tmp, tmp2;
    for(int i = 1; i <= n; ++i) {
        if(!vis[i])
            tmp.pb(i);
        tmp2.pb(i);
    }
    if(tmp.size() > 0) {
        segments.pb(tmp);
    }
    dnc(0, segments.size() - 1, query(tmp2));
    cout << "! ";
    for(int i = 0; i < k; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;   
    string input;
    cin >> input;
    assert(input == "Correct");
}
int main() {
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}