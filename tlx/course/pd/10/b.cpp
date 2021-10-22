#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    int t;
    cin >> t;
    while(t--)
    {
        // do query
        int *x, *y;
        char in_1, in_2; int first, second;
        cin >> in_1 >> first >> in_2 >> second;
        if(in_1 == 'B')
            x = b + first - 1;
        else
            x = a + first - 1;
        if(in_2 == 'B')
            y = b + second - 1;
        else
            y = a + second - 1;
        swap(*x, *y);
    }
    for(int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
    for(int i = 0; i < n; ++i)
        cout << b[i] << " ";
    cout << endl;
    return 0;
}