#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long number;
    if(n < 0)
        number = -n * 2;
    else
        number = 2 * n - 1;
    cout << number * (number + 1) / 2 << endl;
    return 0;
}