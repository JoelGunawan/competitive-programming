#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

void solve()
{
    int a, b;
    cin >> a >> b;
    if(gcd(a, b) == 1) cout << "Finite";
    else cout << "Infinite";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
