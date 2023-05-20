#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < k; ++i) {
            vector<int> tmp;
            for(int j = i; j < n; j += k)
                tmp.push_back(a[j]);
            sort(tmp.begin(), tmp.end());
            for(int j = i; j < n; j += k)
                a[j] = tmp[j / k];
        }
        bool sorted = 1;
        for(int i = 0; i < n; ++i) {
            if(a[i] != i + 1)
                sorted = 0;
        }
        if(sorted) {
            cout << 0 << endl;
            continue;
        }
        int incorrect = 0;
        for(int i = 0; i < n; ++i) {
            if((a[i] - 1) % k != i % k)
                ++incorrect;
        }
        if(incorrect <= 2)
            cout << 1 << endl;
        else
            cout << -1 << endl;
    }
}