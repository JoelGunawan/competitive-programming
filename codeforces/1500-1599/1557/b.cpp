#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        vector<int> b = a;
        sort(b.begin(), b.end());
        int prev = a[0], counter = 1;
        for(int i = 1; i < n; ++i)
        {
            if(prev != *(--lower_bound(b.begin(), b.end(), a[i])))
                ++counter;
            prev = a[i];
        }      
        if(counter <= k)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;  
    }
    return 0;
}