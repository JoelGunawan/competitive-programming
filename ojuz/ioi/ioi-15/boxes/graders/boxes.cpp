#include "boxes.h"
#include <bits/stdc++.h>
using namespace std;

long long delivery(int N, int K, int L, int p[]) {
    long long pref[N + 1], suff[N + 2];
    memset(pref, 0, sizeof(pref));
    memset(suff, 0, sizeof(suff));
    // coba ke next atau ke 0
    for(int i = 1; i <= N; ++i) {
        if(i - K < 0) {
            pref[i] = p[i - 1] + min(p[i - 1], L - p[i - 1]);
        }
        else {
            pref[i] = pref[i - K] + p[i - 1] + min(p[i - 1], L - p[i - 1]);
        }
    }
    for(int i = N; i >= 1; --i) {
        if(i + K > N)
            suff[i] = L - p[i - 1] + min(p[i - 1], L - p[i - 1]);
        else
            suff[i] = L - p[i - 1] + suff[i + K] + min(p[i - 1], L - p[i - 1]);
    }
    long long mn = 1e18;
    for(int i = 0; i <= N; ++i) {
        //cout << pref[i] << " " << suff[i + 1] << endl;
        mn = min(mn, pref[i] + suff[i + 1]);
    }
    return mn;
}
