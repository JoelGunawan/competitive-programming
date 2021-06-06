#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if(a == 9 && b == 1)
    {
        cout << a << " " << b << 0 << endl;
    }
    else if(b - a > 1 || b - a < 0)
    {
        cout << -1 << endl;
    }
    else if(a == b)
    {
        cout << a << 0 << " " << b << 1 << endl;
    }
    else
    {
        cout << a << 9 << " " << b << 0 << endl;
    }
    return 0;
}
