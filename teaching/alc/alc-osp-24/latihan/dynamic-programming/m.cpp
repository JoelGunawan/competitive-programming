#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    map<int, int> dp, cur;
    int pr[n + 1];
    memset(pr, -1, sizeof(pr));
    for(int i = 1; i <= n; ++i) {
        dp[a[i]] = dp[a[i] - 1] + 1;
        cur[a[i]] = i;
        if(cur[a[i] - 1]) {
            pr[i] = cur[a[i] - 1];
        }
    }
    int mx = 0, tempat = 0;
    for(auto x : dp) {
        if(x.second > mx) {
            mx = x.second;
            tempat = cur[x.first];
        }
    }
    cout << mx << endl;
    vector<int> v;
    while(tempat != -1) {
        v.push_back(tempat);
        tempat = pr[tempat];
    }
    reverse(v.begin(), v.end());
    for(auto x : v)
        cout << x << " ";
    cout << endl;
}