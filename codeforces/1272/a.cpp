#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

int average(int a, int b, int c)
{
    return round((a + (double)b + c) / 3.0);
}

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int avg = average(a, b, c);

    if(a < avg) ++a;
    else if(a > avg) --a;
    if(b < avg) ++b;
    else if(b > avg) --b;
    if(c < avg) ++ c;
    else if(c > avg) --c;

    cout << abs(a - b) + abs(a - c) + abs(b - c) << endl;
}

int main()
{
    int q;
    cin >> q;
    while(q--) solve();
    return 0;
}
