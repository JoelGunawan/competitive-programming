#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    const double tax = 1.08;
    const int target = 206;
    if((int)(n * tax) == target)
        cout << "so-so";
    else if((int)(n * tax) < target)
        cout << "Yay!";
    else
        cout << ":(";
    return 0;
}