#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n + 1];
    map<int, int> cnt;
    for(int i = 1; i <= n; ++i)
        cin >> a[i], ++cnt[a[i]];
    int res = 0;
    for(auto i : cnt)
        res += i.second >> 1;
    cout << res << endl;
}