// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
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

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int l = 1, r = n - 1;
    while(l < r) {
        int mid = (l + r) / 2 + ((l + r) % 2);
        if(mid % n == 0)
            --mid;
        cout << "+ " << mid / n * n + n - mid << endl;
        int ans;
        cin >> ans;
        if(ans == mid / n) {
            r = mid - 1;
        }
        else {
            l = mid;
        }
        l += mid / n * n + n - mid, r += mid / n * n + n - mid;
    }
    cout << "! " << l << endl;
    return 0;
}