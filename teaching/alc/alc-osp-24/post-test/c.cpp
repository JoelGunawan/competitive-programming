#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int tc = 0; tc < t; ++tc) {
        int n;
        string s;
        cin >> n >> s;
        int sementara = 0;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            sementara += s[i] - '0';
            a[n - i - 1] = sementara;
        }
        for(int i = 0; i < n; ++i) {
            if(a[i] >= 10) {
                // dia harus pindah sisanya
                int pindah = a[i] / 10;
                int tidak_pindah = a[i] % 10;
                a[i] = tidak_pindah;
                if(i == n - 1) {
                    a.push_back(pindah);
                }
                else {
                    a[i + 1] += pindah;
                }
            }
        }
        while(a.size() > 1 && a.back() == 0)
            a.pop_back();
        for(int i = a.size() - 1; i >= 0; --i) {
            cout << a[i];
        }
        cout << endl;
    }
}