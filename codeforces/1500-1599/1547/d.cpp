#include <bits/stdc++.h>
#define endl "\n"
#define rll register int_fast64_t
#define rint register int_fast32_t
#define v vector
#define pb push_back
#define ins insert
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
void test_case()
{
    int n;
    cin >> n;
    int x[n], res[n];
    for(rint i = 0; i < n; ++i)
        cin >> x[i];
    res[0] = 0;
    rint prev = x[0];
    for(rint i = 1; i < n; ++i)
    {
        res[i] = 0;
        rint tmp = (prev & x[i]);
        if(tmp < prev)
            res[i] += (prev - tmp);
        prev = res[i] ^ x[i]; 
    }
    for(rint i = 0; i < n; ++i)
        cout << res[i] << " ";
    cout << endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}