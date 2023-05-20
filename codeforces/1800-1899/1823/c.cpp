#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n + 1];
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        // find all prime factors   
        map<int, int> s;
        for(int i = 1; i <= n; ++i) {
            for(int j = 2; j <= sqrt(a[i]); ++j) {
                if(a[i] % j == 0) {
                    int cnt = 0;
                    while(a[i] % j == 0) {
                        ++cnt;
                        a[i] /= j;
                    }
                    s[j] += cnt;
                }
            }
            if(a[i] > 1)
                s[a[i]]++;
        }
        int res = 0, sisa = 0;
        for(auto i : s) {
            res += i.second / 2, sisa += i.second & 1;
        }
        cout << res + sisa / 3 << endl;
    }
}