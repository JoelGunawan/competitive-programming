#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string subsoal; int x, y;
    cin >> subsoal >> x >> y;
    // make it so x == y in our moves
    while(x > 1 || y > 1)
    {
        cout << min(x, y) << " " << min(x, y) << endl;
        if(min(x, y) == 1)
            break;
        cin >> x >> y;
    }
    return 0;
}