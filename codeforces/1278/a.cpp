#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string p, h;
    cin >> p >> h;
    sort(p.begin(), p.end());
    if(p.size() > h.size())
    {
        cout << "NO" << endl;
    }
    else if(p.size() == h.size())
    {
        sort(h.begin(), h.end());
        if(p == h)
        {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    else
    {
        for(int i = 0; i < h.size() - p.size() + 1; ++i)
        {
            string tmp = h.substr(i, p.size());
            sort(tmp.begin(), tmp.end());
            {
                if(p == tmp)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        cout << "NO" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
