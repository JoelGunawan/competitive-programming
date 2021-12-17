#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ll long long
#define lll __int128
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int cycle(int number, int max) {
    number <<= 1;
    if(number >= 1 << max)
        number -= 1 << max, number += 1;
    return number;
}
bool sort_by_max(vector<int> a, vector<int> b) {
    int a_max = 0, b_max = 0;
    for(int i = 0; i < a.size(); ++i)
        a_max = max(a[i], a_max);
    for(int i = 0; i < b.size(); ++i)
        b_max = max(b[i], b_max);
    return a_max > b_max;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    // select first n rows
    vector<int> input[m];
    for(int i = 0; i < m; ++i) {
        vector<int> tmp(n);
        for(int j = 0; j < n; ++j)
            cin >> tmp[j];
        input[i] = tmp;
    }
    sort(input, input + m, sort_by_max);
    int ar_s = min(n, m);
    vector<int> ar[ar_s];
    for(int i = 0; i < ar_s; ++i)
        ar[i] = input[i];
    int prev[1 << n], now[1 << n], mapping[1 << n];
    memset(prev, 0, sizeof(prev));
    memset(mapping, -1, sizeof(mapping));
    // precompute the rotation of the bit
    for(int i = 0; i < 1 << n; ++i) {
        // cek kalo rotasinya itu sudah exist
        // kalo ga exist set ke yang sekarang
        int x = i, cur_mapping = i;
        for(int j = 0; j < n - 1; ++j) {
            x = cycle(x, n);
            if(mapping[x] != -1)
                cur_mapping = mapping[x];
        }
        mapping[i] = cur_mapping;
    }
    for(int i = 0; i < ar_s; ++i) {
        memset(now, 0, sizeof(now));
        for(int j = 0; j < 1 << n; ++j) {
            // pake mapping dari current bit
            int local = 0;
            for(int k = 0; k < n; ++k)
                if(!((1 << k) & j))
                    now[j + (1 << k)] = max(max(prev[j + (1 << k)], now[j + (1 << k)]), max(prev[mapping[j]], now[j]) + ar[i][k]);
        }
        // move now to prev
        for(int j = 0; j < 1 << n; ++j) {
            prev[mapping[j]] = max(prev[mapping[j]], now[j]);
        }
    }
    cout << now[(1 << n) - 1] << endl;
    return 0;
}