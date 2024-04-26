#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    while(cin >> n) {
        if(n == 0) {
            break;
        }
        int a[n + 1];
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        vector<int> v;
        int x = 1; // yang perlu kita ambil selanjutnya di kanan (setelah jalan samping)
        for(int i = 1; i <= n; ++i) {
            // keluarkan dari jalan samping dlu sebanyak mgkn
            while(v.size() && v.back() == x) {
                v.pop_back();
                ++x;
            }
            if(a[i] == x) {
                // langsung ga usah ke jalan samping
                ++x;
            }
            else {
                // ke jalan samping
                v.push_back(a[i]);
            }
        }
        while(v.size() && v.back() == x) {
            v.pop_back();
            ++x;
        }
        if(x == n + 1) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
}