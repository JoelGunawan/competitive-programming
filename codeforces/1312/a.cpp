#include <bits/stdc++.h>

using namespace std;

void tc()
{
    int n, m;
    cin >> n >> m;
    if(n % m == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}
