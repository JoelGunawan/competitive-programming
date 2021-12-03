#include <bits/stdc++.h>
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pf push_front
#define ll long long
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n % 2 == 0)
            cout << 0 << endl;
        else
        {
            string s = to_string(n);
            if((s[0] - '0') % 2 == 0)
                cout << 1 << endl;
            else
            {
                bool exist_even = 0;
                for(int i = 0; i < s.size(); ++i)
                    if((s[i] - '0') % 2 == 0)
                        exist_even = 1;
                if(exist_even)
                    cout << 2 << endl;
                else
                    cout << -1 << endl;
            }
        }
    }
    return 0;
}