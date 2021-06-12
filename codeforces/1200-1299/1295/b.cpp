#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, x; string s;
        cin >> n >> x >> s;
        int sum = 0;
        vector<int> prefix(n);
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '0')
                ++sum;
            else
                --sum;
            prefix[i] = sum;
        }
        int res = 0;
        if(x == 0)
            ++res;
        if(sum == 0)
        {
            // check if there is an intersect with x
            bool inf = 0;
            for(int i = 0; i < n; ++i)
                if(prefix[i] == x)
                {
                    inf = 1;
                    break;
                }
            if(inf)
                cout << -1;
            else
                cout << res;
            cout << endl;
        }
        else
        {
            for(int i = 0; i < n; ++i)
            {
                if((x - prefix[i]) / sum >= 0 && (x - prefix[i]) % sum == 0)
                    ++res;
            }
            cout << res << endl;
        }
    }
}