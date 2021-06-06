#include <bits/stdc++.h>

using namespace std;

void tc()
{
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if((y - x) % (a + b))
        cout << -1;
    else
        cout << (y - x) / (a + b);
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}
