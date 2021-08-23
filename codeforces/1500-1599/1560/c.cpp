#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int k;
        cin >> k;
        ll x = ceil(sqrt(k)), y = 1, moves = k - ceil(sqrt(k) - 1) * ceil(sqrt(k) - 1) - 1;
        for(int i = 0; i < moves; ++i)
        {
            if(y == ceil(sqrt(k)))
                --x;
            else
                ++y;
        }
        cout << y << " " << x << endl;
    }
}