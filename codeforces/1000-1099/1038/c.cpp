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
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    sort(a, a + n, greater<int>());
    sort(b, b + n, greater<int>());
    int idx1 = 0, idx2 = 0;
    ll ascore = 0, bscore = 0;
    for(int i = 0; i < 2 * n; ++i) {
        if(i % 2 == 0) {
            if(idx1 < n && (idx2 == n || a[idx1] > b[idx2]))
                ascore += a[idx1++];
            else if(idx2 < n && (idx1 == n || a[idx1] <= b[idx2]))
                ++idx2;
        }
        else {
            if(idx1 < n && (idx2 == n || a[idx1] >= b[idx2]))
                ++idx1;
            else if(idx2 < n && (idx1 == n || a[idx1] < b[idx2]))
                bscore += b[idx2++];
        }
    }
    cout << ascore - bscore << endl;
    return 0;
}