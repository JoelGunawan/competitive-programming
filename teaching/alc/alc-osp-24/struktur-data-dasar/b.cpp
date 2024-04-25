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
        // selama elemen di stack itu >= elemen sekarang, pop
        while(s.size() > 0 && a[s.back()] >= a[i]) {
            s.pop_back();
        }
        if(s.size() > 0) 
            l[i] = s.back();
        else
            l[i] = 0;
        s.push_back(i);
    }
    for(int i = 1; i <= n; ++i)
        cout << l[i] << " ";
    cout << endl;
    // reset s
    s.clear();
    for(int i = n; i >= 1; --i) {
        // selama elemen di stack itu >= elemen sekarang, pop
        while(s.size() > 0 && a[s.back()] >= a[i]) {
            s.pop_back();
        }
        if(s.size() > 0) 
            r[i] = s.back();
        else
            r[i] = 0;
        s.push_back(i);
    }
    for(int i = 1; i <= n; ++i)
        cout << r[i] << " ";
    cout << endl;
}