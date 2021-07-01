#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<double> l(n), r(n);
    for(int i = 0; i < n; ++i)
    {
        int t;
        cin >> t >> l[i] >> r[i];
        if(t == 2 || t == 4)
            r[i] -= 0.5;
        if(t == 3 || t == 4)
            l[i] += 0.5;
    }
    int res = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if((l[j] <= r[i] && r[j] >= r[i])
            || (l[j] <= l[i] && r[j] >= l[i])
            || (l[j] >= l[i] && r[j] <= r[i])
            || (l[j] <= l[i] && r[j] >= r[i]))
                ++res;            
        }
   }
   cout << res << endl;
}