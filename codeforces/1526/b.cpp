#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> possible(111 * 11 - 111 - 11 + 1, -1);
bool dp(int a)
{
    if(possible[a] != -1)
        return possible[a];
    possible[a] = 0;
    if(!(a % 11) || !(a % 111) || (a > 11 && dp(a - 11)) || (a > 111 && dp(a - 111)))
        possible[a] = 1;
    return possible[a];
}

void test_case()
{
    int x;
    cin >> x;
    // chicken mcnugget theorem -> g(a, b) = a * b - a - b
    // we need to do dp for 1 to 1100
    if(x >= possible.size() || dp(x))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    dp(111 * 11 - 111 - 11);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}