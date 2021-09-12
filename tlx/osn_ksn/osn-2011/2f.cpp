#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    char in;
    int a[26];
    memset(a, 0, sizeof(a));
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> in, ++a[in - 'A'];
    sort(a, a + 26, greater<int>());
    if(min(a[0], a[2] + 1) + min(a[1], a[2] + 1) + a[2] < 3)
        cout << -1;
    else
        cout << min(a[0], a[2] + 1) + min(a[1], a[2] + 1) + a[2];
    cout << endl;
    return 0;
}