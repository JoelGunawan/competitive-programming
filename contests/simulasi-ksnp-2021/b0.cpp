#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, cur;
    cin >> n;
    int minimum = INT_MAX, maximum = 0;
    for(int i = 0; i < n; ++i)
        cin >> cur, minimum = min(minimum, cur), maximum = max(maximum, cur);
    cout << (maximum - minimum) / 2 + (maximum - minimum) % 2 << endl;
    return 0;
}