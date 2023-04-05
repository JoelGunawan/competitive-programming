// header file
#include <bits/stdc++.h>
// pragma
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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int dp[2][5005];
    pair<int, int> a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i].fi >> a[i].se;
    for(int i = 1; i <= 5000; ++i)
        dp[0][i] = 0;
    // buat algo pakai deque utk cari next closest minimum
    for(int i = 1; i <= n; ++i) {
        deque<int> dq;
        for(int j = 1; j <= a[i].se - a[i].fi + 1; ++j) {
            //cout << "GET " << j << endl; 
            while(dq.size() && dp[(i - 1) & 1][dq.back()] >= dp[(i - 1) & 1][j]) {
                //cout << "OUT " << dq.back() << endl;
                dq.pop_back();
            }
            dq.push_back(j);
        }
        for(int j = 1; j <= 300; ++j) {
            //cout << "GET " << j + a[i].se - a[i].fi << endl;
            if(j + a[i].se - a[i].fi <= 300) {
                while(dq.size() && dp[(i - 1) & 1][dq.back()] >= dp[(i - 1) & 1][j + a[i].se - a[i].fi]) {
                    //cout << "OUT " << dq.back() << endl;
                    dq.pop_back();
                }
                //if(dq.size())
                //    cout << dp[i - 1][dq.back()] << " " << dp[i - 1][j + a[i].se - a[i].fi] << endl;
                dq.push_back(j + a[i].se - a[i].fi);
            }
            while(dq.front() + a[i - 1].se - a[i - 1].fi < j)
                dq.pop_front();
            //cout << dq.front() << " ";
            // ambil dq.front() aja
                dp[i & 1][j] = dp[(i - 1) & 1][dq.front()] + abs(a[i].fi - j);
            //cout << dp[i][j] << " ";
            //cout << dq.front() << endl;
        }
        //cout << endl;
    }
  //  cout << endl;
    int tmp = 1e9;
    for(int i = 1; i <= 300; ++i) {
        tmp = min(tmp, dp[n & 1][i]);
    }
    cout << tmp << endl;
    return 0;
}