#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int res = 1e3;
    --res;
    cout << (3 * (res / 3) * (res / 3 + 1) + 5 * (res / 5) * (res / 5 + 1) - 15 * (res / 15) * (res / 15 + 1)) / 2 << endl;
    return 0;
}