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
    int n, m;
    cin >> n >> m;
    int x[n + 1];
    for(int i = 0; i < n; ++i) 
        cin >> x[i];
    string a[n + 1];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int arr_res[m];
    // a bipartite graph?
    // we either try to minimize or maximize the value of a student
    // so bitmask
    // we go through each question and check min student count and max student count
    ll res = -1e9;
    pair<int, int> sorted[m];
    for(int bitmask = 0; bitmask < (1 << n); ++bitmask) {
        // 0 -> lebih rendah, 1 -> lebih tinggi
        ll tmp[n];
        for(int i = 0; i < n; ++i)
            tmp[i] = x[i];
        for(int i = 0; i < n; ++i) {
            if(bitmask & (1 << i))
                tmp[i] *= -1;
        }
        for(int i = 0; i < m; ++i) {
            int cnt = 0;
            for(int j = 0; j < n; ++j) {
                if(a[j][i] == '1') {
                    if((1 << j) & bitmask)
                        ++cnt;
                    else
                        --cnt;
                }
            }
            sorted[i] = mp(cnt, i);
        }
        sort(sorted, sorted + m);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(a[j][sorted[i].se] == '1') {
                    if((1 << j) & bitmask)
                        tmp[j] += i + 1;
                    else
                        tmp[j] -= i + 1;
                }
            }
        }
        ll cur = 0;
        for(int i = 0; i < n; ++i) {
            cur += tmp[i];
        }
        if(cur > res) {
            res = cur;
            //cout << bitmask << " " << cur << endl;
            for(int i = 0; i < m; ++i) {
                arr_res[sorted[i].se] = i + 1;
                //cout << sorted[i].fi << " ";
            }
            //cout << endl;
        }
    }
    for(int i = 0; i < m; ++i)
        cout << arr_res[i] << " ";
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