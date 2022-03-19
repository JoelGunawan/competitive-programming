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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        int a[n];
        int odd_cnt = 0, even_cnt = 0;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if(x & 1)
                ++odd_cnt;
            else
                ++even_cnt;
        }
        if(n == x) {
            if(odd_cnt & 1)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else {
            if(even_cnt == 0) {
                if(x & 1)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
            else if(odd_cnt != 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}