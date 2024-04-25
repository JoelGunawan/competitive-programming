#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n + 5];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int l[n + 5], r[n + 5];
    vector<int> s;
    for(int i = 1; i <= n; ++i) {
        while(s.size() > 0 && a[s.back()] >= a[i])
            s.pop_back();
        if(s.size() == 0)
            l[i] = 0;
        else
            l[i] = s.back();
        s.push_back(i);
    }
    s.clear();
    for(int i = n; i >= 1; --i) {
        while(s.size() > 0 && a[s.back()] >= a[i])
            s.pop_back();
        if(s.size() == 0)
            r[i] = n + 1;
        else
            r[i] = s.back();
        s.push_back(i);
    }
    long long mx = 0;
    for(int i = 1; i <= n; ++i) {
        mx = max(mx, 1ll * a[i] * (r[i] - l[i] - 1));
    }
    cout << mx << endl;
}