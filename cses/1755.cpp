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
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    string s;
    cin >> s;
    for(auto i : s) {
        ++cnt[i - 'A'];
    }
    int odd_cnt = 0;
    for(int i = 0; i < 26; ++i)
        if(cnt[i] & 1)
            ++odd_cnt;
    if(odd_cnt > 1) {
        cout << "NO SOLUTION" << endl;
    }
    else {
        string a = "", b = "";
        char mid = 0; 
        for(int i = 0; i < 26; ++i) {
            if(cnt[i] & 1)
                mid = i + 'A';
            cnt[i] /= 2;
            for(int j = 0; j < cnt[i]; ++j)
                a += i + 'A', b += i + 'A';
        }
        reverse(b.begin(), b.end());
        cout << a;
        if(mid != 0)
            cout << mid;
        cout << b << endl;
    }
    return 0;
}