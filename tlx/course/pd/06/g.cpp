#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, in, a = INT_MAX, b = INT_MIN;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> in, a = min(a, in), b = max(b, in);
    cout << b << " " << a << endl;
    return 0;
}