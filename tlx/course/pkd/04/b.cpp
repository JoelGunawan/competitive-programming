#include <bits/stdc++.h>
using namespace std;
vector<int> target, current;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        // each team has n - 1 matches, which means there are n * n - 1 / 2 matches
        target = vector<int>(n, 0), current = target;
        for(int i = 0; i < n; ++i)
            cin >> target[i];
        // do a full brute force of all matches and find whether it is true or not
        
    }
    return 0;
}