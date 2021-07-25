#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void test_case()
{
    int n, m, k;
    cin >> n >> m >> k;
    if((n * m) & 1)
        cout << "NO" << endl;
    else if(n % 2 == 0 && m % 2 == 0)
    {
        if(k & 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    else if(n % 2 == 0)
    {
        if(k % 2 == 1 || 2 * k > n * (m - 1))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    else
    {
        if(2 * k >= m && (2 * k - m) % 4 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;   
    }
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