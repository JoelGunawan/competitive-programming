#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ins insert
#define pf push_front
#define endl "\n"
using namespace std;
int main()
{
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i)
    {
        int querytype;
        cin >> querytype;
        if(querytype == 1)
        {
            int l, r, x;
            cin >> l >> r >> x, --l, --r;
            for(int j = l; j <= r; ++j)
                a[j] += x;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            --l, --r;
            vector<ll> sequence = {a[l]};
            int state = -1;
            for(int i = l + 1; i <= r; ++i)
            {
                if(state == -1)
                {
                    if(a[i] > sequence[sequence.size() - 1])
                        sequence.pb(a[i]), state = 0;
                    else if(a[i] < sequence[sequence.size() - 1])
                        sequence.pb(a[i]), state = 1;
                }
                // should be going down
                else if(state == 0)
                {
                    if(a[i] > sequence[sequence.size() - 1])
                        sequence[sequence.size() - 1] = a[i];
                    else if(a[i] != sequence[sequence.size() - 1])
                        sequence.pb(a[i]), state = 1;
                }
                // should be going up
                else 
                {
                    if(a[i] < sequence[sequence.size() - 1])
                        sequence[sequence.size() - 1] = a[i];
                    else if(a[i] != sequence[sequence.size() - 1])
                        sequence.pb(a[i]), state = 0;
                }
            }
            cout << sequence.size() << endl;
        }
    }
    
    return 0;
}