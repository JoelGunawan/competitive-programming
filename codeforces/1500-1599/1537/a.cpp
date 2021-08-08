#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        int sum = 0;
        for(int i = 0; i < n; ++i)
            sum += a[i];
        if(sum < n)
            cout << 1;
        else if(sum == n)
            cout << 0;
        else
            cout << sum - n;
        cout << endl;
    }
}