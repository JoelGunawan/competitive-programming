#include <iostream>

#define ll long long int

using namespace std;

ll pow(ll x, ll y)
{
    if(y == 0) return 1;
    else if(y == 1) return x;
    else if(y % 2 == 0) return pow(x, y / 2) * pow(x, y / 2);
    else return pow(x, y - 1) * x;
}

void solve()
{
    int n;
    cin >> n;
    int i = 1;
    while(true)
    {
        int tmp = pow(2, i + 1) - 1;
        if(n % tmp == 0)
        {
            cout << n / tmp << endl;
            break;
        }
        i++;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
