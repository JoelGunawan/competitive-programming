#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    if(m == 1 || n == 1)
        cout << m * n;
    else
        cout << m + n;
}