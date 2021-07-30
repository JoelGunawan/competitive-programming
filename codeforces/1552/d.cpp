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
        unordered_map<int, int> done;
        bool ans = 0;
        for(int i = 0; i < (1 << n); ++i)
        {
            int sum = 0;
            for(int j = 0; j < n; ++j)
                if(i & (1 << j))
                    sum += a[j];
            if(done[sum])
            {
                ans = 1;
                break;
            }
            else
                ++done[sum];
        }
        if(ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;   
}