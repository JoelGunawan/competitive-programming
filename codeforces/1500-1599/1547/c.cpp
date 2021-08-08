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
    rint k, n, m;
    cin >> k >> n >> m;
    v<int> a(n), b(m);
    for(rint i = 0; i < n; ++i)
        cin >> a[i];
    for(rint i = 0; i < m; ++i)
        cin >> b[i];
    rint pointer1 = -1, pointer2 = -1, prev1 = -2, prev2 = -2, index = 0;
    int res[n + m];
    while((pointer1 != n - 1 || pointer2 != m - 1) && (prev1 != pointer1 || prev2 != pointer2))
    {
        // try to forward pointer 1
        prev1 = pointer1; prev2 = pointer2;
        while(pointer1 != n - 1 && a[pointer1 + 1] <= k)
        {
            if(a[pointer1 + 1] == 0)
                ++k;
            ++pointer1;
            res[index] = a[pointer1];
            ++index;
        }
        while(pointer2 != m - 1 && b[pointer2 + 1] <= k)
        {
            if(b[pointer2 + 1] == 0)
                ++k;
            ++pointer2;
            res[index] = b[pointer2];
            ++index;
        }
    }
    if(pointer1 == n - 1 && pointer2 == m - 1)
    {
        for(rint i = 0; i < n + m; ++i)
            cout << res[i] << " ";
        cout << endl;
    }
    else
        cout << -1 << endl;

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