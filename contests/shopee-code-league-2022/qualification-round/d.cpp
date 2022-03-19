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
    int a[2 * n];
    for(int i = 0; i < 2 * n; ++i)
        cin >> a[i];
    stack<int> top, bottom;
    bool active[n + 1];
    memset(active, 0, sizeof(active));
    for(int i = 0; i < 2 * n; ++i) {
        if(!active[a[i]]) 
            top.push(a[i]);
        else {
            if(top.top() == a[i]) 
                top.pop();
            else {
                int tmp = top.top();
                top.pop();
                if(top.top() != a[i])
                    cout << "no" << endl, exit(0);
                else
                    top.pop();
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}