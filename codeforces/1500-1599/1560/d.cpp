#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    vector<string> a;
    ll num = 1;
    while(num < 1e18)
        a.push_back(to_string(num)), num *= 2;
    while(t--)
    {
        string n;
        cin >> n;
        int res = INT_MAX;
        // check to every string
        for(int i = 0; i < a.size(); ++i)
        {
            int index = 0;
            for(int j = 0; j < n.size(); ++j)
            {
                if(index == a[i].size())
                    break;
                else if(a[i][index] == n[j])
                    ++index;
            }
            res = min(res, (int)n.size() - index + (int)a[i].size() - index);
        }
        cout << res << endl;
    }
}