#include <bits/stdc++.h>

using namespace std;

void tc()
{
    int n; string s;
    cin >> n >> s;
    // shortest go greedy up, longest go greedy down
    // we go through the string in cycles of ups and downs, so one process involves one up subarray and one down subarray
    vector<int> shortest(n), longest(n);
    int lastindex = -1;
    while(lastindex != n)
    {
        char one = s[lastindex + 1];
        int prev = lastindex + 1;
        for(int i = lastindex + 1; i < n; ++i)
        {
            if(cur != s[i])
            {
                lastindex = i - 1;
                break;
            }
            else if(cur == s[i] && i == n - 1)
                lastindex = i;
        }
        prev = lastindex;
        for(int i = prev + 1; i < n; ++i)
        {

        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}
