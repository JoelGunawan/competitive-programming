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
        int n;
        cin >> n;
        if(n % 3 == 0)
            cout << n / 3 << " " << n / 3 << endl;
        else if(n % 3 == 1)
            cout << n / 3 + 1 << " " << n / 3 << endl;
        else if(n % 3 == 2)
            cout << n / 3 << " " << n / 3 + 1 << endl;
    }
    return 0;
}