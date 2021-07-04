#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
void test_case()
{
    int n;
    cin >> n;
    int odd = 0, even = 0;
    for(int i = 0; i < 2 * n; ++i)
    {
        int in;
        cin >> in;
        if(in & 1)
            ++odd;
        else
            ++even;
    }
    if(even == odd)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}