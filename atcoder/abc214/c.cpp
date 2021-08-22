#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> s(n), t(n);
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    for(int i = 0; i < n; ++i)
        cin >> t[i];
    vector<int> res(n, INT_MAX - 1e9);
    for(int repeat = 0; repeat < 2; ++repeat)
    {
        for(int i = 0; i < n; ++i)
            res[i] = min(res[(i - 1 + n) % n] + s[(i - 1 + n) % n], min(t[i], res[i]));
    }
    for(int i = 0; i < n; ++i)
        cout << res[i] << endl;
}