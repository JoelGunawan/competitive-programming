#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    /*
    vector<int> v;
    for(int i = 1; i <= n; ++i) {
        if(lower_bound(v.begin(), v.end(), a[i]) == v.end())
            v.push_back(a[i]);
        else {
            v[lower_bound(v.begin(), v.end(), a[i])] = a[i];
        }
    }
    cout << v.size() << endl;
    */
    set<int> s;
    for(int i = 1; i <= n; ++i) {
        if(s.lower_bound(a[i]) == s.end()) {
            s.insert(a[i]);
        }
        else {
            s.erase(s.lower_bound(a[i]));
            s.insert(a[i]);    
        }
    }
    cout << s.size() << endl;
}