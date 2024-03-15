#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    int x[n];
    long long pref[n];
    for(int i = 0; i < n; ++i) {
        cin >> x[i];
        if(i == 0)
            pref[i] = x[i];
        else
            pref[i] = pref[i - 1] + x[i];
    }
    while(q--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if(a == 0)
            cout << pref[b] << endl;
        else
            cout << pref[b] - pref[a - 1] << endl;
    }
}