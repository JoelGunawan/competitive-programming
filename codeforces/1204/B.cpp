#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    int n, l, r;
    cin >> n >> l >> r;
    ll mins = 0, maxs = 0;
    for(int i = 0; i < n; ++i)
    {
        if(i >= l) ++mins;
        else mins += pow(2, i);
    }
    cout << mins << " ";
    for(int i = 0; i < n; ++i)
    {
        if(i >= r) maxs += pow(2, r - 1);
        else maxs += pow(2, i);
    }
    cout << maxs << endl;
    return 0;
}
