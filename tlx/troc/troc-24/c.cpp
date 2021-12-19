#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define lll __int128
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fi first
#define se second
#define ins insert
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i = 0; i < k; ++i) {
        int idx_nol = -1, idx_satu = -1, nol = 0, satu = 0;
        for(int j = 0; j < n; ++j) {
            if(s[j] == '1' && idx_satu == -1)
                idx_satu = j;
            if(idx_satu != -1 && s[j] == '0')
                ++satu;
        }
        for(int j = n - 1; j >= 0; --j) {
            if(s[j] == '0' && idx_nol == -1)
                idx_nol = j;
            if(idx_nol != -1 && s[j] == '1')
                ++nol;
        }
        if(idx_nol != -1 && (idx_satu == -1 || nol > satu))
            s[idx_nol] = '1';
        else if(idx_satu != -1)
            s[idx_satu] = '0';
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '1') {
            for(int j = i + 1; j < n; ++j)
                if(s[j] == '0')
                    ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}