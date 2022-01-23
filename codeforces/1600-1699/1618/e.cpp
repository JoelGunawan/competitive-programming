// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
// header file
#include <bits/stdc++.h>
// pragma
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
// macros
#define endl "\r\n"
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
    ll n;
    cin >> n;
    ll b[n], sum = 0;
    for(int i = 0; i < n; ++i)
        cin >> b[i], sum += b[i];
    if(sum % (n * (n + 1) / 2) != 0) {
        cout << "NO" << endl;
        return;
    }
    ll total = sum / ((n * (n + 1)) / 2);
    ll ans[n];
    bool exist = 1;
    ll checksum = 0;
    for(int i = 0; i < n; ++i) {
        ans[(i + 1) % n] = (total + (b[i] - b[(i + 1) % n])) / n;     
        if(ans[(i + 1) % n] <= 0)
            exist = 0;
        checksum += ans[(i + 1) % n];
    }
    checksum *= n * (n + 1) / 2;
    if(!exist || checksum != sum) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; ++i) 
        cout << ans[i] << " ";
    cout << endl;
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}