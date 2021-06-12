#include <iostream>
#include <cmath>

using namespace std;

void program()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 0 << endl;
        return;
    }
    int powerof2 = 0, powerof3 = 0;
    while(n % 3 == 0)
    {
        n /= 3;
        powerof3++;
    }
    while(n % 2 == 0)
    {
        n /= 2;
        powerof2++;
    }
    if(n == 1 && powerof3 >= powerof2)
    {
        cout << powerof3 - powerof2 + powerof3 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) program();
    return 0;
}
