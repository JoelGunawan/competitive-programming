#include <iostream>

using namespace std;

int power(int x, int y)
{
    if(y == 0) return 1;
    else if(y % 2 == 0)
    {
        int tmp = power(x, y / 2);
        return tmp * tmp;
    }
    else return x * power(x, y - 1);
}

void solve()
{
    int c, sum;
    cin >> c >> sum;
    if(sum > c)
    {
        cout << (c - sum % c) * power(sum / c, 2) + (sum % c) * power(sum / c + 1, 2) << endl;;
    }
    else
    {
        cout << sum << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    while(n--) solve();
    return 0;
}
