#include <iostream>

using namespace std;

long long maximum(long long a, long long b)
{
    if(a > b) return a;
    else return b;
}

void solve()
{
    int a, b, n, s;
    cin >> a >> b >> n >> s;
    if(b >= maximum(s - (long long)n * a, s % n)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
