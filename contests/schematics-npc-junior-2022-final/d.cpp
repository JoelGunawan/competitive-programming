#include <bits/stdc++.h>
using namespace std;
int main() {
    // last 3 digits not div by 8 -> not div by 8
    // a mod b = (a mod 125b) mod b 
    // ambil 3 digit terakhir, cek modulo
    string s;
    cin >> s;
    int n = s.size();
    int ans[n + 1];
    s = " " + s;
    // precalc total yang 3 angka
    int cnt = 0;
    for(int i = 1; i <= n - 2; ++i) {
        string tmp = s.substr(i, 3);
        int tmp2 = stoi(tmp);
        if(tmp2 % 8 == 0)
            ++cnt;
    }
    for(int i = 1; i <= n; ++i) {
        // cek i only
        // cek i and i + 1
        // sisa pakai memo 3 angka
        int cur = 0;
        if(stoi(s.substr(i, 1)) % 8 == 0)
            ++cur;
        if(i != n && stoi(s.substr(i, 2)) % 8 == 0)
            ++cur;
        cout << cur + cnt << " ";
        if(i <= n - 2 && stoi(s.substr(i, 3)) % 8 == 0)
            --cnt;
    }   
    cout << endl;
}