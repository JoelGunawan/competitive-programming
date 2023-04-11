#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[0] = 1e9;
    stack<int> s;
    s.push(0);
    long long res = 0;
    for(int i = 1; i <= n; ++i) {
        while(a[s.top()] <= a[i])
            s.pop();
        res += i - s.top();
        s.push(i);
    }
    cout << res << endl;
}