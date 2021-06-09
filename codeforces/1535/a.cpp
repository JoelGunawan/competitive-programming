#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void test_case()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(min(a, b) > max(c, d) || min(c, d) > max(a, b))
        cout << "NO";
    else
        cout << "YES";
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}