#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<string> input(4);
    for(int i = 0; i < 4; ++i)
        cin >> input[i];
    vector<string> check = {"H", "2B", "3B", "HR"};
    vector<bool> used(4, 0);
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            if(input[i] == check[j])
                used[j] = 1;
        }
    }
    bool ans = 1;
    for(int i = 0; i < 4; ++i)
        if(!used[i])
            ans = 0;
    if(ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}