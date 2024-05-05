#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for(auto c : s) {
        ++cnt[c - 'A'];
    }
    sort(cnt, cnt + 26);
    reverse(cnt, cnt + 26);
    // maksimum ke 3 -> cnt[2];
    if(cnt[2] == 0) {
        cout << -1 << endl;
    }
    else {
        cout << cnt[2] + min(cnt[2] + 1, cnt[1]) + min(cnt[2] + 1, cnt[0]) << endl;;
    }
}