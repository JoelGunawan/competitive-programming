#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        // artinya -> lower_bound ada/valid
        if(lower_bound(a.begin(), a.end(), x) != a.end()) {
            int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
            a[idx] = x;
        }
        else {
            a.push_back(x);
        }
    }
    cout << a.size() << endl;
}