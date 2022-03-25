#include <bits/stdc++.h>
#include "server.h"
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n - 1), b(n - 1), c(n - 1);
    for(int i = 0; i < n - 1; ++i)
        cin >> a[i] >> b[i] >> c[i];
    vector<int> res = server(n, a, b, c);
    for(auto i : res)
        cout << i;
    cout << endl;
}