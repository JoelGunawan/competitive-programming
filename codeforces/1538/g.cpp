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
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if(a > b)
            swap(a, b);
        if(x > y)
            swap(x, y);
        // we need to do a search with x and b
    }
}