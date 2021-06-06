#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    while(t--)
    {
        cin >> n;
        cout << n / 2 + n % 2 << "\n";
    }
    return 0;
}
