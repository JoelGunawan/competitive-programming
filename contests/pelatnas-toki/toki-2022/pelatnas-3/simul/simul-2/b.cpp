#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<pair<int, int>> ans;
void solve(int n) {
    if(n % 2 == 0)
        --n;
    // buat n / 2 + 1 garis
    int lines = n / 2 + 1;
    cout << lines << endl;
    for(int i = 0; i < lines; ++i)
        cout << i + 1 << " " << i + lines << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // pake sistem prefix?
    int n, t;
    cin >> n >> t;
    pair<int, int> a[t];
    for(int i = 0; i < t; ++i)
        cin >> a[i].first >> a[i].second;
    if(n == 1)
        cout << 0 << endl, exit(0);
    
    return 0;
}