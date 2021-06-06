#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    for(int i = 0; i < n; ++i)
        c[i] = a[i] - b[i];
    sort(c.begin(), c.end(), greater<int>());
    int rightPointer = n - 1;
    long long result = 0;
    for(int i = 0; i < n; ++i)
    {
        while(-c[rightPointer] >= c[i] && rightPointer >= i)
            --rightPointer;
        if(rightPointer <= i)
            break;
        else
            result += rightPointer - i;
    }
    cout << result << endl;
    return 0;
}
