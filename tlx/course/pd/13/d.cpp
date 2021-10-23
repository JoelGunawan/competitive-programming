#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> cur;
void brute_force(int length, int prev)
{
    if(length == k)
    {
        // output array
        for(int i = 0; i < length; ++i)
            cout << cur[i] << " ";
        cout << endl;
    }
    else
    {
        for(int i = prev + 1; i <= n; ++i)
        {
            cur.push_back(i);
            brute_force(length + 1, i);
            cur.pop_back();
        }
    }
}
int main()
{
    cin >> n >> k;
    brute_force(0, 0);
    return 0;
}