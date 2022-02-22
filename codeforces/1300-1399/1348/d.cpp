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
    // 11 as example
    // 11 - 1 >= 4 * 1
    // split all because there is always a way to make it
    int cnt = 1, days = 0;
    --n;
    vector<int> ans;
    while(n > 0) {
        // if it is less than 4n
        // then find a winning solution
        //cout << n << " " << cnt << endl;
        if(n >= 4 * cnt) {
            ans.pb(cnt);
            cnt += ans.back();
            n -= cnt;
        }
        else if(n > 2 * cnt) {
            // find a solution that makes it so that
            // the remaining n is bigger than cnt
            // but the current cnt is maximum
            // find a new cnt such that cnt <= n / 2
            // and cnt is maximum
            // new cnt is n / 2
            ans.pb(n / 2 - cnt);
            cnt += ans.back();
            n -= cnt;
        }
        else {
            // find a solution that is correct
            n -= cnt;
            ans.pb(n);
            n = 0;
        }
        ++days;
    }
    //cout << n << endl;
    cout << days << endl;
    for(auto i : ans)
        cout << i << " ";
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}