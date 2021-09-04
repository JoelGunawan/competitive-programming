#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long res = 0; int in;
    for(int i = 0; i < 2 * n; ++i)
        cin >> in, res += n * in;
    cout << res << endl;
}