#include <bits/stdc++.h>
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int tester = 0; int n, k, ans;
        cin >> n >> k;
        // check from 1 to n
        for(int i = 0; i < n; ++i)
        {
            cout << (i ^ tester) << endl;
            tester ^= (i ^ tester);
            cin >> ans;
            if(ans == 1)
                break;
        }
    }
    return 0;
}