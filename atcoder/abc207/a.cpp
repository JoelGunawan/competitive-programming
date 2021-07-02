#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b + c - min(a, min(b, c)) << endl;
}