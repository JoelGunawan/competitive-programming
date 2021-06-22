#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> prefix(n + 1, 0);
    for(int i = 1; i <= n; ++i)
        prefix[i] = prefix[i - 1] + (s[i - 1] - 'a' + 1);
    for(int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << endl;
    }
}